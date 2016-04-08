
#ifndef _CODEC_H
#define _CODEC_H


#include "base.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "md5.h"
#include "base64.h"

namespace swlib {

class Codec{
public:
	static void BuffToHex(const char *ibuff,unsigned int ilen,char * hexbuff);
	/**< 二进制转换成16进制*/
	static int 	HexToBuff(const char *ibuff,unsigned int ilen,char * obuff);
	/**< 16进制转换成二进制数据*/
	//static bool DigestCalc(const char *ibuf,unsigned int ilen,const char * isecret,char * digest/*16 bytes*/);
	static std::vector<unsigned char> Md5Calc(swByte* data,size_t size );
	/**< 计算md5 digest*/
	
	static swByteArray Base64Encode(char * data,size_t size );
	static swByteArray Base64Decode(char* data ,size_t size);
	static std::string BufferToHex(const unsigned char* buff,size_t size);
	
};
inline
std::string Codec::BufferToHex(const unsigned char* buff,size_t size){
	std::string s;
	s.assign(size*2+1,'\0');
	BuffToHex((const char*)buff,size,&s[0]);
	return s;
}

inline
swByteArray Codec::Base64Encode(char * data,size_t size ){
	swByteArray bytes;
	char * outs;
	size_t encsize = base64_encode_alloc(data,size,&outs);
	bytes.resize(encsize);
	memcpy(&bytes[0],outs,encsize);
	free(outs);
	return bytes;
}

inline
swByteArray Codec::Base64Decode(char* data ,size_t size){
	size_t decsize;
	char *outs;swByteArray bytes;
	if( base64_decode_alloc(data,size,&outs,&decsize) ){
		bytes.resize(decsize);
		memcpy(&bytes[0],outs,decsize);
	}
	return bytes;
}

extern "C" void  md5_calc(unsigned char *output,unsigned char *input,unsigned int inlen);
#define MD5_DIGEST_LEN 16
inline 
std::vector<unsigned char> Codec::Md5Calc(swByte* data,size_t size ){
	std::vector<unsigned char> digest;
	digest.resize(MD5_DIGEST_LEN);

	cvs_MD5Context ctx;
	cvs_MD5Init(&ctx);
	cvs_MD5Update(&ctx,data,size);
	cvs_MD5Final((swByte*)&digest[0],&ctx);
	return digest;
}		


//////////////////////////////////////////////////////////////////////////
//字节流转换为16进制字符
inline
void char_hex(unsigned char ch,unsigned char *hexbuff){
	unsigned char v;
	v = ch /16;
	if( v <= 9){
		*hexbuff = v + '0';
	}else{
		*hexbuff = v - 10 + 'A';
	}
	hexbuff++;
	v = ch % 16;
	if( v <= 9){
		*hexbuff = v + '0';
	}else{
		*hexbuff = v - 10 + 'A';
	}
}

inline
void  Codec::BuffToHex(const char *ibuff,unsigned int ilen,char * hexbuff){
	for (unsigned int i=0; i < ilen; i++){
		char_hex(*(unsigned char *)ibuff++,(unsigned char*)(hexbuff+i*2));
	}
}

inline
unsigned char  hex_char(unsigned char * hex){
	unsigned char ch;
	unsigned char val;	
	ch = toupper(*hex);
	if( ch >='0' && ch <= '9'){
		ch =  (ch -'0');
	}else if (ch >='A' && ch <='F'){
		ch = (ch - 'A' + 10);
	}else {
		ch =0;
	}
	val = ch *16;
	
	ch = toupper(*(hex+1));
	if( ch >='0' && ch <= '9'){
		ch =  (ch -'0');
	}else if (ch >='A' && ch <='F'){
		ch = (ch - 'A' + 10);
	}else {
		ch =0;
	}
	val +=ch ;
	return val;
}

inline
int Codec::HexToBuff(const char *ibuff,unsigned int ilen,char * obuff){
	unsigned int len;
	if( ilen %2 ){
		return -1;
	}
	len = ilen / 2;
	for (unsigned int i =0 ; i< len;i++){
		*(unsigned char*)(obuff+i) = hex_char( (unsigned char *)(ibuff + i*2) );
	}
	return 0;
}


} // end namespace

#endif

