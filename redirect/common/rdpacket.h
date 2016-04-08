
#ifndef _RD_PACKET_H
#define _RD_PACKET_H

#include "base.h"
#include "socket.h"


struct ConnectionMessageBase;

class MessageQueue:swlib::BaseObject{
public:

	MessageQueue(swUInt32 bufsize=1024*10);
	void reset();
	void queueIn(char* data,size_t size);
	bool getMessage(shared_ptr<ConnectionMessageBase>& msgout);
	swByteArray& getBuffer(){	return _buffer;}
private:
	swByteArray	_buffer;
};


#endif