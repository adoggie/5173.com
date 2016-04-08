#include "rdpacket.h"
#include "rdchannel.h"
#include "stream.h"

MessageQueue::MessageQueue(swUInt32 bufsiz){
	_buffer.reserve(bufsiz);
}

void MessageQueue::reset(){
	swlib::ScopeLocker l(_mtx);
	_buffer.clear();
}

void MessageQueue::queueIn(char* data,size_t size){
	swlib::ScopeLocker l(_mtx);
	size_t oldsize;
	oldsize = _buffer.size();
//	_buffer.insert(_buffer.begin(),_buffer[])
	swByteArray tmpbytes;
	tmpbytes.resize(_buffer.size()+size);
	if(_buffer.size()){
		memcpy(&tmpbytes[0],&_buffer[0],_buffer.size());
	}
	memcpy(&tmpbytes[oldsize],data,size);
	_buffer = tmpbytes;
	//_buffer.resize(_buffer.size()+size);
	
}
//每个包都有4字节的长度描述
bool MessageQueue::getMessage(shared_ptr<ConnectionMessageBase>& msg){
	swlib::ScopeLocker l(_mtx);
	if(_buffer.size()< 4){
		return true; // msg is smaller
	}
	swByteStream stream(&_buffer[0],_buffer.size());
	swUInt32 size;
	stream.readValue(size);
	if(size > stream.leftBytes()){
		return true; // also too smaller
	}
	swUInt16 msgid;
	stream.readValue(msgid);
	switch(msgid){
		case CNM_HELO:
			msg = shared_ptr<ConnectionMessageBase>(new CNM_Helo_t);
			break;
		case CNM_AUTH:
			msg = shared_ptr<ConnectionMessageBase>(new CNM_Auth_t);
			break;
		case CNM_ACCEPT:
		case CNM_REJECT:
		case CNM_HEARTBEAT:
			msg = shared_ptr<ConnectionMessageBase>(new ConnectionMessageBase(msgid));
			break;
		case CNM_CHANNEL:
			stream.readValue(msgid);
			switch(msgid){
				case CM_CONNECT_OPEN:
					msg = shared_ptr<ConnectionMessageBase>(new CM_ConnectOpen_t);
				break;
				case CM_CONNECT_CLOSE:
				case CM_CONNECT_HALFCLOSE:
				case CM_CONNECT_REJECT:
				case CM_CONNECT_ACCEPT:
					msg = shared_ptr<ConnectionMessageBase>(new ChannelMessageBase(msgid));
					break;
				case CM_STREAM_DATA:
					msg = shared_ptr<ConnectionMessageBase>(new CM_StreamData);
					break;
				case CM_DGRAM_DATA:
					msg = shared_ptr<ConnectionMessageBase>(new CM_DgramData);
					break;
				default:
					return false;
			}
			break;
		case CNM_ECHOIP_RESP:
			msg = new CNM_RdServer_EchoIPResp_t;
			break;
		case CNM_RDSERVER_SET:
			msg = new CNM_RdServer_Set_t;
			break;
		default:
			return false;	 //非法数据包
	}
	stream =swByteStream(&_buffer[0]+4,_buffer.size()-4);
	if( !msg->decode(stream)){
		return false;		
	}
	_buffer.erase(_buffer.begin(),_buffer.begin()+msg->size()+4); // skip to next paket
	return true;
}
