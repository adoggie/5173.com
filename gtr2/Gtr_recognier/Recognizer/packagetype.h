#ifndef PACKAGETYPE_H
#define PACKAGETYPE_H

enum PackageEnum
{
	// Client 2 serter.
	ROBOTSTATUS = 1,		//机器人状态
	YZMIMAGE,				//验证码
	MBKPOSITION,			//密保卡
	VERIFYRESULT,			//验证结果
	TRANSACTRESULT,			//交易结果
	YMCONTENT_RUESULT,		//验证码、密保卡登陆后的结果
	ROBOTEGAMEID,			//当前机器人对应的游戏ID

	// SertER 2 CLIENT.
	VERIFYREQUEST = 10,		//验证请求
	TRANSACTREQUEST,		//交易请求
	YZMCONTENT,				//验证码内容
	MBKCONTENT,				//密保卡内容
	DECRYPTIONKEY,			//解密健

	// SERVER 2 RECOGNIZER.
	YZMINFORMATON = 20,
	MBKINFORMATON,
	LOGINRESULT,

	// RECOGNIZER 2 SERVER.
	YZMRESULT	=	30,
	MBKRESULT	=	31,
	LEAVE		=	32,
	GOBACK		=	33,
	LOGININFO	=	34,
	RECOGNIZERSTATUS = 35,

	//
	ROBOTHEART = 40,
	RECONGIZERHEART = 41,
};

enum eLoginResult
{
	LR_ACCOUNTERR = 0,
	LR_PWDERR,
	LR_ISUSING,
	LR_SUCCESS
};
#endif // PACKAGETYPE_H
