
#ifndef _UTIL_H
#define _UTIL_H

#include "base.h"

#include <wx/wx.h>
#include <wx/listctrl.h>



namespace swlib{
//	namespace Util{
		int str2int(const std::string  s);
		float str2float(const std::string& s);
		std::string		str_upper(const std::string s);
		std::string		str_lower(const std::string  s);
		void	mapstr_lower(std::map<std::string,std::string>&  mapstr);
		void	mapstr_upper(std::map<std::string,std::string>&  mapstr);
		std::string  int2str( int i);	
		std::string  float2str(float f);
		std::string strip(const std::string s);
		std::string double2str(double v);
		std::string bytes2hexstr(unsigned char* data,swUInt32 size);
		void char2hex(unsigned char ch,unsigned char *hexbuff);
		
		bool mkdir(const std::string& path);
		std::string formatTimeStamp(time_t time);


//	}	
}
#endif

