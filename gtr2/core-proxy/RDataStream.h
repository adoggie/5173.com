#ifndef _RDATASTREAM_H_
#define _RDATASTREAM_H_
#include "Policy.h"
#include <string>
#include <vector>
#include <map>
#include <list>

//����IO��,ֻ��,���������ݵ�����,ֱ����������������Ϊ�������
//�����������Ķ�������������,���뱣֤�ⲿ������Ч
class RDataStream
{
public:
	RDataStream( const char *pData, unsigned int size ):m_pData(pData),m_current_pos(pData),m_end(pData+size){}
	~RDataStream(){}
	enum eMoveFlag{
		Begin,
		End,
		Current,
	};

	void seek( int pos, eMoveFlag f=Begin ){
		switch( f ){
		case Begin:
			m_current_pos = m_pData + pos;
			break;
		case End:
			m_current_pos = m_end + pos;
			break;
		case Current:
			m_current_pos = m_current_pos + pos;
			break;
		}
	}
	unsigned int pos()const	{ return m_current_pos - m_pData; }
	const char *data()const	{ return m_pData; }
	const char *current()const{ return m_current_pos; }
	const char *end()const{ return m_end; }
	bool atEnd()const	{ return m_current_pos>=m_end; }
	unsigned int size()const { return m_end-m_pData; }

	template< typename T >
	RDataStream &operator>>( T &val ){	//�������������
		val = ReadT<T>();
		return *this;
	}

	//vector
	template<typename T>
	RDataStream &operator>>( std::vector<T> &val ){	//�������������
		val.clear();
		int size = ReadInt();
		for( int i=0; i<size; ++i ){
			T temp;
			*this >> temp;
			val.push_back(temp);
		}
		return *this;
	}

	//map
	template<typename T, typename V>
	RDataStream &operator>>( std::map<T,V> &val ){	//�������������
		val.clear();
		int size = ReadInt();
		for( int i=0; i<size; ++i ){
			T temp_T;
			V temp_V;
			*this >> temp_T >> temp_V;
			val.insert( make_pair(temp_T, temp_V) );
		}
		return *this;
	}

	//list
	template<typename T>
	RDataStream &operator>>( std::list<T> &val ){	//�������������
		val.clear();
		int size = ReadInt();
		for( int i=0; i<size; ++i ){
			T temp;
			*this >> temp;
			val.push_back(temp);
		}
		return *this;
	}

	char *ReadRawBytes( char *out, int length ){
		const char* pos_end = m_current_pos + length;
		if( length!=0 && pos_end<=m_end ){
			memcpy( out, m_current_pos, length );
			m_current_pos = pos_end;
		}
		return out;
	}

	int ReadInt(){
		return ReadT<int>();
	}

	unsigned int ReadUInt(){
		return ReadT<unsigned int>();
	}

	__int64 ReadInt64(){
		__int64 temp;
		ReadRawBytes( (char*)&temp, sizeof(temp) );
		return temp;
	}

	char ReadChar(){
		return ReadT<char>();
	}

	unsigned char ReadUChar(){
		return ReadT<unsigned char>();
	}

	short ReadShort(){
		return ReadT<short>();
	}

	unsigned short ReadUShort(){
		return ReadT<unsigned short>();
	}

	float ReadFloat(){
		return ReadT<float>();
	}

	std::string ReadString(){
		return ReadT<std::string>();
	}

	char *ReadByteStream( char *p, int &size ){
		size = ReadUInt();
		if( size>0 )
			ReadRawBytes( p, size );
		p[size] = 0;
		return p;
	}

private:
	template< typename T >
	T ReadT(){//�������Ͷ���
		typedef TL::TypeTraits<T> PramTrait;
		typedef TL::Select<PramTrait::isStdFundamental||PramTrait::isPointer||PramTrait::isMemberPointer,T,void>::Result ParamType;//ָ��Ҳ����

		//ǿ���޶�ֻ���ǻ�������,�û��Զ������ͱ�����ʾƫ�ػ�������,������ͨ������
		const char* pos_end = m_current_pos + sizeof(ParamType);
		if( pos_end <= m_end ){
			const char *temp = m_current_pos;
			m_current_pos = pos_end;
			return *(ParamType*)temp;
		}
		return T();
	}

	template<>
	std::string ReadT<std::string>(){
		enum{MAX_STRING_LENGTH=0x1000};
		unsigned int size = ReadT<unsigned int>();
		const char *pos_end = m_current_pos + size;
		if( size!=0 && size<MAX_STRING_LENGTH && pos_end <= m_end ){
			const char *temp = m_current_pos;
			m_current_pos = pos_end;
			return std::string(temp,size);
		}
		return std::string();
	}

	const char	*m_pData;
	const char	*m_end;
	const char	*m_current_pos;
};

#endif