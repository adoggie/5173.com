#include "socketmanager.h"
#include <fstream>
#include <QPainter>

SocketManager::SocketManager()
{
	m_loginState = false;
	//readSetting();

	m_length = 0;

	connect(&m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(&m_tcpSocket,SIGNAL(connected()),this,SLOT(doConnected()));
	connect(&m_tcpSocket,SIGNAL(disconnected()),this,SLOT(doDisconnected()));
	connect(&m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(tcpError(QAbstractSocket::SocketError)) );
}

SocketManager::~SocketManager()
{
	m_tcpSocket.close();
}

// SocketManager &SocketManager::GetInstance()
// {
// 	static SocketManager instance;
// 	return instance;
// }

bool SocketManager::init(const QString& host,int port ){
	m_serverIP = host;
	m_serverPort = port;
	return true;
}

/*
void SocketManager::readSetting()
{
	QString path = QCoreApplication::applicationDirPath();
	QSettings *settings = new QSettings(path+tr("\\Setting.ini"), QSettings::IniFormat);
	settings->beginReadArray("Server");
	m_serverIP = settings->value("ServerIP").toString();
	m_serverPort = settings->value("ServerPort").toInt();
}
*/

void SocketManager::initNet()
{
	if(m_tcpSocket.state()==QAbstractSocket::UnconnectedState)
	{
		QString ip = m_serverIP;
		short port = m_serverPort;
		m_tcpSocket.connectToHost(ip,port);
		emit showMessage(tr("正在连接服务器 %1:%2").arg(ip).arg(port));
	}
}
bool SocketManager::isLogin()const
{
	return m_loginState;
}
void SocketManager::closeNet()
{
	m_tcpSocket.disconnectFromHost();
}
void SocketManager::readyRead()
{
	while(true)
	{
		if(m_length==0){
			if(m_tcpSocket.bytesAvailable() < 4)
				return;
			m_tcpSocket.read((char*)&m_length,4);
		}

		if(m_tcpSocket.bytesAvailable() < m_length - 4)
			return;

		QByteArray data = m_tcpSocket.read(m_length - 4);
		StreamManager streamManager(data);

		quint8 packageType = streamManager.ReadUInt8();
		if(packageType == RECONGIZERHEART)
		{
			QByteArray data;
			StreamManager streamManager(data);
			streamManager.WriteUInt32(0);
			streamManager.WriteUInt8(RECONGIZERHEART);
			streamManager.Seek(0);
			streamManager.WriteUInt32(data.size());
			m_tcpSocket.write(data);
		}
		else if(packageType == MBKINFORMATON)
		{
			QString no = streamManager.ReadQString();
			QByteArray image = streamManager.ReadQBytes();
			QByteArray position = streamManager.ReadQBytes();
			QString time = streamManager.ReadQString();
			quint32 gameId = streamManager.ReadUInt32(); // 2010.6.3 scott
			QPixmap pixImage;
			pixImage.loadFromData( image );

			//密保位置,对于完美国际,传过来的可能是文本坐标,6个字节长
			QPixmap pixPosition;
			if( position.size()==6 )
			{
				pixPosition = QPixmap( 126, 50 );
				pixPosition.fill();
				QPainter painter(&pixPosition);
				painter.setFont( QFont("宋体", 24) );
				QRect rect( 0, 0, pixPosition.width(), pixPosition.height() );
				painter.drawText( rect, Qt::AlignCenter, QString(position) );
			}
			else
			{
				pixPosition.loadFromData( position );
			}

			MbkImage mbkImage;
			mbkImage.NO = no;
			mbkImage.Image = pixImage.toImage();
			mbkImage.Position = pixPosition.toImage();
			mbkImage.positionPixData = position;
			mbkImage.CreateTime = QDateTime::fromString( time, "yyyy-MM-dd hh:mm:ss" );
			mbkImage.socket = this;
			mbkImage.gameId = gameId;
			emit displayMbkImage(mbkImage);
		}
		else if(packageType == YZMINFORMATON)
		{
			QString no = streamManager.ReadQString();
			QByteArray image = streamManager.ReadQBytes();
			QString time = streamManager.ReadQString();

			QPixmap pixImage;
			pixImage.loadFromData(image);

			YzmImage yzmImage;
			yzmImage.NO = no;
			yzmImage.Image = pixImage.toImage();
			yzmImage.pixData = image;
			yzmImage.CreateTime = QDateTime::fromString(time,"yyyy-MM-dd hh:mm:ss");
			yzmImage.socket = this;
			emit displayYzmImage(yzmImage);
		}
		else if ( packageType==LOGINRESULT )
		{
			quint8 result = streamManager.ReadUInt8();
			switch ( result )
			{
			case LR_ACCOUNTERR:
				{
					m_loginState = false;
					emit loginResult(LR_ACCOUNTERR);
					break;
				}
			case LR_PWDERR:
				{
					m_loginState = false;
					emit loginResult(LR_PWDERR);
					break;
				}
			case LR_ISUSING:
				{
					m_loginState = false;
					emit loginResult(LR_ISUSING);
					break;
				}
			case LR_SUCCESS:
				{
					m_loginState = true;
					emit loginResult(LR_SUCCESS);
					break;
				}
			}
		}

		m_length = 0;
	}

}


void SocketManager::sendAnswer( const QString &NO, const QString &answer, bool isMbk)
{
	QMutexLocker l(&_mtx_send);
	QByteArray data;
	StreamManager streamManager(data);

	streamManager.WriteUInt32(0);
	streamManager.WriteUInt8(isMbk?MBKRESULT:YZMRESULT);
	streamManager.WriteQString(NO);
	streamManager.WriteQString(answer);
	streamManager.Seek(0);
	streamManager.WriteUInt32(data.size());
	
	m_tcpSocket.write(data);
}


void SocketManager::doConnected()
{
	emit showMessage(tr("连接成功"));
	emit connected(this);
}

void SocketManager::doDisconnected()
{
	emit showMessage(tr("连接断开"));
	m_loginState = false;
}

void SocketManager::tcpError(QAbstractSocket::SocketError error)
{
	emit showMessage(tr("连接错误: %1").arg(m_tcpSocket.errorString()));
}

void SocketManager::SendLeavePacket()
{
	QByteArray data;
	StreamManager streamManager(data);

	streamManager.WriteUInt32(0);
	streamManager.WriteUInt8(LEAVE);
	streamManager.Seek(0);
	streamManager.WriteUInt32( streamManager.Size() );

	m_tcpSocket.write(data);
}
void SocketManager::SendGoBackpacket()
{
	QByteArray data;
	StreamManager streamManager(data);

	streamManager.WriteUInt32(0);
	streamManager.WriteUInt8(GOBACK);
	streamManager.Seek(0);
	streamManager.WriteUInt32( streamManager.Size() );

	m_tcpSocket.write(data);
}
void SocketManager::SendLoginInfoPacket( const QString &account, const QString &pwd )
{
	QByteArray data;
	StreamManager streamManager(data);

	streamManager.WriteUInt32(0);
	streamManager.WriteUInt8(LOGININFO);
	streamManager.WriteQString( account );
	streamManager.WriteQString( pwd );
	streamManager.Seek(0);
	streamManager.WriteUInt32( streamManager.Size() );

	m_tcpSocket.write(data);
}
void SocketManager::SendGetTaskPacket()
{
	QMutexLocker l(&_mtx_send);
	QByteArray data;
	StreamManager streamManager(data);

	streamManager.WriteUInt32(0);
	streamManager.WriteUInt8(RECOGNIZERSTATUS);
	streamManager.Seek(0);
	streamManager.WriteUInt32( streamManager.Size() );

	m_tcpSocket.write(data);
}