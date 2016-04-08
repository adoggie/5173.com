
#ifndef _BT_MUTEX_H
#define _BT_MUTEX_H
#include <windows.h>

namespace swlib{
	
class Mutex{
public:
	Mutex(){
		InitializeCriticalSection(&cs);
	}
	~Mutex(){
		DeleteCriticalSection(&cs);
	}
	void lock(){
		EnterCriticalSection(&cs);
	}
	void unlock(){
		LeaveCriticalSection(&cs);
	}
private:
	CRITICAL_SECTION	cs;  
};

typedef Mutex Locker;

class ScopeLocker{
public:
	ScopeLocker(Locker&	l):_l(l){
		_l.lock();
	}
	~ScopeLocker(){
		_l.unlock();
	}
private:
	Locker&	_l;
};

}

#endif
