#ifndef _THREAD_H
#define _THREAD_H

#include <windows.h>

#include "async.h"

namespace swlib{

class Thread{
public:
	Thread(){
		_entry = NULL;        
     _user = NULL;
		 _end = true;
		 _loop = false;				
	}

	Thread( void(*entry)(Thread* ,void*),void* user){        
		_entry = entry;        
    _user = user;
    _end = true;
		_loop = false;
		_cond.set(true);
  }
  
	bool start(){
		_thandle = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Thread::_run,(void*)this,NULL,&_tid);
		return true;    	
	}
    
	void    stop(){
		_loop = false;
	}

	void    wait(){
		_cond.wait();
	/*
		while(!_end){
			Sleep(20);
     }
     Sleep(20);  // ensure that thread has terminated
		 */
	}
  
	void    stopAndWait(){
		stop();wait();
	}
    
  bool    loop(){
		return _loop;
	}
  
	void    code_begin(){
		_cond.set(false);
		_loop = true; _begin = true;_end=false;
	}
  
	void    code_end(){
		_loop = false; _begin = false;_end=true;
    CloseHandle(_thandle);
		_cond.set(true);
	}

	void setUser(void * user){
		_user = user;
	}
	
	void* getUser(){
		return _user;
	}
	
	void setEntry(void(*entry)(Thread* ,void*)){
		_entry = entry;
	}
protected:
  static void    _run(Thread* thread){
		thread->code_begin();
		thread->run();		
		thread->code_end();
	}

	virtual void run(){	
		_entry(this,_user);
	}

private:
	volatile bool    _loop,_begin,_end;
  void (*_entry)(Thread* ,void*);
  void*    _user;
  DWORD    _tid;
  HANDLE    _thandle;
	Condition	_cond;
}; 

//////////////////////////////////////////////////////////////////////////
}

#endif

