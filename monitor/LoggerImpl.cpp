#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include "LoggerImpl.h"
#include "main.h"

extern TForm1* Form1;

std::string GetIPFromConn(const std::string & strConn);

LoggerImpl::LoggerImpl() {

}

LoggerImpl::~LoggerImpl() {

}

void LoggerImpl::gameMsg(const ::gtr::GameIdentifyT& gameInfo, ::Ice::Int timeTick,
	const ::gtr::LogMessageT& msg, const ::Ice::Current& current) {
	assert(Form1);
	


	char * nexttok = NULL;
	unsigned int slmax = 1024*8;
	char* tok;

	std::vector<std::string> fields;
	tok = strtok_s((char*)msg.msg.c_str(),&slmax,",",&nexttok);
	while(tok){
		fields.push_back(tok);
		tok = strtok_s(NULL,&slmax,",",&nexttok);
	}
	if(fields.size() < 5){
		return ;
	}
	LogPacketT * packet = new LogPacketT;
	std::vector<std::string>::iterator itr;
	itr = fields.begin();
	std::advance(itr,5);
	packet->body.assign(itr,fields.end());
	LogGameMessageT* gmsg = packet->getMessage();
	if(gmsg ==NULL){
		delete packet;
		return ;
	}
	delete packet;
	LogGameDetailT* msgdetail;
	if( gmsg->type ==  LogGameMessageT::GAME_MSG_DETAIL){
	   msgdetail = (LogGameDetailT*)gmsg;
	   LPROBOTDATAMISC lpRobotDataMisc = Form1->GetRobotMiscByIP(msgdetail->ip.c_str());
	   if (lpRobotDataMisc) {
		DoLogMessage(msgdetail, lpRobotDataMisc->lpRobot);
		DoInsertBusPkgOperation(msgdetail);
	   }
	}
	delete gmsg;
}

void LoggerImpl::gameImage(const ::gtr::GameIdentifyT& gameInfo, ::Ice::Int nTimeElapsed,
	const ::std::string& strOp, const ::gtr::ImageDataT& imgData,
	const ::Ice::Current& current) {
	assert(Form1);
/*
	BUSINESS_INFO bi;
	BUSINESS_PKG bp;
	bi.lpBusPkg = &bp;
	bi.uTimeElapsed = (UINT)nTimeElapsed;
	bi.lpBusPkg->strOrderId = gameInfo.tradeNo;
	bi.lpBusPkg->strGameId = gameInfo.id;
	bi.lpBusPkg->strDetail = strOp;
	bi.lpBusPkg->strIP = GetIPFromConn(current.con->toString());

	LPROBOTDATAMISC lpRobotDataMisc = Form1->GetRobotMiscByIP
	(bi.lpBusPkg->strIP.c_str());
	if ( lpRobotDataMisc ) {
		lpRobotDataMisc->uHeartbeat = GetTickCount();
		DoLogMessage(bi, lpRobotDataMisc->lpRobot);

		unsigned char* lpData = new unsigned char[imgData.bytes.size()];
		for (size_t i = 0; i < imgData.bytes.size(); i++) {
			lpData[i] = imgData.bytes.at(i);
		}

		DoInsertBusPkgWithImageOperation(bi, lpData, imgData.bytes.size());
		delete[]lpData;
	}
*/
}

::Ice::Int LoggerImpl::getType(const ::Ice::Current&){
	return 0;
}

void LoggerImpl::heartbeat(
	const ::std::string& strSenderType,
	const ::std::string& strSenderID,
	const ::Ice::Current& current){

	assert(Form1);
	std::string strIP = GetIPFromConn(current.con->toString());
	LPROBOTDATAMISC lpRobotDataMisc = Form1->GetRobotMiscByIP(strIP.c_str());
	if ( lpRobotDataMisc ) {
		//lpRobotDataMisc->uHeartbeat = ::GetTickCount();
	}
}
::gtr::ServiceIdentifyT LoggerImpl::getId(const ::Ice::Current&){
	return ::gtr::ServiceIdentifyT();
}


::Ice::Int LoggerImpl::getTimestamp(const ::Ice::Current&){
	return 0;
}

void LoggerImpl::shutdown(const ::Ice::Current&){
	return;
}

std::string GetIPFromConn(const std::string& strConn) {
	if (strConn.size() > 15) {
		const char* lpszIPBegin = strstr(strConn.c_str(), "remote address = ");
		const char* lpszIPEnd = strstr(lpszIPBegin, ":");
		if (!lpszIPBegin || !lpszIPEnd || (lpszIPEnd - lpszIPBegin) < 7) {
			return NULL;
		}
		lpszIPBegin += 17;
		return std::string(lpszIPBegin, lpszIPEnd - lpszIPBegin);
	}

	return NULL;
}

/*
int LogServerI::run(int argc, char* argv[]) {
	if (argc > 1) {

		return EXIT_FAILURE;
	}

	try{
		Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter(
							"ILogServer");
		gtr::ILoggerPtr spLogger = new LoggerImpl;
		adapter->add(spLogger, communicator()->stringToIdentity("logserver"));
		adapter->activate();
		communicator()->waitForShutdown();
	}
	catch(const ::Ice::Exception& __ex) {
    	int i = 0;
	}
	return EXIT_SUCCESS;
}
*/
