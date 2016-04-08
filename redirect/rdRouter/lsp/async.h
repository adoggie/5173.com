
/*
async.h
����ͬ���첽
*/

#ifndef _SW_ASYNC_H
#define _SW_ASYNC_H

#include <windows.h>

/*namespace swlib{*/

	class Condition{
	public:
		Condition(){
			_event = CreateEvent(NULL,TRUE,FALSE,NULL);
	
		}
		void wait(){
			WaitForSingleObject(_event,INFINITE);
		}

		bool wait(unsigned int msec){
			if( WaitForSingleObject(_event,msec) ==WAIT_OBJECT_0){
				return true;
			}
			return false;
		}
		//����Ϊ���ź�
		void set(bool signal= true){
			if( signal){
				SetEvent(_event);				
			}else{
				ResetEvent(_event);
			}
		}
	public:
		HANDLE _event;
	};






/*}*/



#endif
