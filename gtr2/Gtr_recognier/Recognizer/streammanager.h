#ifndef STREAMMANAGER_H
#define STREAMMANAGER_H

#include <QObject>
#include <QIODevice>
#include <QDataStream>

class StreamManager
{
public:
	StreamManager(QByteArray &data);

	qint8 ReadInt8();
	qint16 ReadInt16();
	qint32 ReadInt32();
	quint8 ReadUInt8();
	quint16 ReadUInt16();
	quint32 ReadUInt32();
	qint32 ReadQBytes(char *result, int length);
	QByteArray ReadQBytes();
	QString ReadQString();

	void WriteUInt8(quint8 val){ m_stream << val; }
	void WriteUInt16(quint16 val){ m_stream << val; }
	void WriteUInt32(quint32 val){ m_stream << val; }
	void WriteInt8(qint8 val){ m_stream << val; }
	void WriteInt16(qint16 val){ m_stream << val; }
	void WriteInt32(qint32 val){ m_stream << val; }
	void WriteBytes(const char *result, int length);
	void WriteBytes(const QByteArray &val);
	void WriteQString(const QString &val);

	void Seek(quint64 type);
	qint32 Size()const;
private:
	QDataStream m_stream;
};

#endif // STREAMMANAGER_H
