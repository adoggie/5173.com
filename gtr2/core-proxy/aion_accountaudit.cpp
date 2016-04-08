
#include "aion_accountaudit.h"

extern string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

IMPLEMENT_APP_CONSOLE(Aion_AccountAudit)

const int selectserver_trytimes = 3;
const int selectarea_trytimes = 3;
const int login_trytimes = 1;
const int inputmb_trytimes = 3;
const int selectrole_trytimes = 3;

//#define XLOG logmsg
#define XLOG getLogger().Debug

void Aion_AccountAudit::task_AccountAudit(gtr::GameTaskResultT& result)
{
	XLOG("������Ϊ%s",(char*)_tasklet.no.c_str());
	XLOG("��������Ϊ%s",_tasklet.audit.sellerActor.c_str());
	XLOG("�����д�����ϢΪ%s",_tasklet.area.c_str());
	XLOG("������С����ϢΪ%s",_tasklet.server.c_str());
	XLOG("�������˺���ϢΪ%s",_tasklet.account.c_str());

	_gamectx.timeout = 60000;
	/*
	Ԥ����Ĭ�ϵķ��ؽ��
	*/
	result.result = GT_ERR_8050;

	/*
	�м�Ĵ������
	*/
	run(&_gamectx,_tasklet,result);

	XLOG("����End�ӿ�");
	/*
	�ر���Ϸ
	*/
	_gamectx.apilist->End(&_gamectx);

	XLOG("���ط��������˺���˽��Ϊ%d",(int)result.result);
}

void Aion_AccountAudit::run(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int i;
	int returnvalue;

	/*
	ѡ��������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectServer(const_cast<char*>(tasklet.area.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectserver_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectserver_trytimes - 1 )
		{
			/*
			����ֵ�����޷�����
			*/
			XLOG("���Ӵ���ʧ��");
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("���Ӵ����ɹ�");

	/*
	������½��
	*/
	returnvalue = _gamectx.apilist->Begin(&_gamectx);
	if ( returnvalue != GT_OK )
	{
		XLOG("������Ϸʧ��");
		/*
		������Ϸʧ��
		*/
		_gamectx.apilist->End(&_gamectx);
		return;
	}

	XLOG("������Ϸ�ɹ�");

	Sleep(6000);

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
			�����������
			*/
			taskresult.result = GT_ERR_8010;

			XLOG("�����������");
			return;
		}
		else if ( returnvalue == GT_DYNAMICMB )
		{
			/*
			��̬�ܱ����ֻ��ܱ�ת�˹�
			*/
			taskresult.result = GT_ERR_8040;

			XLOG("��̬�ܱ����ֻ��ܱ�ת�˹�");
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("��½�ɹ�");


	/*
	ѡС������
	*/
	for ( i = 0; i < selectarea_trytimes; ++i )
	{
		returnvalue = call->apilist->SelectArea(const_cast<char*>(tasklet.server.c_str()),call);
		if ( returnvalue == GT_OK )
			break;
		else if ( returnvalue == GT_UNABLECONNECT && i != selectarea_trytimes - 1 )
			continue;
		else if ( returnvalue == GT_UNABLECONNECT && i == selectarea_trytimes - 1 )
		{
			XLOG("С���޷�����");
			return;
		}
		else
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return;
		}
	}

	XLOG("ѡС���ɹ�");

	Sleep(2000);

	/*
	ѡ��ɫ����
	*/
	XLOG("ѡ�񶩵��еĽ�ɫ%s��½",tasklet.audit.sellerActor.c_str());
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
			XLOG("ѡ��ɫʧ��");

			taskresult.result = GT_ERR_8030;
			return;
		}
		else
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
	}

	XLOG("��ɫ%s��½�ɹ�",tasklet.post.sellerActor.c_str());

	/*
	����Ҫ�سǷ�
	*/

	returnvalue = call->apilist->IsNeedBackHome(call);

	if ( returnvalue == GT_OK )
	{
		XLOG("��Ҫʹ�ûس�");
		if (backhomeItemprocess(call,tasklet,taskresult)==false)
			return;
	}
	else if( returnvalue == GT_FALSE )
	{
		XLOG("����Ҫʹ�ûس�");
	}
	else
	{
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}

	/*
	��ȡ�������·��
	*/
	int npclist[16] = {0};
	int size = 16;
	int* begin = npclist;
	returnvalue = call->apilist->GetBestNPC(begin,&size,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ȡ���·��ʧ��");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	for ( int i = 0; i < size; ++i )
	{
		int npctype = *(begin + i);

		XLOG("��%d��������%d",i + 1, npctype);

		XLOG("��ʼ�ƶ���%d��NPC", npctype);
		call->timeout = 180000;
		returnvalue = call->apilist->MoveToByNpcID(npctype,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		call->timeout = 60000;
		XLOG("�ƶ���%d��NPC�ɹ�", npctype);
		XLOG("��ʼ�Ի�%d��NPC", npctype);
		returnvalue = call->apilist->Talk(npctype,call);
		if ( returnvalue != GT_OK )
		{
			checkReturnvalueprocess(returnvalue,taskresult);
			return;
		}
		XLOG("�Ի�%d��NPC�ɹ�", npctype);

		switch (npctype)
		{
		case AION_NPC_FLY:
		case AION_NPC_TRANSPORT:
			{
				XLOG("��ʼʹ��%d��NPC�Ĵ��ͺͷ��й���", npctype);
				call->timeout = 120000;
				returnvalue = call->apilist->Transport(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("���ͻ��߷��гɹ�");
			}
			break;
		case AION_NPC_MAILBOX:
			{
				XLOG("��ʼ������");
				returnvalue = call->apilist->OpenMailBox("",call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("������ɹ�");
				XLOG("����������Ʒ��Ϣ��ʼ");
				call->timeout = 180000;
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("����������Ʒ��Ϣ�ɹ�");
			}
			break;
		case AION_NPC_WAREHOUSE:
			{
				XLOG("��ʼ�򿪲ֿ�");
				returnvalue = call->apilist->OpenWarehouse((char*)_tasklet.audit.sellerSecondPwd.c_str(),call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("�򿪲ֿ�ɹ�");
				XLOG("��ʼ����ֿ���Ʒ��Ϣ");
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("����ֿ���Ʒ��Ϣ�ɹ�");
			}
			break;
		case AION_NPC_EXCHANGE:
			{
				XLOG("��ʼ�򿪽�����");
				returnvalue = call->apilist->OpenExchange("",call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("�򿪽������ɹ�");
				XLOG("��ʼ���潻������Ʒ��Ϣ");
				returnvalue = call->apilist->SaveItemInfo(npctype,call);
				if ( returnvalue != GT_OK )
				{
					checkReturnvalueprocess(returnvalue,taskresult);
					return;
				}
				XLOG("���潻������Ʒ��Ϣ�ɹ�");
			}
			break;
		default:
			assert(0);
		}
	}

	call->timeout = 60000;

	XLOG("���汳����������Ʒ��Ϣ��ʼ");
	/*
	�����ɫ����,������Ʒ��Ϣ��
	*/
	returnvalue = call->apilist->SaveItemInfo(AION_SELF,call);
	if ( returnvalue != GT_OK )
	{
		XLOG("���汳����������Ʒ��Ϣʧ��");
		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
	XLOG("���汳����������Ʒ��Ϣ�ɹ�");

	XLOG("��ʼ��ȡ��ɫ�˺���Ϣ");

	/*
	��ȡ�˺���Ϣ
	*/

	char* info = NULL;
	int infosize;
	returnvalue = call->apilist->GetAccountInfo(&info,&infosize,call);

	if ( returnvalue == GT_OK )
	{
		XLOG("��ȡ��ɫ�˺���Ϣ�ɹ�");

		AddAionItemType();
		AddAionItemProperty();
		accountinfo.parse(info,infosize);
		accountinfo.save();
		std::wstring doc = accountinfo.m_markup.GetDoc();
		taskresult.textval = ws2s(doc);

		taskresult.result = GT_ERR_8000;
	}
	else
	{
		XLOG("��ȡ��ɫ�˺���Ϣʧ��");

		checkReturnvalueprocess(returnvalue,taskresult);
		return;
	}
}

void Aion_AccountAudit::checkReturnvalueprocess( int returnvalue, gtr::GameTaskResultT& taskresult )
{
	if ( returnvalue == GT_OK )
	{
		return;
	}
	else if ( returnvalue == GT_FALSE )
	{
		XLOG("��һ������ʧ�ܵ����޷�����");
		return;
	}
	else if ( returnvalue == GT_ROLEKICK )
	{
		XLOG("��һ���������Ҷ���");
		return;
	}
	else if ( returnvalue == GT_TIMEOUT )
	{
		XLOG("��һ��������ʱ");
		return;
	}
	else if ( returnvalue == GT_CONNECTBREAK )
	{
		XLOG("��һ�����������ж�");
		return;
	}
	else if ( returnvalue == GT_PLAYERINLINE )
	{
		XLOG("�������");
		return;
	}
	else if ( returnvalue == GT_ROLELOCK )
	{
		XLOG("��ұ����");
		return;
	}
	else if ( returnvalue == GT_UNABLEMOVETO )
	{
		XLOG("�޷�����Ŀ�ĵ�");
		return;
	}
	else if ( returnvalue == GT_UNABLETALKTO )
	{
		XLOG("�޷��Ի�NPC");
		return;
	}
	else
	{
		XLOG("δ֪�ķ���ֵ%d",returnvalue);
		return;
	}
}

bool Aion_AccountAudit::backhomeSkillprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���سǼ���
	*/
	returnvalue = call->apilist->IsExistBackHomeSkill(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("��Ҵ��ڻسǼ���");
		returnvalue = call->apilist->UseBackHomeSkill(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("���ʹ�ûسǼ��ܳɹ�");
			return true;
		}
		else
		{
			XLOG("���ʹ�ûسǼ���ʧ��");
			return false;
		}
	}
	else
	{
		XLOG("��Ҳ����ڻسǼ���");
		return false;
	}
}
bool Aion_AccountAudit::backhomeItemprocess(CALLCTX* call,gtr::GameTaskletT& tasklet,gtr::GameTaskResultT& taskresult)
{
	int returnvalue;
	/*
	���س���Ʒ
	*/
	returnvalue = call->apilist->IsExistBackHomeItem(call);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		checkReturnvalueprocess( returnvalue , taskresult);
		return false;
	}
	else if ( returnvalue == GT_TRUE )
	{
		XLOG("��Ҵ��ڻس���Ʒ");
		returnvalue = call->apilist->UseBackHomeItem(call);
		if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
		{
			checkReturnvalueprocess( returnvalue , taskresult);
			return false;
		}
		else if( returnvalue == GT_TRUE )
		{
			XLOG("���ʹ�ûس���Ʒ�ɹ�");
			return true;
		}
		else
		{
			XLOG("���ʹ�ûس���Ʒʧ��");
			if (backhomeSkillprocess(call,tasklet,taskresult))
				return true;
			else
				return false;
		}
	}
	else
	{
		XLOG("��Ҳ����ڻس���Ʒ");
		if (backhomeSkillprocess(call,tasklet,taskresult))
			return true;
		else
			return false;
	}
}

void Aion_AccountAudit::AddAionItemType()
{
	accountinfo.AddItemType( wxT("����Ʒ") );

	accountinfo.AddItemSpecialType( wxT("����Ʒ") );
}
void Aion_AccountAudit::AddAionItemProperty()
{
	accountinfo.AddItemProperty( wxT("���������"),	wxT("��������� +([^@]+)") );
}