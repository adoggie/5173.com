#ifndef _X_SOCKET_H_
#define _X_SOCKET_H_



#include <WinSock2.h>
  #include <MSTcpIP.h>
  #include <MSWSock.h>

class XSocket
{
public:
	XSocket();
	XSocket(SOCKET nSocket);
	~XSocket();

	XSocket &operator = (const SOCKET nSocket);
	operator SOCKET();

	// ����׽���
	SOCKET GetHandle();
	// �ж��׽��ֿ������
	bool IsValid();

	// ��һ��socket
	int Open();
	// �ر�һ��socket
	int Close();
	// ��ֹ�׽��������ݵĽ��ܺͷ���
	int Shutdown(int nHow);
	// �󶨷������ĵ�ַ��ip,port
	int Bind(const char *szIP, unsigned short nPort);
	// ����������
	int Listen(int nBacklog);
	// �ͻ��˵�����ip,port
	int Connect(const char *szIP, unsigned short nPort);
	// ���õ�ַ
	int ReuseAddr();
	// �ѷ�0�׽��ֱ�ɷ�������
	int SetNonBlock(bool bNonBlock);
	// ��Ϊ1���ͻ����׽����Ͻ���Nagle�㷨��ʹ�����ӳ�
	int SetNoDelay(int nNoDelay);
	// �׽��ֱ����óɿɽ��й㲥��Ϣ�ķ���
	int SetSndBuf(int nSndBuf);
	// �û��쳣���߼��
	int SetKeepAlive();
	// ��ȡ���������׽����ϵ����ݽ��ն�Ӧ�ĳ�ʱֵ
	int UpdateAcceptContext(SOCKET nListenSocket);

private:
	SOCKET m_nSocket;
};

#endif //_SOCKET_H_