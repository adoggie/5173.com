#ifndef _GTR_MESSAGE_H
#define _GTR_MESSAGE_H

#include "gtr_base.h"


//包标记
enum GtMessageType{
	// Client 2 server.
	ROBOTSTATUS = 1,			//机器人状态
	YZMIMAGE,					//验证码
	MBKPOSITION,				//密保卡
	VERIFYRESULT,				//验证结果
	TRANSACTRESULT,				//交易结果
	YMCONTENT_RUESULT,			//验证码、密保卡登陆后的结果
	ROBOTEGAMEID,				//当前机器人对应的游戏ID
	ACCOUNTRESULT,				//账号验证结果

	// SERVER 2 CLIENT.
	VERIFYREQUEST = 10,		//验证请求
	TRANSACTREQUEST,		//交易请求
	YZMCONTENT,				//验证码内容
	MBKCONTENT,				//密保卡内容
	DECRYPTIONKEY,			//解密健
	ACCOUNTVERIFYREQUEST,	//账号验证请求

	// SERVER 2 RECOGNIZER.
	YZMINFORMATON = 20,
	MBKINFORMATON,

	// RECOGNIZER 2 SERVER.
	YZMRESULT = 30,
	MBKRESULT,
	//
	ROBOTHEART = 40,
};

//机器人状态
enum eRebotStatus{
	RS_FREE,
	RS_UNKNOW,
	RS_VERIFY,
	RS_TRANSACT,
};

//验证状态
enum eVerifyResult{
	VR_VERIFYSUCCESS = 10,				//成功
	VR_ACCOUNTERROR,					//账号或密码错误
	VR_ACTORUNAVAILABLE,				//账号名字错误
	VR_LEVELERROR,						//角色等级错误
	VR_MONEYERROR,						//金币错误
	VR_UNKNOW,							//未知错误
	VR_NEEDSHMB = 17,					//需要手机密保
	VR_NEEDDTMB,						//需要动态密保
};

enum eTransactResult
{
	TR_TRANSACTSUCCESS = 1,				//交易成功
	TR_MANUALHANDLE,					//人工处理
	TR_BUYERCANCEL,						//买家取消
	TR_SELLERCANCEL,					//卖家取消
	TR_UNKNOW
};

enum eYMContentResult
{
	YMR_VERIFYCODEERROT,			//验证码错误
	YMR_MBKCODEERROR,				//密保卡错误
};


class GtMessageBase{
public:	
	GtMessageBase(){}
	virtual ~GtMessageBase(){}
	virtual GtMessageType	getType() = 0;								//获取包类型
	virtual GtStreamBytes	encBytes()									//序列成字节流
	{
		GtStreamBytes gtstr;
		return gtstr;
	}
	virtual bool parse(GtByte* data,GtUInt32 size){return true;}		//解析字节流到结构
	virtual GtUInt32 getSize(){return 0;}								//计算序列成字节的大小
	virtual std::string toString() = 0;
protected:
	GtMessageType	_type;
};





#endif

