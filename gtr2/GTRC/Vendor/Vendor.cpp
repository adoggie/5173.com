#include "StdAfx.h"
#include "Vendor.h"
#include "Dispatcher.h"
#include "Messagemanager.h"
#include "HostService.h"
#include "base64.h"
#include <sstream>
using namespace client;

extern string ipaddr;

extern void showlog(string msg);

Vendor::Vendor(const _VendorInfo &info)
{
	_vendorInfo = info;
	_status = Vendor::Idle;
	_enable = true;
	_wait_answer = true;
}

Vendor::~Vendor(void)
{
}

int Vendor::getTaskId()
{
	return time(NULL);
}

string Vendor::getStatusHint()
{
	switch(_status)
	{
	case Vendor::Idle:
		return "Idle";

	case Vendor::Busy:
		return "Busy";

	case Vendor::Timeout:
		return "Timeout";
	}

	return "Unknown";

}
/*
任务指派
: 根据_gameID启动Robot
: 
*/
void Vendor::assign(GtMessageBase *pmsg)
{
	if(pmsg==NULL)
	{
		return;
	}

	time_t now = time(NULL);
	switch(pmsg->getType())
	{
		// verify
	case VERIFYREQUEST:
		{
			VerifyInfo* pTI = (VerifyInfo*)pmsg;
			_tasklet.type = gtr::gwsVerify;
			_tasklet.id = getTaskId();
			_tasklet.no = pTI->NO;
			_tasklet.gameId = getGameId();
			_tasklet.account = pTI->Account;
			_tasklet.password = pTI->Password;
			_tasklet.area = pTI->Area;
			_tasklet.server = pTI->Server;
			//_tasklet.lineName;
			//_tasklet.lineNo;
			_tasklet.createTime = ctime(&now);

			_tasklet.verify.sellerActor = pTI->SellerActor;
			_tasklet.verify.level = pTI->Level;
			_tasklet.verify.money = pTI->Money;
			_tasklet.verify.verifyTime = pTI->Verifytime;
			_tasklet.verify.sellerSecondPwd = pTI->SellerSecondPwd;
			_tasklet.verify.sellerIndex = pTI->SellerIndex;
			_tasklet.verify.sellerGroup = pTI->SellerGroup;
			_tasklet.verify.bankPwd = pTI->BankPwd;
		}
		break;

		// post
	case TRANSACTREQUEST:
		{
			TransactionInfo* pTI = (TransactionInfo*)pmsg;
			_tasklet.type = gtr::gwsPost;
			_tasklet.id = getTaskId();
			_tasklet.no = pTI->NO;
			_tasklet.gameId = getGameId();
			_tasklet.account = pTI->Account;
			_tasklet.password = pTI->Password;
			_tasklet.area = pTI->Area;
			_tasklet.server = pTI->Server;
			//_tasklet.lineName;
			//_tasklet.lineNo;
			_tasklet.createTime = ctime(&now);

			_tasklet.post.money = pTI->Money;
			_tasklet.post.sellerActor = pTI->SellerActor;
			_tasklet.post.sellerLevel = pTI->SellerLevel;
			_tasklet.post.transactionTime = pTI->TransactionTime;
			_tasklet.post.sellerSecondPwd = pTI->SellerSecondPwd;
			_tasklet.post.buyerActor = pTI->BuyerActor;
			_tasklet.post.buyerLevel = pTI->BuyerLevel;
			_tasklet.post.buyerMoney = pTI->BuyerMoney;
			_tasklet.post.sellerIndex = pTI->SellerIndex;
			_tasklet.post.sellerGroup = pTI->SellerGroup;
			_tasklet.post.bankPwd = pTI->BankPwd;
		}
		break;

		// audit
	case ACCOUNTVERIFYREQUEST:
		{
			AccountVerifyInfo* pTI = (AccountVerifyInfo*)pmsg;
			_tasklet.type = gtr::gwsAccountAudit;
			_tasklet.id = getTaskId();
			_tasklet.no = pTI->NO;
			_tasklet.gameId = getGameId();
			_tasklet.account = pTI->Account;
			_tasklet.password = pTI->Password;
			_tasklet.area = pTI->Area;
			_tasklet.server = pTI->Server;
			//_tasklet.lineName;
			//_tasklet.lineNo;
			_tasklet.createTime = ctime(&now);

			_tasklet.audit.sellerActor = pTI->SellerActor;
			_tasklet.audit.sellerSecondPwd = pTI->SellerSecondPwd;
			_tasklet.audit.sellerIndex = pTI->SellerIndex;
			_tasklet.audit.sellerGroup = pTI->SellerGroup;
			_tasklet.audit.bankPwd = pTI->BankPwd;
		}
		break;

	default:
		;
	}
}

void Vendor::assign(gtr::GameTaskletT task)
{
	_tasklet = task;
}
/*
任务处理中
*/
bool Vendor::isIdle()
{
	return _status == Vendor::Idle;
}

#define GTRC_ROBOT_TIMEOUT	180
/*
任务处理超时
*/
bool Vendor::timeOut()
{
	if(_status == Vendor::Timeout)
		return true;

	if(_status == Vendor::Idle)
		return false;

	time_t end;
	end = time(NULL);
	double elapse = difftime(end, _start);
	if(elapse>GTRC_ROBOT_TIMEOUT)
	{
		gtrcLog("WARNING : Robot Timeout!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		_status = Vendor::Timeout;
	}

	return _status == Vendor::Timeout;

}

/*
日志存档
: 将执行日志提交给日志服务器
: 
*/
void Vendor::makeLog(string strLog)
{
	strLog = "\tLOG:" + strLog;
	showlog(strLog);
	
}

/*
截图存档
*/
void Vendor::makeScreenShot(string strName, void* imgData)
{
	strName = "\tIMAGE:" + strName;
	showlog(strName);
}

/*
取得任务数据
*/

gtr::GameTaskletT Vendor::getTask()
{
	string strLog = "Robot request for task";
	showlog(strLog);
	return _tasklet;
}

#define gLoggorWrap HostService::_instance._LoggorWrap

std::string encode_logmsg_base64(const char* s){
	std::string encmsg;
	char * buff;
	size_t ilen;
	ilen = strlen(s);
	size_t	size = base64_encode_alloc (s, ilen, &buff);
	encmsg.assign(buff,size);
	free(buff);
	return encmsg;
}

void Vendor::gtrcLog(std::string log)
{
	char buf[255];

	std::string ip = encode_logmsg_base64(ipaddr.c_str());
	std::string no = encode_logmsg_base64(_tasklet.no.c_str());
	std::string gameid = encode_logmsg_base64(_tasklet.gameId.c_str());

	itoa(time(0), buf, 10);

	std::string timetick = encode_logmsg_base64(buf);
	std::string detail = encode_logmsg_base64(log.c_str());

	stringstream logmsg;

	logmsg << "GRL,1.0,0,7," << time(0) << ",0," << no << ',' << gameid << ',' << ip << ',' << timetick << ',' << detail;
	

	::gtr::GameIdentifyT gameId;
	::gtr::LogMessageT msg;

	gameId.id = getGameId();
	gameId.tradeNo = getTaskNo();
	msg.xclass = 0;
	msg.msg = logmsg.str();
	gLoggorWrap.gameMsg(gameId, time(NULL), msg);
}


/*
心跳，计算超时
*/
void Vendor::heatbeat()
{
	string strMsg = "\tHearBeat";
	showlog(strMsg);
}

/*
认证: 秘保卡 & 验证码
*/
string Vendor::auth(int type, const vector<unsigned char>& imgData)
{
	string feedback;

	if(type==3)
	{
		YZMImage *pYzm = new YZMImage;
		pYzm->NO = getTaskNo();
		pYzm->YZMPix = *(vector<char>*)&imgData; 

		GtMessageBase* fdMsg = DISPATCHER.SendToServer(pYzm, getTaskNo(), 1);
		if(fdMsg && fdMsg->getType()==YZMCONTENT)
		{
			YZMContent* pYZM = (YZMContent*)fdMsg;
			feedback = pYZM->content;
			_userName = pYZM->username;
		}

		delete pYzm;
	}
	else
	{
		MBKImage *pMbk = new MBKImage;
		pMbk->NO = getTaskNo();
		pMbk->MBKPix = *(vector<char>*)&imgData; 

		GtMessageBase* fdMsg = DISPATCHER.SendToServer(pMbk, getTaskNo(), 1);
		if(fdMsg && fdMsg->getType()==MBKCONTENT)
		{
			MBKContent* pMBK = (MBKContent*)fdMsg;
			feedback = pMBK->content;
			_userName = pMBK->username;
		}

		delete pMbk;

	}

	return feedback;
}

string Vendor::auth(string authkey)
{
	string feedback;

	MBKImage *pMbk = new MBKImage;
	pMbk->NO = getTaskNo();
	for(int i=0; i<authkey.length(); i++)
	{
		pMbk->MBKPix.push_back(authkey[i]);
	}

	GtMessageBase* fdMsg = DISPATCHER.SendToServer(pMbk, getTaskNo(), 1);
	if(fdMsg && fdMsg->getType()==MBKCONTENT)
	{
		MBKContent* pMBK = (MBKContent*)fdMsg;
		feedback = pMBK->content;
		_userName = pMBK->username;
	}

	delete pMbk;

	return feedback;
}

/*
设置任务执行结果
*/
void Vendor::setFinished(bool sock)
{
	string strLog = "!!!!!Robot finished the task";
	showlog(strLog);

	_status = Vendor::Idle;

	if(sock)
		DISPATCHER.completeTask();
}

void Vendor::setResultFeedback(int nResult, string aux)
{
	//_status = Vendor::Idle;

	// finish the task 

	GtMessageBase *resultMsg = NULL;
	switch(_tasklet.type)
	{
	case gtr::gwsVerify:
		{
			VerifyResult* result = new VerifyResult;
			result->NO = getTaskNo();
			result->m_verifyResult = (eVerifyResult)nResult;
			resultMsg = result;
		}
		break;

	case gtr::gwsPost:
		{
			TransactResult* result = new TransactResult;
			result->NO = getTaskNo();
			result->m_transactResult = (eTransactResult)nResult;
			resultMsg = result;
		}
		break;

	case gtr::gwsAccountAudit:
		{
			AccountVerifyResult* result = new AccountVerifyResult;
			result->NO = getTaskNo();
			result->Result = nResult;
			result->AccountInfo = encode_logmsg_base64(aux.c_str()) ;
			resultMsg = result;
		}
		break;
	}

	if(resultMsg)
	{
		DISPATCHER.SendToServer(resultMsg, getTaskNo());

		//string key = result->toString();
		//printf("%s",key.c_str());
		Sleep(5000);
	}

}

void Vendor::verifyAnswer(int type,bool succ)
{
	AnswerResult* result = new AnswerResult;
	result->NO = getTaskNo();
	result->UserName = _userName;
	//result->_type = type;
	result->Result = succ ? 1 : 0;

	string log = "VerifyAnswer:[";
	log += result->NO;
	log += "]";
	log += _userName;
	log += succ ? "[1]" : "[0]";
	showlog(log);
	DISPATCHER.SendToServer(result, getTaskNo());
}

/*
*/
void Vendor::startRobot()
{
//	return;
	string dir = "";
	int pos = _vendorInfo.robotPath.find_last_of("\\");
	if(pos != -1)
		dir = _vendorInfo.robotPath.substr(0, pos);

	_start = time(NULL);
	_status = Vendor::Busy;

	SHELLEXECUTEINFO   ShExecInfo   =   {0};  
	ShExecInfo.cbSize   =   sizeof(SHELLEXECUTEINFO);  
	ShExecInfo.fMask   =   SEE_MASK_NOCLOSEPROCESS;  
	ShExecInfo.hwnd   =   NULL;  
	ShExecInfo.lpVerb   =   NULL;  
	ShExecInfo.lpFile   =   _vendorInfo.robotPath.c_str();  
	ShExecInfo.lpParameters   =   NULL;  
	ShExecInfo.lpDirectory   =   dir.c_str();  
	ShExecInfo.nShow   =   SW_SHOW;  
	ShExecInfo.hInstApp   =   NULL;  

	ShellExecuteEx(&ShExecInfo);  
}

string Vendor::getAnswer()
{
	while(_wait_answer)
	{
		Sleep(100);
	}
	return _answer;
}

void Vendor::setAnswer(string answer)
{
	_answer = answer;
	_wait_answer = false;

}
