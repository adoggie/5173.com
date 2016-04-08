#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QBuffer>
#include <QImageReader>
#include <QTimer>
#include <QPixmap>
#include <QSettings>
#include <QCoreApplication>

#include "streammanager.h"
#include "packagetype.h"
#include "imagetype.h"

#include <string>
#include <map>
#include <vector>
#include <list>

#include <QMutexLocker>

#define NO_SIZE 64
#define IMAGE_SIZE 2048000
#define POSITION_SIZE 64
#define TIME_SIZE 64




class SocketManager : public QObject
{
	Q_OBJECT
public:
	SocketManager(); 
public:
	
	~SocketManager();
	//static SocketManager &GetInstance();
	
	bool init(const QString& host,int port );  
	 
	void initNet();
	void closeNet();
	bool isLogin()const;

	void SendLeavePacket();
	void SendGoBackpacket();
	void SendLoginInfoPacket( const QString &account, const QString &pwd );
	void SendGetTaskPacket();
	
	void sendAnswer( const QString &NO, const QString &answer, bool isMbk);
private:
	

	QTcpSocket m_tcpSocket;

	QString m_serverIP;
	int m_serverPort;

	int m_length;

	bool m_loginState;

	void readSetting();
	
signals:
	void showMessage(const QString &msg);
	void displayMbkImage(const MbkImage &mbkImage);
	void displayYzmImage(const YzmImage &yzmImage);
	void connected(SocketManager* sock);
	void loginResult( eLoginResult r );
private slots:
	void readyRead();
	//void sendAnswer( const QString &NO, const QString &answer, bool isMbk);
	void tcpError(QAbstractSocket::SocketError error);
	void doConnected();
	void doDisconnected();
	
private:
	QMutex	_mtx_send;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
 

#endif // SOCKETMANAGER_H
