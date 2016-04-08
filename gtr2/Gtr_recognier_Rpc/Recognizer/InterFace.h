/*{*******************************************************}
{                                                       }
{       �ܱ���ʶ��ӿ�                                  }
{                                                       }
{       ��Ȩ���� (C) 2010 5173                          }
{       ������:jijianhua 20100520                     }
{*******************************************************}*/
#ifndef __INTERFACE__
#define __INTERFACE__
#include <windows.h>
#define def_dllname "AutoRecognizer.dll"
#define GB_PROCESS_ERROR(Condition)    if (!(Condition))   goto Exit0;
#pragma   pack(1)   



//��Ϸ����Ŀ¼

typedef struct _PicBuffInfo
{
	char* cPicBuff;               //ͼƬBuff
	DWORD dwPicBuffLen;           //ͼƬ���ݳ���
}TPicBuffInfo,*PPicBuffInfo;
  
//
typedef struct _GetCardDataByCoordinate
{
    PPicBuffInfo PicInfo;           
	char* cCoordinateBuff;        //���к�Buff
	DWORD dwCoordinateBuffLen;    //���кų���
	char* cRelBuff;               //���ؽ��Buff
	int iType;                    //��������  QQϵ�� ��1 
	int iRel;                     //���������
}TGetCardDataByCoordinate,*PGetCardDataByCoordinate;

//
typedef struct _GetCoordinateTable
{
    PPicBuffInfo PicInfo;  
	char* cRelBuff;               //���ؽ��Buff
	DWORD dwRelBuffLen;           //��ȷ�����Ӧ���ص��ַ�����
	int iType;                    //��������  QQϵ�� ��1 
	int iRel;                     //���������
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
	char* cPicBuff;               //ͼƬBuff
	DWORD dwPicBuffLen;           //ͼƬ���ݳ���
}TGetLinePic,*PGetLinePic;


typedef BOOL (__stdcall *AutoInit)();                               //��ʼ������
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