#ifndef _RD_STREAM_H
#define _RD_STREAM_H
#include "base.h"
class swByteStream{
public:
	//度流到达尾部
	class ExceptionReadError:public std::exception{
		const char *  what() const{
			return "reached stream end";
		}
	};
	swByteStream(bool bigedian= true);
	swByteStream(swByte* start,swUInt32 size,bool bigedian= true);
	void operator =(const swByteStream& stream);
	swByte*		begin();
	swByte*		forward(swUInt32 n);	//前进n字节，返回当前位置,过界返回NULL 
	swByte*		back(swUInt32 n);			//回退n字节,过界则返回起始地址
	swByte*		rewind();							//重新绕回开始位置
	swUInt32	size();
	void			reset();
	void			setCurrent(swByte*);
	swByte*		current();
	bool			isEOF(); //是否到达尾部
	swUInt32	leftBytes(); //甚于字节数
	bool			readValue(swUInt32& val,bool forward=true); //读取值之后往前进
	bool			readValue(swUInt16& val,bool forward=true);
	bool			readValue(swUInt8& val,bool forward=true);
	bool			readValue(swFloat& val,bool forward=true);
	bool			readValue(swDouble& val,bool forward=true);
// 	bool			readValue(swGeoRect&val,bool forward=true);
// 	bool			readValue(swGeoPoint&val,bool forward=true);
// 	bool			readValue(swGeoSize&val,bool forward=true);
// 	bool			readString(swString& val,bool forward=true); //读1字节的短字符串(0~255),对应string_desc_t类型
	bool			readString(std::string& val,bool forward=true); //(用于存储utf-8)读1字节的短字符串(0~255),对应string_desc_t类型
// 	bool			readValue(swGeoPoint* pts,swUInt32 num,bool forward= true);
// 	bool			readValue(swGeoPoint** pts,swUInt32 num,bool forward= true);
private:
	swByte*		_ptr;
	swUInt32	_size;
	swByte*		_curr;
	bool			_be; //是否按网络字节读取
};


#define SW_INLINE inline

//////////////////////////////////////////////////////////////////////////
#define swN2H16(x)	x //((swUInt16)ntohs(u_short(x)))
#define swN2H32(x) x //((swUInt32)ntohl(u_long(x)))
//////////////////////////////////////////////////////////////////////////
SW_INLINE
swByteStream::swByteStream(bool bigedian /*= true*/){
	_be = bigedian;
	_ptr =NULL;
	_curr = NULL;
	_size = 0;
}
SW_INLINE
swByteStream::swByteStream(swByte* start,swUInt32 size,bool bigedian /*= true*/){
	_size = size;
	_be = bigedian;
	_ptr = _curr = start;
}
SW_INLINE
swByte*		swByteStream::begin(){
	return _ptr;
}

/*
forward()
越界返回NULL
*/
SW_INLINE
swByte*		swByteStream::forward(swUInt32 n){
	// 	if( _curr-_ptr+n > _size ){
	// 		return NULL;
	// 	}
	_curr+=n;
	return _curr;
}

/*
back()
越界返回首部地址
*/
SW_INLINE
swByte*		swByteStream::back(swUInt32 n){
	if( _curr-n <_ptr){
		return _ptr;
	}
	_curr-=n;
	return _curr;
}

/*
rewind()
重新绕回开始位置
*/
SW_INLINE
swByte*		swByteStream::rewind(){ //

	return _curr = _ptr;
}
SW_INLINE	
swUInt32	swByteStream::size(){
	return _size;
}
SW_INLINE
void			swByteStream::reset(){
	_ptr = _curr = NULL;
	_size = 0;
}
SW_INLINE	
void			swByteStream::setCurrent(swByte* cr){
	_curr = cr;
}
SW_INLINE	
swByte*		swByteStream::current(){
	return _curr;
}
SW_INLINE
bool			swByteStream::isEOF(){
	if( swUInt32(_curr-_ptr) >= _size){
		return true;
	}
	return false;
}
SW_INLINE
swUInt32	swByteStream::leftBytes(){
	return _size - (_curr - _ptr);
}
SW_INLINE
bool			swByteStream::readValue(swUInt32& val,bool f){
#ifdef SW_BYTES_ALIGN 
	memcpy(&val,_curr,4);
#else
	val = (swUInt32)swN2H32(*(swUInt32*)_curr);
#endif
	if(f){
		forward(4);
	}
	return true;
}
SW_INLINE
bool			swByteStream::readValue(swUInt16& val,bool f){
#ifdef SW_BYTES_ALIGN 
	memcpy(&val,_curr,2);
#else
	val = (swUInt16)swN2H16(*(swUInt16*)_curr);
#endif
	if(f){
		forward(2);
	}
	return true;
}
SW_INLINE
bool			swByteStream::readValue(swUInt8& val,bool f){
	//val = *(swUInt8*)_curr;
	memcpy(&val,_curr,1); // 2009.8.24
	if(f){
		forward(1);
	}
	return true;
}
SW_INLINE
bool			swByteStream::readValue(swFloat& val,bool f){
	swUInt32 u32v;
	readValue(u32v,f);
	//val =(swFloat)u32v;
	memcpy(&val,&u32v,4);
	return true;
}
SW_INLINE
bool			swByteStream::readValue(swDouble& val,bool f){
	return false;
}

SW_INLINE
bool			swByteStream::readString(std::string& val,bool f){
	swUInt8 len;
	readValue(len,f);
	if(len){
		val.append((char*)_curr,len);
		forward(len);
	}
	return true;
}

SW_INLINE
void swByteStream::operator =(const swByteStream& stream){
	reset();
	_ptr = stream._ptr;
	_size = stream._size;
	_curr = stream._curr;
	_be = stream._be;
}	 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//必须检测size,防止写溢出
class swStreamOut{
public:
	swStreamOut( swByte* data,size_t size){
		_ptr = _curr = data;
		_size = size;
	}

	swStreamOut& serial (const swUInt8& i8,bool f=true){
		if(_curr+1>_ptr+_size){
			return *this;  // Nop 
		}
		memcpy(_curr,&i8,1);
		if(f){
			_curr+=1;
		}
		return *this;
	}

	swStreamOut& serial(const swUInt16 i16,bool f=true){
		if(_curr+2>_ptr+_size){
			return *this;  // Nop 
		}
		memcpy(_curr,&i16,2);
		if(f){
			_curr+=2;
		}
		return *this;
	}
	swStreamOut& serial(const swUInt32 i32,bool f=true){
		if(_curr+4 >_ptr+_size){
			return *this;  // Nop 
		}
		memcpy(_curr,&i32,4);
		if(f){
			_curr+=4;
		}
		return *this;
	}

	swStreamOut& serialBytes(const swByte* bytes,size_t size,bool f=true){
		if(_curr+size > _ptr+_size){
			return *this;  // Nop 
		}
		memcpy(_curr,bytes,size);
		if(f){
			_curr+=size;
		}
		return *this;
	}

	// 4+body
	swStreamOut& serialByteArray(const swByteArray& bytes,bool f=true){
		if(_curr+ bytes.size() + 4 > _ptr+_size){
			return *this;  // Nop 
		}
		swUInt32 len;
		len = bytes.size(); 
		memcpy(_curr,&len,4);
		_curr+=4;
		memcpy(_curr,&bytes[0],len);
		if(f){
			_curr+=len;
		}else{
			_curr-=4;
		}
		return *this;
	}

	swStreamOut& serialShortString(const std::string& s,bool f=true){
		swUInt8 len;
		len = (swUInt8)s.size();
		if(_curr+ len +1 > _ptr+_size){
			return *this;  // Nop 
		}		
		memcpy(_curr++,&len,1);		
		memcpy(_curr,s.c_str(),len);
		if(f){
			_curr+=len;
		}else{
			_curr--;
		}		
		return *this;
	}

	swStreamOut& serialString(const std::string& s,bool f=true){
		swUInt32 len;
		len = (swUInt32)s.size();
		if(_curr+ len +4 > _ptr+_size){
			return *this;  // Nop 
		}		
		memcpy(_curr,&len,4);	
		_curr+=4;
		memcpy(_curr,s.c_str(),len);
		if(f){
			_curr+=len;
		}else{
			_curr-=4; // back to origin
		}		
		return *this;
	}

	size_t size(){
		return _size;
	}
	swByte* begin(){
		return _ptr;
	}
	swByte* current(){
		return _curr;
	}
	
	size_t leftBytes(){
		return _size - (_curr - _ptr);
	}

	swByte* forward(swUInt32 n){
		_curr+=n;
		return	_curr;
	}

	swByte* back(swUInt32 n){
		_curr-=n;
		return _curr;
	}
	//////////////////////////////////////////////////////////////////////////
	swByte* _ptr;
	swByte* _curr;
	size_t  _size;
};

#endif
