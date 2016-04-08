/*{*******************************************************}
{                                                       }
{       密保卡识别接口                                  }
{                                                       }
{       版权所有 (C) 2010 5173                          }
{       最后更新:jijianhua 20100520                     }
{*******************************************************}*/
#ifndef __INTERFACE__
#define __INTERFACE__
#include <windows.h>
#define def_dllname "AutoRecognizer.dll"
#define GB_PROCESS_ERROR(Condition)    if (!(Condition))   goto Exit0;
#pragma   pack(1)   



//游戏所在目录

typedef struct _PicBuffInfo
{
	char* cPicBuff;               //图片Buff
	DWORD dwPicBuffLen;           //图片数据长度
}TPicBuffInfo,*PPicBuffInfo;
  
//
typedef struct _GetCardDataByCoordinate
{
    PPicBuffInfo PicInfo;           
	char* cCoordinateBuff;        //序列号Buff
	DWORD dwCoordinateBuffLen;    //序列号长度
	char* cRelBuff;               //返回结果Buff
	int iType;                    //处理类型  QQ系列 填1 
	int iRel;                     //处理错误码
}TGetCardDataByCoordinate,*PGetCardDataByCoordinate;

//
typedef struct _GetCoordinateTable
{
    PPicBuffInfo PicInfo;  
	char* cRelBuff;               //返回结果Buff
	DWORD dwRelBuffLen;           //正确情况下应返回的字符个数
	int iType;                    //处理类型  QQ系列 填1 
	int iRel;                     //处理错误码
}TGetCoordinateTable,*PGetCoordinateTable;

//
/*
PGetLinePic = ^TGetLinePic;
TGetLinePic = packed record
cPicBuff: PChar;
dwPicBuffLen: DWORD;
end;*/

typedef struct _GetLinePic
{
	char* cPicBuff;               //图片Buff
	DWORD dwPicBuffLen;           //图片数据长度
}TGetLinePic,*PGetLinePic;


typedef BOOL (__stdcall *AutoInit)();                               //初始化函数
//typedef BOOL (__stdcall *AutoUnInit)();                              
typedef HRESULT (__stdcall *AutoGetCardDataByCoordinate)(PGetCardDataByCoordinate pParamInfo); 

typedef HRESULT (__stdcall *AutoGetCoordinateTable)(PGetCoordinateTable pParamInfo); 

typedef PGetLinePic (__stdcall *AutoGetLinePicBuff)(); 






typedef struct _AUTOPICAPI
{
	AutoInit Init;	
	AutoGetCardDataByCoordinate GetCardDataByCoordinate;
	AutoGetCoordinateTable GetCoordinateTable;
	AutoGetLinePicBuff GetLinePicBuff;
	HINSTANCE PlatForm;
}TAUTOPICAPI,*PAUTOPICAPI;

/////////////////////////////////////////////
TAUTOPICAPI g_AUTOPICAPI = {NULL};

BOOL __stdcall Init_AutoRecognizer(char* pcDllPath);
BOOL __stdcall UnInit_AutoRecognizer();


HRESULT __stdcall InitExportFunc(char* pcDllPath)
{
	HRESULT hRel = E_FAIL;
	ZeroMemory(&g_AUTOPICAPI,sizeof(g_AUTOPICAPI));
	if (pcDllPath == NULL)
	{
			g_AUTOPICAPI.PlatForm = ::LoadLibraryA(def_dllname);
	}
	else
	{
			g_AUTOPICAPI.PlatForm = ::LoadLibraryA(pcDllPath);
	}


	GB_PROCESS_ERROR(g_AUTOPICAPI.PlatForm);

	g_AUTOPICAPI.Init = (AutoInit)(GetProcAddress(g_AUTOPICAPI.PlatForm,"Init"));
	GB_PROCESS_ERROR(g_AUTOPICAPI.Init);	

	g_AUTOPICAPI.GetCardDataByCoordinate = (AutoGetCardDataByCoordinate)(GetProcAddress(g_AUTOPICAPI.PlatForm,"GetCardDataByCoordinate"));
	GB_PROCESS_ERROR(g_AUTOPICAPI.GetCardDataByCoordinate);	

	g_AUTOPICAPI.GetCoordinateTable = (AutoGetCoordinateTable)(GetProcAddress(g_AUTOPICAPI.PlatForm,"GetPicCoordinateTable"));
	GB_PROCESS_ERROR(g_AUTOPICAPI.GetCoordinateTable);	

	g_AUTOPICAPI.GetLinePicBuff = (AutoGetLinePicBuff)(GetProcAddress(g_AUTOPICAPI.PlatForm,"GetLinePicBuff"));
	GB_PROCESS_ERROR(g_AUTOPICAPI.GetLinePicBuff);	

	hRel = S_OK;
Exit0:
	return hRel;
}



BOOL __stdcall Init_AutoRecognizer(char* pcDllPath)
{
	BOOL bRel = FALSE;
	GB_PROCESS_ERROR(S_OK == InitExportFunc(pcDllPath));
	bRel = g_AUTOPICAPI.Init();
Exit0:
	return bRel;
}


BOOL __stdcall UnInit_AutoRecognizer()
{
	if (NULL != g_AUTOPICAPI.PlatForm)
	{
		FreeLibrary(g_AUTOPICAPI.PlatForm);
		g_AUTOPICAPI.PlatForm = NULL;
	}
	return TRUE;
}



#endif __INTERFACE__