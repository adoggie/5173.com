#include "Crypt.h"
#include "DES.h"
//#include "base64.h"
#include <atlenc.h>

bool decrypt ( const char *key, const char* data, char *des, int &desSize)
{
	//base64Ω‚¬Î
	int srcSize = strlen(data);
	int nDestLen = Base64DecodeGetRequiredLength(srcSize);
	Base64Decode(data, srcSize,(BYTE*)des, &nDestLen);
	des[nDestLen] = 0;

	unsigned char ckey[8] = {0};
	memcpy( ckey, key, min(strlen(key),sizeof(ckey)) );

	//DESΩ‚√‹
	DES Des ;
	Des.decrypt(ckey,(unsigned char*)des,nDestLen/8);
	desSize = strlen(des);
	return true;
};

//int MyBase64EncodeGetRequiredLength( int srcSize )
//{
//	return	BASE64_LENGTH(srcSize);
//}
//BOOL MyBase64Encode( const BYTE *pbSrcData,int nSrcLen,LPSTR szDest,int *pnDestLen)
//{
//	base64_encode( (char*)pbSrcData, nSrcLen, (char*)szDest, *pnDestLen );
//	return TRUE;
//}