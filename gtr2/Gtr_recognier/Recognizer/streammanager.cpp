#include "streammanager.h"

StreamManager::StreamManager(QByteArray &data)
	: m_stream(&data, QIODevice::ReadWrite)
{
	m_stream.setByteOrder(QDataStream::LittleEndian);
}
quint32 StreamManager::ReadUInt32()
{
	quint32 result;
	m_stream >> result;
	return result;
}
quint16 StreamManager::ReadUInt16()
{
	quint16 result;
	m_stream >> result;
	return result;
}
quint8 StreamManager::ReadUInt8()
{
	quint8 result;
	m_stream >> result;
	return result;
}
qint32 StreamManager::ReadInt32()
{
	qint32 result;
	m_stream >> result;
	return result;
}
qint16 StreamManager::ReadInt16()
{
	qint16 result;
	m_stream >> result;
	return result;
}
qint8 StreamManager::ReadInt8()
{
	qint8 result;
	m_stream >> result;
	return result;
}


qint32 StreamManager::ReadQBytes(char *result, int arrayLength)
{
	quint32 length = ReadUInt32();
	if( arrayLength<length )
		return -1;

	m_stream.readRawData(result,length);
	return length;
}

QByteArray StreamManager::ReadQBytes()
{
	quint32 length = ReadUInt32();
	QByteArray temp;
	temp.resize( length );
	m_stream.readRawData( temp.data(), length );
	return temp;
}
QString StreamManager::ReadQString()
{
	return ReadQBytes();
}

void StreamManager::WriteBytes(const char *result, int length)
{
	m_stream << length;
	m_stream.writeRawData(result,length);
}
void StreamManager::WriteBytes(const QByteArray &val)
{
	WriteBytes( val.data(), val.size() );
}
void StreamManager::WriteQString(const QString &val)
{
	WriteBytes(val.toAscii());
}

void StreamManager::Seek(quint64 pos)
{
	m_stream.device()->seek(pos);
}

qint32 StreamManager::Size()const
{
	return m_stream.device()->size();
}
