
#include "dnf_accountaudit.h"

IMPLEMENT_APP_CONSOLE(Dnf_AccountAudit)

const int selectserver_trytimes = 3;
const int selectarea_trytimes = 3;
const int login_trytimes = 1;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

extern std::string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

#define XLOG logmsg

void FormatAreaName( string &area )
{
	static string a[] = { "һ��", "����", "����", "����", "����", "����", "����", "����", "����", "ʮ��", 
		"ʮһ��", "ʮ����", "ʮ����", "ʮ����", "ʮ����", "ʮ����", "ʮ����", "ʮ����", "ʮ����", "��ʮ��" };
	static string b[] = { "1��", "2��", "3��", "4��", "5��", "6��", "7��", "8��", "9��", "10��",
		"11��", "12��", "13��", "14��", "15��", "16��", "17��", "18��", "19��", "20��"};

	for ( int i = sizeof(a)/sizeof(a[0]) - 1; i>=0; --i )
	{
		//area.replace( a[i].c_str(), b[i].c_str() );
	}
}

//void FormatServName( string &serv )
//{
//	wxRegEx reg(wxT("\\d+"));
//	if (reg.Matches(s2ws(serv).c_str()))
//	{
//		wxString s = reg.GetMatch(s2ws(serv),1);
//		serv = s.mb_str();
//	}
//	//serv.remove( QRegExp("\\d+") );
//	//serv.replace( "��","��" );//û�й�������ֻ�й㶫��
//}


void Dnf_AccountAudit::task_AccountAudit(gtr::GameTaskResultT& result)
{
	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("��������Ϊ%s",_tasklet.audit.sellerActor.c_str());
	XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());
	_gamectx.timeout = 100000;
	/*
	Ԥ����Ĭ�ϵķ��ؽ��
	*/
	result.result = GT_ERR_8050;

	/*
	������½��
	*/
	int returnvalue;
	returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if ( returnvalue != GT_OK )
	{
		printf("%d",returnvalue);
		/*
		������Ϸʧ��
		*/
		_gamectx.apilist->End(&_gamectx);
		return;
	}

	/*
	�м�Ĵ������
	*/
	run(&_gamectx,_tasklet,result);

	/*
	�ر���Ϸ
	*/
	_gamectx.apilist->End(&_gamectx);

	logmsg("���ط��������˺���˽��Ϊ%d",(int)result.result);
}

void Dnf_AccountAudit::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	//FormatServName(tasklet.area);
	//XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	int i;
	int returnvalue;

	Sleep(2000);

	/*
	ѡ��������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		//returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.area.c_str()),call);
		returnvalue = call->apilist->SelectServer("�㽭��",call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����
			*/
			logmsg("���Ӵ���ʧ��");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	logmsg("���Ӵ����ɹ�");

	Sleep(2000);

	/*
	ѡС������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_FALSE && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_FALSE && i == selectarea_trytimes - 1 )
		{
			logmsg("С���޷�����");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	logmsg("ѡС���ɹ�");

	Sleep(5000);

	/*
	�˺ŵ�½����
	*/
	for ( i = 0; i < login_trytimes; ++i )
	{
		returnvalue = call->apilist->Login(const_cast<char*>(tasklet.account.c_str()),const_cast<char*>(tasklet.password.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_PASSWORDERROR && i != login_trytimes - 1 )
		{
			continue;
		}
		else if ( returnvalue == GT_PASSWORDERROR && i == login_trytimes - 1 )
		{
			/*
			�����������l
			*/
			taskresult.result = GT_ERR_8010;

			logmsg("�����������");
			return;
		}
		else if ( returnvalue == GT_MBERROR )
		{
			/*
			�����ܱ��ϴ�����
			*/
			taskresult.result = GT_ERR_8040;

			logmsg("�����ܱ��ϴ�����");
			return;
		}
		else if ( returnvalue == GT_VERIFYCODEERROR )
		{
			/*
			����Ա��������
			*/
			taskresult.result = GT_ERR_8040;

			logmsg("��֤�������δ��󣬴���Ա��������");
			return;
		}
		else if ( returnvalue == GT_UNABLECONNECT )
		{
			logmsg("�޷������˺�������֤");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	logmsg("��½�ɹ�");

	/*
	ѡ������
	*/
	returnvalue = call->apilist->SelectLineByName("",call);

	if ( returnvalue != GT_OK )
	{
		logmsg("ѡ��ʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	logmsg("ѡ�߳ɹ�");

	Sleep(2000);

	/*
	ѡ��ɫ����
	*/
	logmsg("ѡ�񶩵��еĽ�ɫ%s��½",tasklet.post.sellerActor.c_str());
	for ( i = 0; i < selectrole_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectRoleByName((char*)_tasklet.audit.sellerActor.c_str(),call);
		if ( returnvalue == GT_OK )
		{
			break;
		}
		else if ( returnvalue == GT_NOTEXISTED && i != selectrole_trytimes -1 )
		{
		}
		else if ( returnvalue == GT_NOTEXISTED && i == selectrole_trytimes -1 )
		{
			logmsg("ѡ��ɫʧ��");

			taskresult.result = GT_ERR_8030;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	logmsg("��ɫ%s��½�ɹ�",tasklet.audit.sellerActor.c_str());

	/*
	��ȡ�˺���Ϣ
	*/

	char* info = NULL;
	int infosize;
	returnvalue = call->apilist->GetAccountInfo(&info,&infosize,call);

	if ( returnvalue == GT_OK )
	{
		AddDNFItemType();
		AddDNFItemProperty();
		accountinfo.parse(info,infosize);
		accountinfo.save();
		std::wstring doc = accountinfo.m_markup.GetDoc();
		taskresult.textval = ws2s(doc);

		taskresult.result = GT_ERR_8000;
	}
	else
	{
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
}

void Dnf_AccountAudit::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		logmsg("��һ������ʧ�ܵ����޷�����");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		logmsg("��һ���������Ҷ���");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		logmsg("��һ��������ʱ");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		logmsg("��һ�����������ж�");
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		logmsg("�������");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		logmsg("��ұ����");
		return;
	}
	else if ( returnvalue == GT_UNABLECONNECT )
	{
		logmsg("��һ���������ش���");
		return;
	}
}

char* Dnf_AccountAudit::core_auth_image(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height)
{
	static std::string secret;
	gtr::QuestionContentT data;

	data.type = ctx->xtype;	
	data.image.type = (int)imagetype;
	data.image.width = width;
	data.image.height = height;
	data.image.bytes.resize(size);
	memcpy(&data.image.bytes[0],imagedata,size);

	try{
		secret = _serverPrx->answer(data);
	}	catch(...){

	}
	return (char*)secret.c_str();
}

void Dnf_AccountAudit::AddDNFItemType()
{
	accountinfo.AddItemType( wxT("����Ʒ") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("Ͷ��Ʒ") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("����װ��") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("ͷ��") );
	accountinfo.AddItemType( wxT("��װ") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("Ь") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("��ָ") );
	accountinfo.AddItemType( wxT("�ƺ�") );
	accountinfo.AddItemType( wxT("����") );
	accountinfo.AddItemType( wxT("װ��") );

	accountinfo.AddItemSpecialType( wxT("����Ʒ") );
	accountinfo.AddItemSpecialType( wxT("����") );
	accountinfo.AddItemSpecialType( wxT("Ͷ��Ʒ") );
	accountinfo.AddItemSpecialType( wxT("����") );
}
void Dnf_AccountAudit::AddDNFItemProperty()
{
	accountinfo.AddItemProperty( wxT("���������"),	wxT("��������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("ħ��������"),	wxT("ħ�������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("��������"),	wxT("�������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("���ӷ�������������"),	wxT("���ӷ������������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("ħ��������"),	wxT("ħ�������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("���ӷ�����ħ��������"),	wxT("���ӷ�����ħ�������� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("����"),		wxT("���� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("����"),		wxT("���� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("����"),		wxT("���� +([^@]+)") );
	accountinfo.AddItemProperty( wxT("����"),		wxT("���� +([^@]+)") );
}