// IocpModeSvr.cpp: implementation of the CIocpModeSvr class.
//
//////////////////////////////////////////////////////////////////////

#include "IocpModeSvr.h"
#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

#pragma  warning(disable:4800)

DWORD WINAPI ServerWorkerProc(LPVOID lParam) {
	CIocpModeSvr* pSvr = (CIocpModeSvr*)lParam;
	HANDLE CompletionPort = pSvr->CompletionPort;
	DWORD ByteTransferred;
	LPPER_HANDLE_DATA PerHandleData;
	PPER_IO_OPERATION_DATA PerIoData;
	DWORD RecvByte;
	while (true) {
		bool bSuccess = GetQueuedCompletionStatus
		(CompletionPort, &ByteTransferred, (LPDWORD) & PerHandleData, (LPOVERLAPPED*) & PerIoData,
			INFINITE);
		// �˳��źŵ���˳��߳�
		if (ByteTransferred == -1 && PerIoData == NULL) {
			return 1L;
		}
		// �ͻ����Ѿ��Ͽ����ӻ������ӳ��ִ���
		if (ByteTransferred == 0 &&
			(PerIoData->OperType == RECV_POSTED || PerIoData->OperType == SEND_POSTED)) {
			// ���ÿͻ�������ɾ��
			int arrSize = 0;
			bool bFind = false;
			::EnterCriticalSection(&pSvr->cInfoSection);
			while (arrSize < pSvr->ClientInfo.size()) {
				PER_HANDLE_DATA pPerHandleData = pSvr->ClientInfo.at(arrSize);
				if ((pPerHandleData.IpAddr == PerHandleData->IpAddr) &&
					(pPerHandleData.sClient == PerHandleData->sClient)) {
					bFind = true;
					pSvr->ClientInfo.erase(pSvr->ClientInfo.begin() + arrSize);
					break;
				}
				arrSize++;
			}
			::LeaveCriticalSection(&pSvr->cInfoSection);
			if (bFind) {
				// ��¼�˳���־
				// CString LogStr;
				// in_addr in_A;
				// in_A.S_un.S_addr=PerHandleData->IpAddr;
				// LogStr.Format("Ip: %s,Socket : %d Disconneted",inet_ntoa(in_A),PerHandleData->sClient);
				// pSvr->WriteLogString(LogStr);
				// TRACE("\nSocket : %d Disconneted",PerHandleData->sClient);
				// ���ûص�������֪ͨ�ϲ�ÿͻ����Ѿ��Ͽ�
				pSvr->m_pProcessRecvData(PerHandleData->IpAddr,
					PerHandleData->sClient, NULL, 0);
				// �ر��׽ӿ�
				closesocket(PerHandleData->sClient);
				GlobalFree(PerHandleData);
				GlobalFree(PerIoData);
			}
			continue;
		}
		// Ϊ��������ɣ���������
		if (PerIoData->OperType == RECV_POSTED) {
			// ���ûص���������������
			pSvr->m_pProcessRecvData(PerHandleData->IpAddr,
				PerHandleData->sClient, PerIoData->RecvBuf, ByteTransferred);
			// ��Դ�����ÿ�
			memset(PerIoData->RecvBuf, 0, BUFFER_SIZE);
			ByteTransferred = 0;
			// ����IO��������
			unsigned long Flag = 0;
			ZeroMemory(&(PerIoData->OverLapped), sizeof(OVERLAPPED));

			PerIoData->RecvDataBuf.buf = PerIoData->RecvBuf;
			PerIoData->RecvDataBuf.len = BUFFER_SIZE;
			PerIoData->OperType = RECV_POSTED;
			// �ύ��һ��Recv����
			WSARecv(PerHandleData->sClient, &(PerIoData->RecvDataBuf), 1,
				&RecvByte, &Flag, &(PerIoData->OverLapped), NULL);
		}
		// ������ɣ��ÿջ��������ͷŻ�����
		if (PerIoData->OperType == SEND_POSTED) {
			memset(PerIoData, 0, sizeof(PER_IO_OPERATION_DATA));
			GlobalFree(PerIoData);
			ByteTransferred = 0;
		}
	}
	return 0L;
}

DWORD WINAPI ListenProc(LPVOID lParam) {
	CIocpModeSvr* pSvr = (CIocpModeSvr*)lParam;
	SOCKET Accept;
	while (true) {
		// ���տͻ�������
		Accept = WSAAccept(pSvr->ListenSocket, NULL, NULL, NULL, 0);
		// �����µľ����������

		LPPER_HANDLE_DATA PerHandleData = (LPPER_HANDLE_DATA)\
 GlobalAlloc(GPTR, sizeof(PER_HANDLE_DATA));
		// ȡ�ÿͻ�����Ϣ
		sockaddr soad;
		sockaddr_in in;
		int len = sizeof(soad);
		if (getpeername(Accept, &soad, &len) == SOCKET_ERROR) {
			// CString LogStr;
			// LogStr.Format("getpeername() faild : %d",GetLastError());
			// pSvr->WriteLogString(LogStr);
		}
		else {
			memcpy(&in, &soad, sizeof(sockaddr));
		}
		// �������
		PerHandleData->sClient = Accept;
		PerHandleData->IpAddr = in.sin_addr.S_un.S_addr;
		// �洢�ͻ���Ϣ
		::EnterCriticalSection(&pSvr->cInfoSection);
		pSvr->ClientInfo.push_back(*PerHandleData);
		::LeaveCriticalSection(&pSvr->cInfoSection);
		// ת����Ϣ
		// CString LogStr;
		// LogStr.Format("UserIP: %s ,Socket : %d Connected!",inet_ntoa(in.sin_addr),Accept);
		// pSvr->WriteLogString(LogStr);

		// TRACE("\nUserIP: %s ,Socket : %d Connected!",inet_ntoa(in.sin_addr),Accept);
		// �����ͻ��˿ڵ���ɶ˿ڣ���������ڴ�ʱ���󶨵���ɶ˿�
		CreateIoCompletionPort((HANDLE)Accept, pSvr->CompletionPort, (DWORD)
			PerHandleData, 0);
		// Io�������ݱ�־

		PPER_IO_OPERATION_DATA PerIoData = (PPER_IO_OPERATION_DATA)\
 GlobalAlloc(GPTR, sizeof(PER_IO_OPERATION_DATA));
		unsigned long Flag = 0;
		DWORD RecvByte;
		ZeroMemory(&(PerIoData->OverLapped), sizeof(OVERLAPPED));

		PerIoData->RecvDataBuf.buf = PerIoData->RecvBuf;
		PerIoData->RecvDataBuf.len = BUFFER_SIZE;
		PerIoData->OperType = RECV_POSTED;
		// �ύ�׸�������������
		// ��ʱ
		// ����ͻ��˶Ͽ�����
		// ��Ҳ�����Խ�������ʱ�õ�֪ͨ
		WSARecv(PerHandleData->sClient, &(PerIoData->RecvDataBuf), 1,
			&RecvByte, &Flag, &(PerIoData->OverLapped), NULL);
	}
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CIocpModeSvr::CIocpModeSvr() {
	IsStart = false;
}

CIocpModeSvr::~CIocpModeSvr() {
}

bool CIocpModeSvr::SendMsg(LPCTSTR TargetIp, char * pData,
	unsigned long Length) {
	if (TargetIp == "" || pData == NULL || Length == 0 || !IsStart)
		return false;

	bool bFind = false;
	PER_HANDLE_DATA pPerHandleData;
	memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));

	unsigned long tIp = inet_addr(TargetIp);
	// �ڱ��в��Ҹÿͻ������ݲ���������

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	while (arrSize < ClientInfo.size()) {
		pPerHandleData = ClientInfo.at(arrSize);
		if ((pPerHandleData.IpAddr == tIp)) {
			bFind = true;
			break;
		}
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	// �ҵ��ÿͻ��ˣ������ύ��������������
	if (bFind) {
		return SendMsg(pPerHandleData.sClient, pData, Length);
	}
	else {
		// CString LogStr;
		// pData[Length]='\0';
		// LogStr.Format("��ͼ�������ݵ�û�����ӵĿͻ���:%s����:%s",TargetIp,pData);
		// WriteLogString(LogStr);
		return false;
	}
	return false;
}

// �ύ������Ϣ����
// ����ύ������Ϣʧ�ܣ�
// �򽫵����ڹ����߳��ｫĿ��ͻ��˵������ж�
bool CIocpModeSvr::SendMsg(SOCKET sClient, char * pData, unsigned long Length) {
	if (sClient == INVALID_SOCKET || pData == NULL || Length == 0 || !IsStart)
		return false;

	// ���������
	PPER_IO_OPERATION_DATA PerIoData = (PPER_IO_OPERATION_DATA)\
 GlobalAlloc(GPTR, sizeof(PER_IO_OPERATION_DATA));

	// ׼������
	unsigned long Flag = 0;
	DWORD SendByte;
	ZeroMemory(&(PerIoData->OverLapped), sizeof(OVERLAPPED));
	memcpy(PerIoData->SendBuf, pData, Length);
	PerIoData->SendDataBuf.buf = PerIoData->SendBuf;
	PerIoData->SendDataBuf.len = Length;
	PerIoData->OperType = SEND_POSTED;
	int bRet = WSASend(sClient, &(PerIoData->SendDataBuf), 1, &SendByte, Flag, &
		(PerIoData->OverLapped), NULL);
	if (bRet == SOCKET_ERROR && GetLastError() != WSA_IO_PENDING) {
		// CString LogStr;
		// LogStr.Format("WSASend With Error : %d",GetLastError());
		// WriteLogString(LogStr);
		return false;
	}
	else
		return true;

	return false;
}

bool CIocpModeSvr::SendMsgToAll(char * pData, unsigned long Length) {
	if (pData == NULL || Length == 0 || !IsStart)
		return false;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		SendMsg(pPerHandleData.sClient, pData, Length);
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	return true;
}

bool CIocpModeSvr::SendMsgToOther(LPCTSTR ExceptIp, char *pData,
	unsigned long Length) {
	if (ExceptIp == "" || pData == NULL || Length == 0 || !IsStart)
		return false;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		if (pPerHandleData.IpAddr != inet_addr(ExceptIp))
			SendMsg(pPerHandleData.sClient, pData, Length);
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	return true;
}

bool CIocpModeSvr::SendMsgToOther(SOCKET ExceptSocket, char * pData,
	unsigned long Length) {
	if (ExceptSocket == INVALID_SOCKET || pData == NULL || Length == 0 ||
		!IsStart)
		return false;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		if (pPerHandleData.sClient != ExceptSocket)
			SendMsg(pPerHandleData.sClient, pData, Length);
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	return true;
}

bool CIocpModeSvr::Init(ProcessRecvData* pProcessRecvData,
	unsigned long iSvrPort) {
	if (IsStart || pProcessRecvData == NULL)
		return false;

	m_SvrPort = iSvrPort;

	::InitializeCriticalSection(&cInfoSection);

	m_pProcessRecvData = pProcessRecvData;
	int bRet = InitNetWork(iSvrPort, &HostIpAddr);
	if (bRet == 0) {
		IsStart = true;
		return true;
	}
	else
		return false;
}

void CIocpModeSvr::DisConnectAll() {
	if (!IsStart)
		return;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		shutdown(pPerHandleData.sClient, 1);
		closesocket(pPerHandleData.sClient);
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
}

bool CIocpModeSvr::DisConnectClient(LPCTSTR ClientIp) {
	if (!IsStart || ClientIp == "")
		return false;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		if (pPerHandleData.IpAddr == inet_addr(ClientIp)) {
			shutdown(pPerHandleData.sClient, 1);
			closesocket(pPerHandleData.sClient);
			::LeaveCriticalSection(&cInfoSection);
			return true;
		}
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	return false;
}

bool CIocpModeSvr::DisConnectClient(SOCKET sClient) {
	if (!IsStart || sClient == INVALID_SOCKET)
		return false;

	::EnterCriticalSection(&cInfoSection);
	int arrSize = 0;
	PER_HANDLE_DATA pPerHandleData;
	while (arrSize < ClientInfo.size()) {
		memset(&pPerHandleData, 0, sizeof(PER_HANDLE_DATA));
		pPerHandleData = ClientInfo.at(arrSize);
		if (pPerHandleData.sClient == sClient) {
			shutdown(pPerHandleData.sClient, 1);
			closesocket(pPerHandleData.sClient);
			::LeaveCriticalSection(&cInfoSection);
			return true;
		}
		arrSize++;
	}
	::LeaveCriticalSection(&cInfoSection);
	return false;
}

void CIocpModeSvr::UnInit() {
	if (!IsStart)
		return;
	// �˳������߳�
	SYSTEM_INFO sys_Info;
	GetSystemInfo(&sys_Info);
	for (int i = 0; i < sys_Info.dwNumberOfProcessors * 2 + 2; i++) {
		// �ĳ��˳���Ϣ
		PostQueuedCompletionStatus(CompletionPort, -1, -1, NULL);
	}
	// �˳������߳�
	::TerminateThread(ListenThreadHandle, 1L);
	::WaitForSingleObject(ListenThreadHandle, 10);
	CloseHandle(ListenThreadHandle);
	// �ر����������
	shutdown(ListenSocket, 0);
	closesocket(ListenSocket);
	// �жϵ�ǰ��������
	DisConnectAll();
	::DeleteCriticalSection(&cInfoSection);
	m_pProcessRecvData = NULL;
	IsStart = false;
}

int CIocpModeSvr::InitNetWork
	(unsigned int SvrPort, std::string *pHostIpAddress) {
	// ��������
	// CString LogStr;
	int Error = 0;
	WSADATA wsaData;
	char Name[100];
	hostent *pHostEntry;
	in_addr rAddr;
	// Net Start Up
	Error = WSAStartup(MAKEWORD(0x02, 0x02), &wsaData);
	if (Error != 0) {
		Error = WSAGetLastError();
		pHostIpAddress->assign("");

		// LogStr.Format("WSAStartUp Faild With Error: %d",Error);
		// WriteLogString(LogStr);

		return Error;
	}
	// Make Version
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		WSACleanup();

		WriteLogString("The Local Net Version Is not 2");

		return-1;
	}
	// Get Host Ip
	Error = gethostname(Name, sizeof(Name));
	if (0 == Error) {
		pHostEntry = gethostbyname(Name);
		if (pHostEntry != NULL) {
			memcpy(&rAddr, pHostEntry->h_addr_list[0], sizeof(struct in_addr));
			pHostIpAddress->assign(inet_ntoa(rAddr));
		}
		else {
			Error = WSAGetLastError();
			// LogStr.Format("GetHostIp faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;

		}
	}
	else {
		Error = WSAGetLastError();
		// LogStr.Format("gethostname faild with Error: %d",Error);
		// WriteLogString(LogStr);
		return Error;
	}
	if (0 == Error) {
		// ���������˿�
		ListenSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0,
			WSA_FLAG_OVERLAPPED);
		if (ListenSocket == INVALID_SOCKET) {
			Error = WSAGetLastError();
			// LogStr.Format("CreateSocket faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;
		}
	}
	// �󶨵�Ŀ���ַ
	if (0 == Error) {
		sockaddr_in InternetAddr;
		InternetAddr.sin_family = AF_INET;
		InternetAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		InternetAddr.sin_port = htons(SvrPort);
		if (bind(ListenSocket, (PSOCKADDR) & InternetAddr, sizeof(InternetAddr)
			) == SOCKET_ERROR) {
			Error = GetLastError();
			// LogStr.Format("bind Socket faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;
		}
	}
	// �����˿��ϵ���������
	if (0 == Error) {
		if (listen(ListenSocket, 5) == SOCKET_ERROR) {
			Error = GetLastError();
			// LogStr.Format("listen Socket faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;
		}
	}
	// ������ɶ˿ھ��
	if (0 == Error) {
		CompletionPort = CreateIoCompletionPort
			(INVALID_HANDLE_VALUE, NULL, 0, 0);
		if (CompletionPort == INVALID_HANDLE_VALUE) {
			Error = GetLastError();
			// LogStr.Format("CreateIoCompletionPort faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;
		}
	}
	// ���������̣߳��߳���ΪCPU����������*2+2
	if (0 == Error) {
		SYSTEM_INFO sys_Info;
		GetSystemInfo(&sys_Info);
		for (int i = 0; i < sys_Info.dwNumberOfProcessors * 2 + 2; i++) {
			HANDLE ThreadHandle;
			DWORD ThreadID;

			ThreadHandle = CreateThread(NULL, 0, ServerWorkerProc, this, 0,
				&ThreadID);
			if (ThreadHandle == NULL) {
				Error = WSAGetLastError();
				// LogStr.Format("Create Server Work Thread faild with Error: %d",Error);
				// WriteLogString(LogStr);
				return Error;
			}
			CloseHandle(ThreadHandle);
		}
	}
	// ���������߳�
	if (0 == Error) {
		DWORD thID;
		ListenThreadHandle = CreateThread(NULL, 0, ListenProc, this, 0, &thID);
		if (ListenThreadHandle == NULL) {
			Error = WSAGetLastError();
			// LogStr.Format("Create Listen Thread faild with Error: %d",Error);
			// WriteLogString(LogStr);
			return Error;
		}
	}
	return Error;
}

void CIocpModeSvr::WriteLogString(LPCTSTR strLog) {
	SYSTEMTIME sysTm;
	::GetLocalTime(&sysTm);
	std::ofstream OutputFile;
	OutputFile.open("NetSvrLog.txt", std::ios::app);
	OutputFile << sysTm.wYear << "��" \
 << sysTm.wMonth << "��" \
 << sysTm.wDay << "��" \
 << sysTm.wHour << "ʱ" \
 << sysTm.wMinute << "��" \
 << sysTm.wSecond << "��" \
 << ":" \
 << "    " \
 << strLog \
 << "\n" \
 << std::endl;
	OutputFile.close();
}
