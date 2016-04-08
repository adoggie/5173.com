
#include "stdafx.h"
#include "rdserver_ldr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include  <io.h>

bool	sameInstance(const std::string& name){
	HANDLE hMutex = CreateMutex(NULL, false, name.c_str());
	if (GetLastError() == ERROR_ALREADY_EXISTS){
		CloseHandle(hMutex);
		return true;
	}	
	return false;
}

/*
bool	NetStore_AppBase::processShot(const std::string& name){
	FILE* pfile;
	std::string filename;
	filename = wxString::Format(wxT("%s.pid"),wxString::FromUTF8(name.c_str())).ToUTF8().data();
	pfile = fopen(filename.c_str(),"w");
	if( !pfile){
		return false;
	}
	swUInt32 pid = wxGetProcessId();
	char buff[32];
	sprintf(buff,"%u",pid);
	fwrite(buff,strlen(buff),1,pfile);
	fclose(pfile);
	return true;
}						 */


void  killProcess(const std::string& pidfile){
	std::string processfile =pidfile;
	FILE * pfile;
	pfile = fopen(processfile.c_str(),"r");
	char buff[32];
	if( pfile){		
		fgets(buff,sizeof(buff),pfile);
		fclose(pfile);
		unsigned int  pid = (unsigned int) atoi(buff);
		HANDLE hproc = OpenProcess(PROCESS_TERMINATE,0,pid);
		if( hproc){
			TerminateProcess( hproc,0);
			CloseHandle(hproc);
		}
	}	
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	int argc = __argc;
	/*
	 .exe        启动，运行rdserver.exe
	 .exe update 更新并重新启动
		rdserveru.exe存在则删除rdserver.exe,更名rdserveru.exe->rdserver.exe, 
		load rdserver.exe
	*/
	killProcess("rdserver.pid");
	Sleep(1000*3);
	if( _access("rdserveru.exe",04) ==0){ //can be read
		_unlink("rdserver.exe");
		rename("rdserveru.exe","rdserver.exe");
	}
	//////////////////////////////////////////////////////////////////////////
	STARTUPINFO si; 
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb =sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;
	PROCESS_INFORMATION pi; 
	CreateProcess(NULL,"rdserver.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
	//////////////////////////////////////////////////////////////////////////
	return (int) 0;
}
