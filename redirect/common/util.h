
#ifndef _UTIL_H
#define _UTIL_H

#include "base.h"
#include "mutex.h"
#include "baseobj.h"
#include <time.h>
#include "smartptr.h"

namespace swlib{
//	namespace Util{
		int str2int(const std::string  s);
		float str2float(const std::string& s);
		std::string		str_upper(const std::string s);
		std::string		str_lower(const std::string  s);
		void	mapstr_lower(std::map<std::string,std::string>&  mapstr);
		void	mapstr_upper(std::map<std::string,std::string>&  mapstr);
		std::string  int2str( int i);	
		std::string  float2str(float f);
		std::string strip(const std::string s);
		std::string double2str(double v);
		std::string bytes2hexstr(unsigned char* data,swUInt32 size);
		void char2hex(unsigned char ch,unsigned char *hexbuff);
		
		bool mkdir(const std::string& path);
		std::string formatTimeStamp(time_t time);
		swUInt32 currentTimeTick();
		std::string getHostName();


//	}	
}

//////////////////////////////////////////////////////////////////////////
namespace swlib{
	
class SequenceUInt:public BaseObject{
public:
	SequenceUInt(swUInt32 start=0,swUInt32 end = 0xffffffff,bool cycle= true){
		_cycle =cycle;
		_value = start;
		_max = end;
	}
	swUInt32 next(){
		ScopeLocker l(_mtx);
		return ++_value;
		
	}
	swUInt32 current(){
		return _value;
	}
	
private:
	swUInt32 _value;
	swUInt32 _max;
	bool	_cycle;
};

//////////////////////////////////////////////////////////////////////////
class TimerAction;
struct TimerActionClient{
	void onTimerAction(TimerAction* action);
};

class TimerAction:public BaseObject{
public:
	TimerAction(TimerActionClient* client,swUInt32 interval=5,swUInt32 id=0){ //д╛хо
		_id = id;
		_interval = interval;
		_client = client;
		_currTick = (swUInt32)time(0);
	}
	swUInt32 interval(){	return _interval; }
	void setInterval(swUInt32 intr){ _interval = intr;}
	swUInt32 id(){	return _id;}
	void		setId(swUInt32 id){ _id = id;}
	void update(){
		_currTick = (swUInt32)time(0);
	}
	void exec(){
		if( swUInt32(time(0)) > _currTick ){
			_client->onTimerAction(this);
			update();
		}
	}
protected:
	TimerActionClient* _client;
	swUInt32 _id;
	swUInt32 _interval;
	swUInt32 _currTick;
};
	
	//////////////////////////////////////////////////////////////////////////
template <typename T>
class Singleton{
public:
	static T* instance(){
		static shared_ptr<T> instobj;
		if(!instobj.get()){
			instobj = new T();
		}
		return instobj.get();
	}
};
	
	
	
}
#endif

