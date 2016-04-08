#include "rdchannel.h"

//////////////////////////////////////////////////////////////////////////
swByteArray ConnectionMessageBase::final(){
	swByteArray packet;
	swByteArray data;
	packet.resize(4+size());
	data = encode();
	swStreamOut sout(&packet[0],packet.size());
	swUInt32 len;
	len = size();
	sout.serial(len).serialBytes(&data[0],data.size());

	return packet;
}

bool ConnectionMessageBase::decode(swByteStream& stream){
	if( stream.leftBytes() < 2){
		return false;
	}
	stream.readValue(cnmid);
	return true;
}

swUInt32	ConnectionMessageBase::size(){
	swUInt32 r=2;
	return r;
}

swByteArray ConnectionMessageBase::encode(){
	swByteArray bytes;
	bytes.resize(ConnectionMessageBase::size());
	memcpy(&bytes[0],&cnmid,ConnectionMessageBase::size());
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//

 

bool CNM_Helo_t::decode(swByteStream& stream){
	if(!ConnectionMessageBase::decode(stream)){
		return false;
	}
	if(!decodeShortString(stream,helo)){
		return false;
	}
	return true;
}

swUInt32	CNM_Helo_t::size(){
	swUInt32 r= helo.size()+1;
	return r+ConnectionMessageBase::size();
}

swByteArray CNM_Helo_t::encode(){
	swByteArray bytes;
	swByteArray parent = ConnectionMessageBase::encode();
	bytes.resize(size());
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serialShortString(helo);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//
 
bool CNM_Auth_t::decode(swByteStream& stream){
	if( stream.leftBytes()<size()){
		return false;
	}
	ConnectionMessageBase::decode(stream);
	memcpy(secureKey,stream.current(),16);
	stream.forward(16);
	memcpy(&requester,stream.current(),1);
	return true;
}

swUInt32	CNM_Auth_t::size(){
	return ConnectionMessageBase::size()+17;
}

swByteArray CNM_Auth_t::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size()).serialBytes(secureKey,16).serial(requester);
	return bytes;
}

//////////////////////////////////////////////////////////////////////////
 
bool CNM_RdServer_EchoIPResp_t::decode(swByteStream& stream){
	if(!ConnectionMessageBase::decode(stream)){
		return false;
	}
	if(stream.leftBytes()<4){
		return false;
	}
	stream.readValue(ip);
	return true;
}

swUInt32	CNM_RdServer_EchoIPResp_t::size(){
	return ConnectionMessageBase::size()+4;
}

swByteArray CNM_RdServer_EchoIPResp_t::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size()).serial(ip);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
 
//在dispacther端解析，无须处理
bool CNM_RdServer_Status_t::decode(swByteStream& stream){
	if(!ConnectionMessageBase::decode(stream)){
		return false;
	}
	return true;
}

swUInt32	CNM_RdServer_Status_t::size(){
	return ConnectionMessageBase::size()+16+1+mac.size()+1+hostname.size()+1+vendor.size();
}

swByteArray CNM_RdServer_Status_t::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serial(tick).serial(conNum).serial(ipaddr).serial(port).serial(rptInterval);
	sout.serialShortString(mac).serialShortString(hostname).serialShortString(vendor);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
 

bool CNM_RdServer_Set_t::decode(swByteStream& stream){
	if(stream.leftBytes()<size()){
		return false;
	}
	ConnectionMessageBase::decode(stream);
	stream.readValue(mask);
	stream.readValue(rptInterval);

	return true;
}

swUInt32	CNM_RdServer_Set_t::size(){
	return ConnectionMessageBase::size()+6;
}

swByteArray CNM_RdServer_Set_t::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serial(mask).serial(rptInterval);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////

 

bool CNM_SystemQueryResult::decode(swByteStream& stream){
	if( stream.leftBytes()<size()){
		return false;
	}
	ConnectionMessageBase::decode(stream);
	stream.readValue(ver);
	stream.readValue(tick);
	return true;
}
swUInt32	CNM_SystemQueryResult::size(){
	return 8+ConnectionMessageBase::size();
}

swByteArray CNM_SystemQueryResult::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size()).serial(ver).serial(tick);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
 
bool CNM_SystemUpdate::decode(swByteStream& stream){
	if(!ConnectionMessageBase::decode(stream)){
		return false;
	}
	swUInt32 len;
	if(stream.leftBytes()<4){
		return false;
	}
	stream.readValue(len);
	if(stream.leftBytes()<len){
		return false;
	}
	medias.resize(len);
	memcpy(&medias[0],stream.current(),len);
	return true;
}

swUInt32	CNM_SystemUpdate::size(){
	return ConnectionMessageBase::size() + 4+medias.size();
}

swByteArray CNM_SystemUpdate::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serialByteArray(medias);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//
 
bool ChannelMessageBase::decode(swByteStream& stream){
	if( stream.leftBytes()<size()){
		return false;
	}
	ConnectionMessageBase::decode(stream);

	stream.readValue(cmid);
	stream.readValue(cid);

	return true;
}

swUInt32	ChannelMessageBase::size(){
	return ConnectionMessageBase::size() + 6;
}

swByteArray ChannelMessageBase::encode(){
	swByteArray bytes;
	bytes.resize(ChannelMessageBase::size());
	swByteArray parent;
	parent = ConnectionMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serial(cmid).serial(cid);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//
 
bool CM_ConnectOpen_t::decode(swByteStream& stream){
	if(stream.leftBytes()<size()){
		return false;
	}
	ChannelMessageBase::decode(stream);

	stream.readValue(addr);
	stream.readValue(port);
	stream.readValue(timeout);
	return true;
}

swUInt32	CM_ConnectOpen_t::size(){
	return ChannelMessageBase::size()+8;
}

swByteArray CM_ConnectOpen_t::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ChannelMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serial(addr).serial(port).serial(timeout);
	return bytes;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//
 
bool CM_ChannelData::decode(swByteStream& stream){
	if(!ChannelMessageBase::decode(stream)){
		return false;
	}
	if( !decodeByteArray(stream,data)){
		return false;
	}
	return true;
}

swUInt32	CM_ChannelData::size(){
	return ChannelMessageBase::size()+data.size()+4;
}

swByteArray CM_ChannelData::encode(){
	swByteArray bytes;
	bytes.resize(size());
	swByteArray parent;
	parent = ChannelMessageBase::encode();
	swStreamOut sout(&bytes[0],bytes.size());
	sout.serialBytes(&parent[0],parent.size());
	sout.serialByteArray(data);
	return bytes;	
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//