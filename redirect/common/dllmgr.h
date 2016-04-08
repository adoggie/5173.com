
/**
	多动态库文件管理
	2005.11.16	add "UnloadAll()"
*/
#ifndef _DLLMGR_H
#define _DLLMGR_H

#include "base.h"
#include "dll_loader.h"


namespace swlib{


class Dll_Manager{
public:
	typedef std::vector<Dll_Loader*> Dll_List;
	
	Dll_Manager(){
	}
	
	void	batchLoad(char ** dlls){
		char * file;
		int i=0;
		while( file = dlls[i++]){
			loadDll(file);
		}
	}

	Dll_Loader* 	loadDll(const char * file){
			Dll_Loader * dll = new Dll_Loader;
			if( dll->load(file) ){
				_dll_list.push_back(dll);
				return dll;
			}
			delete dll;							
			return NULL;
	}
	
	Dll_Loader * getDll(const char * file){
		Dll_Loader * dll;
		Dll_List::iterator itr;		
		for( itr = _dll_list.begin();itr!=_dll_list.end();itr++){
			dll = *itr;
			if( dll->getFileName() == file){
				return dll;
			}
		}
		return NULL;
	}
	
	void free(Dll_Loader *dll){
		dll->free();
	}

	void unload_all(){
		Dll_List::iterator itr;
		Dll_Loader * dll;
		for( itr = _dll_list.begin();itr!=_dll_list.end();itr++){
			dll = *itr;
			free(dll);
			delete dll;
		}
	}

	~Dll_Manager(){
		unload_all();
	}	
private:		
	Dll_List	_dll_list;
};


} // END namespace 

#endif
