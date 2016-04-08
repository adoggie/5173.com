
#ifndef _ANSWERSERVANT_H
#define _ANSWERSERVANT_H


#include <QtGui>
#include <QPointer>
#include <QDateTime>
#include <QImage>


#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include <gtrc.h>

struct QuestionT{
	std::string no;
	quint32 createtime;
	gtr::QuestionContentT content;
	quint32 cookie;
	
	QImage image;
	QImage image2;	
	gtr::IQuestionServerPrx server;
	std::string serveraddr;	//服务器连接信息
	//QDateTime CreateTime;
};
typedef std::map<std::string ,QuestionT*> QuestionListT;

//////////////////////////////////////////////////////////////////////////

class AnswerServer:public gtr::IAnswerEndpoint{//,public QObject{
	//Q_OBJECT
public:
	AnswerServer();
	static AnswerServer* instance();
	void shiftQuestion(const std::string& no) ;  //删除指定单号的问题记录 
	static gtr::IAnswerEndpointPrx answerPrx;
public:
	::Ice::Int getType(const Ice::Current&);
	::gtr::ServiceIdentifyT getId(const Ice::Current&);
	::Ice::Int getTimestamp(const Ice::Current&);
	void shutdown(const Ice::Current&);
	void heartbeat(const ::std::string&,const ::std::string&,const Ice::Current&);
	::Ice::Int getRemains(const Ice::Current&  );
	::Ice::Int addQuestion(const ::gtr::IQuestionServerPrx& server,const ::std::string&,const ::std::string&,const ::gtr::QuestionContentT&,const Ice::Current&);		
//signals:
//	void addQuestion( QuestionT& q);
private:
	
protected:
	QuestionListT	_questions;
	QMutex				_mtx_questions;	
	quint32		_seqno;
};



#endif


