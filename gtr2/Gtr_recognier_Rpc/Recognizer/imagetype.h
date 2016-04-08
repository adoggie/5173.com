#ifndef IMAGETYPE_H
#define IMAGETYPE_H


#include <QDateTime>
#include <QImage>
#include <QString>

class SocketManager;
struct AuthPacketT{
	quint32  cookie;		
};

struct MbkImage:AuthPacketT
{
	QString NO;
	QImage Image;
	QImage Position;
	QByteArray positionPixData;
	QDateTime CreateTime;
};


struct YzmImage:AuthPacketT
{
	QString NO;
	QImage Image;
	QByteArray pixData;
	QDateTime CreateTime;
};



#endif // IMAGETYPE_H
