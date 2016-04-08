
#ifndef _SMART_HANDLE_H
#define _SMART_HANDLE_H

#include "mutex.h"
#include <assert.h>
//#include <boost/shared_ptr.hpp>
//using namespace boost;
//#define  shared_ptr  boost::shared_ptr

namespace swlib{
//	typedef <T> shared_ptr<T>;
//}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
template <typename T>
class  Shared{
public:
	Shared(T* ptr=0){
		_ptr = ptr;
		_ref = 0;
	}

	virtual ~Shared(){}
	Shared& operator=(const Shared&){
		return *this;
	}

	void __incRef(){
		_mutex.lock();
		assert(_ref >= 0);
		++_ref;
		_mutex.unlock();
	}

	void __decRef(){
		_mutex.lock();
		bool doDelete = false;
		assert(_ref > 0);
		if(--_ref == 0){
			_noDelete = true;
			doDelete = true;
		}
		_mutex.unlock();
 		if(doDelete){
			if(_ptr){
				delete _ptr;
			}
 			delete this;
 		}
	}

	int __getRef() const{
		_mutex.lock();
		int ref = _ref;
		_mutex.unlock();
		return ref;
	}

	T* get() const{
		return _ptr;
	} 

	void set(T* ptr){
		_ptr = ptr;
	}
	

public:
	int _ref;
	Mutex _mutex;
	bool _noDelete;
	T*	_ptr;
};

//////////////////////////////////////////////////////////////////////////
template<typename T>
class HandleBase{
public:
	typedef T element_type;

	T* get() const{
		return _ptr->_ptr;
	}

	T* operator->() const{
		return _ptr->_ptr;
	}

	T& operator*() const{
		return *(_ptr->_ptr);
	}

	operator bool() const{
		return _ptr->_ptr ? true : false;
	}

// 	void swap(HandleBase& other){
// 		std::swap(_ptr, other._ptr);
// 	}

	Shared<T>* _ptr;
private:

};


template<typename T, typename U>
inline bool operator==(const HandleBase<T>& lhs, const HandleBase<U>& rhs){
	T* l = lhs.get();
	U* r = rhs.get();
	if(l && r){
		return *l == *r;
	}else{
		return !l && !r;
	}   
}

template<typename T, typename U>
inline bool operator!=(const HandleBase<T>& lhs, const HandleBase<U>& rhs){
	T* l = lhs.get();
	U* r = rhs.get();
	if(l && r)
	{
		return *l != *r;
	}
	else
	{
		return l || r;
	}   
}

// template<typename T, typename U>
// inline bool operator<(const HandleBase<T>& lhs, const HandleBase<U>& rhs)
// {
// 	T* l = lhs.get();
// 	U* r = rhs.get();
// 	if(l && r)
// 	{
// 		return *l < *r;
// 	}
// 	else
// 	{
// 		return !l && r;
// 	}
// }
//////////////////////////////////////////////////////////////////////////
template<typename T>
class Handle : public HandleBase<T>{
public:
	Handle(T* p=0 ){
		this->_ptr = new Shared<T>(p);

		if(this->_ptr){
			this->_ptr->__incRef();
		}
	}

 	template<typename Y>
 	Handle(const Handle<Y>& r){
 		this->_ptr =(Shared<T>*) r._ptr;
 		if(this->_ptr){
 			this->_ptr->__incRef();
 		}
 	}

	 
// 	Handle(const Handle& r){
// 		this->_ptr =(Shared<T>*) r._ptr;
// 		if(this->_ptr){
// 			this->_ptr->__incRef();
// 		}
// 	}

	Handle(const Handle& r){
		this->_ptr = r._ptr;
		if(this->_ptr){
			this->_ptr->__incRef();
		}
	}

	~Handle(){
		if(this->_ptr){
			this->_ptr->__decRef();
		}
	}

	Handle& operator=(T* p){
		if( this->_ptr){			
			if(this->_ptr->get() == p){
				return *this;
			}
			this->_ptr->__decRef();
		}
		
		this->_ptr = new Shared<T>(p);
		if(this->_ptr){
			this->_ptr->__incRef();
		}
		return *this;
	}

//  	template<typename Y>
//  	Handle& operator=(const Handle<Y>& r){
//  		if(this->_ptr != r._ptr)
//  		{
//  			if(r._ptr){
//  				r._ptr->__incRef();
//  			}
//  			
//  			if(this->_ptr){
//  				this->_ptr->__decRef();
//  			}
//  			this->_ptr = r._ptr;
//  		}
//  		return *this;
//  	}

 	Handle& operator=(const Handle& r){
		if(this->_ptr != r._ptr)
		{
			if(r._ptr){
				r._ptr->__incRef();
			}

			if(this->_ptr){
				this->_ptr->__decRef();
			}
			this->_ptr = r._ptr;
		}
		return *this;
 	}

	
};




//////////////////////////////////////////////////////////////////////////
 
} // namespace swlib
 
 
#define  shared_ptr swlib::Handle


#endif
