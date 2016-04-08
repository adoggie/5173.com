#pragma once

#include <windows.h>

bool decrypt ( const char *key, const char* data, char *des, int &desSize );
//int MyBase64EncodeGetRequiredLength( int srcSize );
//BOOL MyBase64Encode( const BYTE *pbSrcData,int nSrcLen,LPSTR szDest,int *pnDestLen);
