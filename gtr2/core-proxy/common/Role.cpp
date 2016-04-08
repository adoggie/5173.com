#include "Role.h"
#include "service.h"


#define XLOG getRobotApp().logmsg
//#define XLOG appLogger().Message

Role::Role(GtrApiWrap* wrap):_wrap(wrap)
{
	_baglast = 0;
	baggold = 0;
}

Role::~Role(void)
{
}

bool Role::checkBag(int tries)
{
	do
	{
		QueryBag();
		Sleep(1000);
		tries--;

	}while(tries && _baglast == baggold);

	return _baglast != baggold;
}

void Role::BackHome()
{
	int returnvalue;

	/*
	���سǼ���
	*/
	returnvalue = _wrap->IsExistBackHomeSkill();
	if ( returnvalue == GT_TRUE )
	{
		XLOG("��Ҵ��ڻسǼ���");
		/*
		ʹ�ûسǼ���
		*/
		returnvalue = _wrap->UseBackHomeSkill();
		if( returnvalue == GT_TRUE )
		{
			XLOG("���ʹ�ûسǼ��ܳɹ�");
		}
		else
		{
			if(returnvalue == GT_FALSE)
			{
				XLOG("���ʹ�ûسǼ���ʧ��");
				/*
				ʹ�ûس���Ʒ
				*/
				BackHomeAux();
			}
			else
			{
				throw(make_error( returnvalue));
			}
		}
	}
	else
	{
#if 0
		if(returnvalue == GT_FALSE)
		{
			XLOG("��Ҳ����ڻسǼ���");
			/*
			ʹ�ûس���Ʒ
			*/
			BackHomeAux();
		}
		else
		{
			throw(make_error( returnvalue));
		}
#else
		XLOG("��Ҳ����ڻسǼ���");
		throw(make_error( returnvalue));

#endif
	}
}

void Role::BackHomeAux()
{
	int returnvalue;
	/*
	���سǵ���
	*/
	returnvalue = _wrap->IsExistBackHomeItem();
	if ( returnvalue == GT_TRUE )
	{
		XLOG("��ɫ���ڻس���Ʒ");
		/*
		ʹ�ûسǵ���
		*/
		returnvalue = _wrap->UseBackHomeItem();
		if ( returnvalue == GT_TRUE )
		{
			XLOG("��ɫʹ�ûس���Ʒ�ɹ�");
		}
		else if ( returnvalue == GT_FALSE )
		{
			XLOG("��ɫʹ�ûس���Ʒʧ��");
			throw(robot_error(GT_ERR_3120, "�س�ʧ��"));
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
	else
	{
		if ( returnvalue == GT_FALSE )
		{
			XLOG("��ɫ�����ڻس���Ʒ");
			throw(robot_error(GT_ERR_3120, "�س�ʧ��"));
		}
		else
		{
			throw(make_error( returnvalue));
		}
	}
}

void Role::Login(gtr::GameTaskletT& tasklet)
{
	int returnvalue;

	/*
	ѡ��������
	*/
	returnvalue = _wrap->SelectArea(tasklet.area); 
	if ( returnvalue == GT_OK )
	{
		XLOG("���Ӵ����ɹ�");
	}
	else
	{
		if ( returnvalue == GT_UNABLECONNECT)
		{
			/*
			����ֵ�����޷�����,ת�˹�
			*/
			throw(robot_error(GT_ERR_3000, "���Ӵ���ʧ��"));
		}
		else
		{

			throw(make_error(returnvalue));		
		}

	}

	/*
	ѡС������
	*/
	returnvalue = _wrap->SelectServer(tasklet.server);
	if ( returnvalue == GT_OK )
	{
		XLOG("����С���ɹ�");
	}
	else 
	{
		if ( returnvalue == GT_UNABLECONNECT)
		{
			/*
			����ֵС���޷�����,ת�˹�
			*/
			throw(robot_error(GT_ERR_3020,"����С��ʧ��"));
		}
		else if( returnvalue == GT_NOTEXISTED )
		{
			throw(robot_error(GT_ERR_3020, "С��������"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	/*
	�˺ŵ�½����
	*/
	returnvalue = _wrap->Login(tasklet.account,tasklet.password);

	if ( returnvalue == GT_OK )
		XLOG("�˺ŵ�½�ɹ�");
	else
	{
		if ( returnvalue == GT_PASSWORDERROR)
		{
			/*
			�����������
			*/
			throw(robot_error(GT_ERR_2000,"�����������"));
		}
		else if ( returnvalue == GT_MBERROR)
		{
			/*
			�����ܱ��ϴ�����
			*/
			throw(robot_error(GT_ERR_2090,"�����ܱ��ϴ�����"));
		}
		else if ( returnvalue == GT_VERSIONERROR )
		{
			/*
			��Ϸ�汾����
			*/
			throw(robot_error(GT_ERR_3120, "��Ϸ�汾����"));
		}
		else if ( returnvalue == GT_PLAYERINLINE )
		{
			/*
			�������
			*/
			throw(robot_error(GT_ERR_3120, "�������"));
		}
		else if ( returnvalue == GT_FALSE)
		{
			throw(robot_error(GT_ERR_3120, "��Ϸ������û�����߿������ܱ������δ����˺ű���ʱ��ͣ"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}

	/*
	ѡ������
	*/
	returnvalue = _wrap->SelectLineByName("");
	//returnvalue = _wrap->SelectLineByName("12");
	//returnvalue = _wrap->SelectLineByIndex(12); 
	if ( returnvalue != GT_OK )
	{
		XLOG("ѡ��ʧ��");

		throw(make_error(returnvalue));		
	}
	XLOG("ѡ����·�ɹ�");

	/*
	�����޽�ɫ��ֱ��ȡ����������ʾ���޽�ɫ����
	������һ����ɫ����ɫ��ƥ�䣬ֱ���ߺ������̣�
	������һ����ɫ����ɫ����ƥ�䣬����㹻������
	������һ����ɫ����ɫ����ƥ�䣬��Ҳ��㣬ֱ��ȡ����������ʾ����ɫ����ƥ�䣬�ҽ�������㣩��
	���������ɫ�����н�ɫ��ƥ�䣬ֱ���ߺ������̣� ע����ɫ��ƥ��󣬲��Ը��˺�������ɫ����������жϣ���
	���������ɫ�����޽�ɫ��ƥ�䣬ֱ��ת�˹�����ʾ����ɫ����ƥ�䣩��
	*/
	_seller = tasklet.post.sellerActor;

#if 1
	vector<string> roles;
	returnvalue = _wrap->GetRoleList(roles);
	if( returnvalue == GT_OK )
	{
		XLOG("�ʺŽ�ɫ����Ϊ%d", roles.size());
		for(int i=0; i<roles.size(); i++)
		{
			XLOG("�ʺŽ�ɫ%d: %s", i+1, roles[i].c_str());
		}

		if(roles.size()==0)
		{
			//�޽�ɫ��ֱ��ȡ����������ʾ���޽�ɫ��
			throw(robot_error(GT_ERR_2010, "�ʺ����޽�ɫ"));
		}
		else if(roles.size()==1)
		{
			if(roles[0]==_seller)
			{
				//��ɫ��ƥ�䣬ֱ���ߺ�������
			}
			else
			{
				//��ɫ����ƥ�䣬�����㹻�򷢻��� ����ֱ��ȡ����������ʾ����ɫ����ƥ�䣬�ҽ�������㣩
				//throw(robot_error(GT_ERR_2140, "��ɫ����ƥ�䣬�ҽ��������"));
				XLOG("�ʺ���ֻ��һ����ɫ,���ǽ�ɫ����ƥ��,ѡ��Ψһ��ɫ");
				_seller = roles[0];
			}
		}
		else
		{
			//extern void _debug_loop();
			//_debug_loop();
			vector<string>::iterator itbegin = roles.begin();
			vector<string>::iterator itend = roles.end();
			vector<string>::iterator itfind = itbegin;

			for(; itfind != itend; itfind++)
			{
				string pp = (*itfind);
				if(strcmp(pp.c_str(), _seller.c_str())==0)
					break;
			}


			//vector<string>::iterator itfind = std::find(roles.begin(), roles.end(), _seller);
			if(itfind != roles.end())
			{
				//�н�ɫ��ƥ�䣬ֱ���ߺ������̣� ע����ɫ��ƥ��󣬲��Ը��˺�������ɫ����������жϣ�
			}
			else
			{
				//�޽�ɫ��ƥ�䣬ֱ��ת�˹�
				throw(robot_error(GT_ERR_3130, "�ʺ����ж����ɫ,���ǽ�ɫ����ƥ��"));
			}
		}
	}
	else
	{
		//�޽�ɫ��ֱ��ȡ����������ʾ���޽�ɫ��
		throw(robot_error(GT_ERR_2010, "��ɫ�б��ѯʧ��, ��ɫ�б�Ϊ��"));
	}
#endif

	/*
	ѡ��ɫ����
	*/
	returnvalue = _wrap->SelectRoleByName(_seller); 
	if ( returnvalue == GT_OK )
	{
		XLOG("ѡ���ɫ%s��½�ɹ�",_seller.c_str());
	}
	else
	{
		// �жϽ�ɫ�б��Ƿ�Ϊ�գ� ��ֱ�ӳ����� ���ֲ�ƥ��ת�˹�
		if ( returnvalue == GT_NOTEXISTED)
		{
			XLOG("��¼��ɫ%sʧ��",_seller.c_str());
			throw(robot_error(GT_ERR_2010, "ѡ��ɫʧ��"));
		}
		else
		{
			throw(make_error(returnvalue));		
		}
	}
}

void Role::QueryLevel()
{
	int returnvalue;

	do 
	{
		returnvalue = _wrap->QueryRoleLevel(_seller, &_level);
		if(returnvalue == GT_TRUE )
		{
			XLOG("��ɫ��ǰ�ȼ�%d��", _level);
			Sleep(500);
		}
		else
		{
			Sleep(500);
			//throw(make_error(returnvalue));
		}
	} while (_level == 0);

}

void Role::QuerySafeTime(int max)
{
	int returnvalue;
	
	/*
	��ȫʱ����
	*/
	int safetime = 0;
	_wrap->QuerySafeTime(&safetime); 
	if ( safetime > max )
	{
		/*
		����ֵ��ȫʱ�����2����,ת�˹�
		*/
		char buf[255];
		sprintf(buf, "��ȫʱ��%d����(����%d����)", safetime, max);
		throw(robot_error(GT_ERR_3030,buf));
	}

	XLOG("��ȫʱ����ɹ�,��ȫʱ��%d����", safetime);

}

void Role::QueryBag()
{
	static int queryid = 0;

	_baglast = baggold;

	queryid++;
	int returnvalue = _wrap->QueryItemsInBag((Gt_GameItemT)GT_ITEM_1,&baggold);
	if ( returnvalue != GT_OK )
	{
		XLOG("��ѯ�������ʧ��");
		baggold = _baglast;
		throw(make_error(returnvalue));

	}

	XLOG("��%d�β�ѯ�������Ϊ%d",queryid, (int)baggold);
}

bool Role::IsNearByNpc(int npc)
{
	int returnvalue = _wrap->IsNearBy(npc);
	if ( returnvalue != GT_OK && returnvalue != GT_FALSE )
	{
		throw(make_error( returnvalue));
	}

	return returnvalue==GT_TRUE ? true : false;
}