

#include "answerServant.h"
#include "recognizer.h"


::Ice::Int AnswerServer::getType(const Ice::Current&){

	return 0;
}

::gtr::ServiceIdentifyT AnswerServer::getId(const Ice::Current&){
	gtr::ServiceIdentifyT sid ;
	return sid;
}

::Ice::Int AnswerServer::getTimestamp(const Ice::Current&){
	return 0;
}

void AnswerServer::shutdown(const Ice::Current&){

}

void AnswerServer::heartbeat(const ::std::string&,const ::std::string&,const Ice::Current&){

}

::Ice::Int AnswerServer::getRemains(const Ice::Current&){	
	return _questions.size();
}

::Ice::Int AnswerServer::addQuestion(const ::gtr::IQuestionServerPrx& server,const ::std::string& no,const ::std::string& createTime,const ::gtr::QuestionContentT& question,const Ice::Current& c){
	QMutexLocker l(&_mtx_questions);		
	QuestionListT::iterator itr;
	itr = _questions.find(no);
	
	if( itr ==_questions.end() ){
		_seqno++;
		QuestionT* q = new QuestionT;
		q->no = no;
		q->createtime = atoi(createTime.c_str());
		q->cookie = _seqno;
		q->content = question;
		q->server = server;
		q->serveraddr = c.con->toString();
		_questions[no] = q;		
		//emit addQuestion(_questions[no]);		
		
		//gtr::QuestionResultT qrst;
		//q.server->answerResult(q.no,qrst);
		
		Recognizer::instance()->recvQuestion(*q);
	}
	return getRemains(c);
}



AnswerServer* AnswerServer::instance(){
	static AnswerServer *handle = NULL;
	if( handle == NULL){
		handle = new AnswerServer();
	}
	return handle;
}

AnswerServer::AnswerServer(){
	_seqno = 0;
}

void AnswerServer::shiftQuestion(const std::string& no){
	QMutexLocker l(&_mtx_questions);		
	QuestionListT::iterator itr;
	itr = _questions.find(no);
	if( itr !=_questions.end() ){
		QuestionT* q = itr->second;
		_questions.erase(itr);
		delete q;
	}
}


gtr::IAnswerEndpointPrx AnswerServer::answerPrx;
