#ifndef IMAGETYPE_H
#define IMAGETYPE_H


#include <QDateTime>
#include <QImage>
#include <QString>

class SocketManager;
struct AuthPacketT{
	SocketManager * socket;
	AuthPacketT(){
		socket = NULL;
	}
};

struct MbkImage:AuthPacketT
{
	QString NO;
	QImage Image;
	QImage Position;
	QByteArray positionPixData;
	QDateTime CreateTime;
	quint32 gameId;  //”Œœ∑±‡∫≈ 2010.5.27
};


struct YzmImage:AuthPacketT
{
	QString NO;
	QImage Image;
	QByteArray pixData;
	QDateTime CreateTime;
	quint32 gameId; //”Œœ∑±‡∫≈ 2010.5.27
};



#endif // IMAGETYPE_H
