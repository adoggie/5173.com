#ifndef _PACKAGE_H_
#define _PACKAGE_H_
#include <string>
typedef enum tagPkgMessageType{
	MSG_NORMAL = 0,
	MSG_HEART  = 1,
	MSG_ALERT  = 2
} PKG_MSG_TYPE, *LPPKG_MSG_TYPE;

typedef struct tagBusinessPkg{
std::string strOrderId;
std::string strGameId;
std::string strDetail;
std::string strIP;
}BUSINESS_PKG, *LPBUSINESS_PKG;


#endif