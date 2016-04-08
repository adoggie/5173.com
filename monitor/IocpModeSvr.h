// IocpModeSvr.h: interface for the CIocpModeSvr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IOCPMODESVR_H__46FFF420_23C3_4356_A88D_AEBDA61EA186__INCLUDED_)
#define AFX_IOCPMODESVR_H__46FFF420_23C3_4356_A88D_AEBDA61EA186__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
// #include <afxtempl.h>
#include <vector>
#include <winsock2.h>
#pragma  comment(lib,"ws2_32.lib")

/** *************************************************************************************
�ļ���:IocpModeSvr.h
����:CIocpModeSvr
��˵��:������һ����ɶ˿�ģ�͵��������������
����ƽ̨:WinNT3.5���ϰ汾��Windows2000
����ӿ�˵��:�������һ���ص�������ַ���ú�����������ԭ��
void _stdcall ProcessRecvData(unsigned long sIP,
SOCKET sClient,
char * pData,
unsigned long DataLength);
�˻ص������������մӿͻ��˷��������ݻ���ĳ�ͻ��˶Ͽ����ӵ�֪ͨ(��ʼ����)
unsigned long sIP : ��ʾ����֪ͨ�Ŀͻ���IP��ַ
SOCKET sClient :���������ںͿͻ���ͨѸ���׽��֣�
������ǶϿ�������Ϣ��
������ʹ�ô˲�������SendMsg��ͻ��˷�������
char * pData : ���β���������
unsigned long DataLength :���β������ݵ����ݳ���
��ʾ�����pData==NULL ����DataLength ���ʾ���ǿͻ��˶Ͽ����ӵ���Ϣ��
�����ҵ��������ɡ�
����ӿ�˵��:
�����ʼ����������һ��Ϊ�ص���ַ(������ȷ��д)���ڶ���Ϊ����˿ں�
��ʼ���ɹ������棬���򷵻ؼ�
bool Init(ProcessRecvData* pProcessRecvData,unsigned long iSvrPort=SVRPORT);

���淴��ʼ�����������ڳ����˳�ʱ���ã������ڳ�����Ҫ������������ʱ����
void UnInit();

�����ڹ��ڷ�����Ϣ������Ľӿ�˵��

1����Ŀ��IP�ͻ��˷������ݣ�
��һ��ΪĿ��ͻ���IP,
�ڶ���Ϊ��������ַ��
������Ϊ����������
�ɹ�"�ύ"�����棬���򷵻ؼ٣�
�ǿ�������Ϊ�ͻ����Ѿ��Ͽ����߸�����û�����ӡ�
bool SendMsg(LPCTSTR TargetIp,char * pData,unsigned long Length);


2����Ŀ���׽��ַ�������
��һ��Ϊ�ͻ����׽���
�ڶ���Ϊ��������ַ
������Ϊ����������
�ɹ�"�ύ"�����棬���򷵻ؼ�
�ǿ�������Ϊ�ͻ����Ѿ��Ͽ�����
��ʾ���˺���Ϊ����Ҫ�����ķ������ݺ��������и�Ч�ʵ����ԡ�
��������������֪ͨ�ص����Եڶ��ε�sClientֱ����д��
��һ���з������ݣ�������ڽ��յ�����ʱ��Ҫ�ش���Ϣ����
ʹ�ô˺���
�ɹ�"�ύ"������,���򷵻ؼ�
bool SendMsg(SOCKET sClient,char * pData,unsigned long Length);


3�����������߿ͻ��˷�������
�������ݵ������Ѿ���ȷ���ߵĿͻ���
��һ��Ϊ��������ַ
�ڶ���Ϊ����������
�ɹ�"�ύ"�����棬���򷵻ؼ�
�󲿷�����¶��᷵���� ^_^
bool SendMsgToAll(char * pData,unsigned long Length);


4�������ĳ��IP��������������߿ͻ��˷�������
��һ��Ϊ�����IP
�ڶ���Ϊ��������ַ,
������Ϊ���������ȣ�
�ɹ�"�ύ"�����棬���򷵻ؼ�
�󲿷�����¶��᷵����
bool SendMsgToOther(LPCTSTR SourceIp,char* pData,unsigned long Length);


5�������ĳ��Socket�õ������������߿ͻ��˷�������
��һ��Ϊ�����Socket
�ڶ���Ϊ��������ַ
������Ϊ����������
�ɹ�"�ύ"�����棬���򷵻ؼ�
�󲿷�����¶��᷵����
bool SendMsgToOther(SOCKET ExceptSocket,char * pData,unsigned long Length);

����������1
1��const char * GetLocalIpAdd()
���ر���Ip��ַ������ֵΪ���ʮ���Ƶ��ַ���
2��unsigned short GetSvrPort()
���ط���ʹ�õ������˿ں�

����������2
1��bool DisConnectClient(LPCTSTR ClientIp);
�жϲ�����ָ����IP�Ŀͻ��˵����ӣ��ɹ������棬���򷵻ؼ١�
2��bool DisConnectClient(SOCKET sClient);
�жϲ�����ָ���Ŀͻ��������ӣ�������ָ����Ҫ�ж����׽ӿڡ�
3��void DisConnectAll();
�ж����пͻ��������ӡ�

��д�ߣ���� qq:5535833
��дʱ�䣺2004��12��20��

�޸ļ�¼��--------------------------------------------------------------------------
1��
--------------------------------------------------------------------------
2��
--------------------------------------------------------------------------

 ************************************************************************************** */

// ����˿�
#define SVRPORT 10012
// ��������С
#define BUFFER_SIZE 8192
// ��������
#define RECV_POSTED 0
// ��������
#define SEND_POSTED 1

// ���������
typedef struct _PER_HANDLE_DATA {
	unsigned long IpAddr;
	SOCKET sClient;
}PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

// IO��������
typedef struct _PER_IO_OPERATION_DATA {
	// �ص��ṹ
	OVERLAPPED OverLapped;
	// ���ݻ�����
	WSABUF RecvDataBuf;
	WSABUF SendDataBuf;
	char RecvBuf[BUFFER_SIZE];
	char SendBuf[BUFFER_SIZE];
	// �������ͱ�ʾ
	bool OperType;
}PER_IO_OPERATION_DATA, *PPER_IO_OPERATION_DATA;

// �ص��������ݺ���ԭ��
typedef void __stdcall ProcessRecvData(unsigned long sIP, SOCKET sClient,
	const char*pData, unsigned long DataLength);

DWORD WINAPI ServerWorkerProc(LPVOID lParam);
DWORD WINAPI ListenProc(LPVOID lParam);

class CIocpModeSvr {
public:
	CIocpModeSvr();
	virtual~CIocpModeSvr();

	// ��ʼ��
	bool Init(ProcessRecvData* pProcessRecvData,
		unsigned long iSvrPort = SVRPORT);
	// ����ʼ��
	void UnInit();

	/* ���ڷ�����Ϣ�ĺ����� */
	bool SendMsg(LPCTSTR TargetIp, char * pData, unsigned long Length);
	bool SendMsg(SOCKET sClient, char * pData, unsigned long Length);
	bool SendMsgToAll(char * pData, unsigned long Length);
	bool SendMsgToOther(LPCTSTR ExceptIp, char* pData, unsigned long Length);
	bool SendMsgToOther(SOCKET ExceptSocket, char * pData,
		unsigned long Length);

	// ��ñ���Ip��ַ
	const char * GetLocalIpAdd() {
		if (IsStart)
			return HostIpAddr.c_str();
		else
			return NULL;
	}

	// ��÷�����ʹ�õĶ˿ں�
	unsigned short GetSvrPort() {
		if (IsStart)
			return m_SvrPort;
		else
			return 0;
	}

public:
	bool DisConnectClient(LPCTSTR ClientIp);
	bool DisConnectClient(SOCKET sClient);
	void DisConnectAll();

protected:
	int InitNetWork(unsigned int SvrPort = SVRPORT,
		std::string *pHostIpAddress = NULL);
	void WriteLogString(LPCTSTR strLog);

	ProcessRecvData* m_pProcessRecvData;

private:
	// ��ɾ��
	HANDLE CompletionPort;

	// ����IP
	std::string HostIpAddr;
	// �ͻ���Ϣ�б�
	std::vector<PER_HANDLE_DATA>ClientInfo;

	// �ͻ���Ϣ�ٽ籣����
	CRITICAL_SECTION cInfoSection;
	// �����Ƿ��Ѿ�����
	bool IsStart;
	// �����˿�
	SOCKET ListenSocket;
	// �����߳̾�������ڷ���ʼ��ʱ���������߳�
	HANDLE ListenThreadHandle;
	// ����˿ڼ�¼
	unsigned short m_SvrPort;

	friend DWORD WINAPI ServerWorkerProc(LPVOID lParam);
	friend DWORD WINAPI ListenProc(LPVOID lParam);
};

#endif // !defined(AFX_IOCPMODESVR_H__46FFF420_23C3_4356_A88D_AEBDA61EA186__INCLUDED_)
