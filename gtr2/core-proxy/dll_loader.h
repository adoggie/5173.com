
#ifndef _DLL_H
#define _DLL_H

#include "base.h"

#ifdef _UNIX
	#include <unistd.h>
	#include <signal.h>
	#include <sys/socket.h>
	#include <dlfcn.h>
	#define getsymaddr	dlsym
	typedef void	*	HMODULE;
#endif

#ifdef  WIN32
	#include <windows.h>
	#define getsymaddr	GetProcAddress
#endif


namespace swlib{

class Dll_Loader{
#ifdef _UNICODE
	typedef std::wstring  STRING;
#else
	typedef std::string		STRING;
#endif
public:
	bool 	load(const TCHAR * dll);
	void *	loadSymbol(const char *proc);
	void	free();	
	HMODULE getModule();
	Dll_Loader::STRING & 	getFileName();
private:	
	HMODULE				libmodule;	
	STRING  filename;
};


inline 
Dll_Loader::STRING &Dll_Loader::getFileName(){
	return filename;
}
inline
HMODULE Dll_Loader::getModule(){
	return libmodule;
}

inline 
bool 	Dll_Loader::load(const TCHAR * dll){
	filename = dll;
	#ifdef _UNIX		
		libmodule = dlopen(dll,RTLD_NOW);
	#endif
	#ifdef _WIN32
		libmodule = LoadLibrary(dll);
	#endif
	if( !libmodule){
		return false;
	}
	return true;
}

inline 
void *	Dll_Loader::loadSymbol(const char *proc){
	return getsymaddr(libmodule,(LPCSTR)proc);
}

inline 
void	Dll_Loader::free(){
	#ifdef _UNIX		
		dlclose(libmodule);
	#endif
	#ifdef _WIN32
		FreeLibrary(libmodule);
	#endif	
}


}

#endif
