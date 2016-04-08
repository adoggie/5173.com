
#ifndef _SW_BASEOBJ_H
#define _SW_BASEOBJ_H

#include "base.h"
#include "mutex.h"

namespace swlib{


class BaseObject{
public:
	void setData(void* data){
		_data = data;
	}
	void* data(){
		return _data;
	}
	void* data(int key){
		std::map<int,void*>::iterator itr;
		itr = _datadict.find(key);
		if(itr == _datadict.end()){
			return NULL;
		}
		return _datadict[key];
	}
	void setData(int key,void* data){
		_datadict[key] = data;
	}
	Mutex&	mutex(){	return _mtx;}	
protected:
	void *	_data;
	std::map<int,void*> _datadict;
	Mutex		_mtx;
};


}
#endif
