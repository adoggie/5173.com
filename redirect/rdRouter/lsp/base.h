#ifndef _SW_BASE_H
#define _SW_BASE_H

#pragma warning(disable:4005 )
#pragma warning(disable:4996)
//#include "config.h"

#include <windows.h>


#include <string>
#include <list>
#include <vector>
#include <map>

//#include <boost/shared_ptr.hpp>
//using namespace boost;

//typedef std::string swString;
#include "smartptr.h"
//using namespace boost;

	


typedef int 		swInt32;
typedef float 	swFloat;
typedef float 	swGeoReal;
typedef double 	swDouble;
typedef unsigned int swUInt32;
typedef char 		swChar;
typedef unsigned char 	swByte;
typedef char 		swInt8;
typedef unsigned char 	swUInt8;
typedef short		swInt16;
typedef unsigned short swUInt16;
typedef std::vector<swByte> swByteArray;

typedef int	swBool;
#define swTrue	1
#define swFalse 0
#define swOk		swTrue



#endif