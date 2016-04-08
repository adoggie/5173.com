#pragma once

#include "../idl/gtr_api.h"
#include <vector>
#include <string>
#include <map>
#include "service.h"
#include "gtrmethod.h"
using namespace std;

class GtrChecker
{
public:
	virtual void Do() = 0;
};

class GtrApiWrap
{ 
	CALLCTX* _ctx;
	int _tries;
	int _sleep;
	int _total_timeout;

	GT_RESULT _lastReturn;
	map<string, GtrMethod*> _settings;
	vector<GtrChecker*> _checkers;

	swlib::swLogger	_dbglogger;
	time_t		_tmStart;

	bool isTimeout();

	GT_BOOL Init(char * gamedir );
	void CleanUp( );

	void ParamInit(string name);
	void set_param(string name);
	void begin_core(string name);
	bool end_core(string name);
	string getDebugLogfile();


public:
	GtrApiWrap();
	~GtrApiWrap(void);
	void Initialize(CALLCTX* ctx);

	GT_RESULT SelectServer(string server);						//ѡ����	�����д�����Ϣ	OK	�޷�����					SelectServer		char*
	GT_RESULT SelectArea(string area);							//ѡС��	������С����Ϣ	OK	�޷�����					SelectArea		char*
	// null �Զ�ѡ����·
	GT_RESULT SelectLineByName(string line);		// 		ѡ��·	Pingֵ�ϵ�	OK	�޷�����					SelectLine		void
	// -1 �Զ�ѡ����·
	GT_RESULT SelectLineByIndex(int line);		// 		ѡ��·	Pingֵ�ϵ�	OK	�޷�����					SelectLine		void	
	GT_RESULT Login(string usr,string passwd);	// 		�˺���������	�������˺�������Ϣ	OK	�˺��������	�������		�汾����		Login		char* account, char* pwd
	GT_RESULT IsExistDynMB();									// 		��ѯ��̬�ܱ�		��	��					IsExistDynMB		void	
	GT_RESULT IsRightClass(int );							// 		��ѯ��ɫ��Ӫ	������������Ӫ	��	��					IsRightClass		int	
	GT_RESULT IsExistBackHomeSkill();					// 		��ѯ�سǼ���		��	��					IsExistBackHomeSkill		void
	GT_RESULT UseBackHomeSkill();							// 		ʹ�ûسǼ���		OK	ʧ��					UseBackHomeSkill		void
	GT_RESULT IsExistBackHomeItem();					// 		��ѯ�Ƿ���ڻس���Ʒ		��	��					
	GT_RESULT UseBackHomeItem();							// 		ʹ�ûس���Ʒ		OK	ʧ��						
	GT_RESULT QueryRoleLevel(string role ,POUT int *); // 		��ѯ���ҽ�ɫ�ȼ�		OK	ʧ��					QuerySellerLevel		char*, int*
	GT_RESULT SelectRoleByName(string role);				// 		��ɫѡ��	�����еĽ�ɫ����Ϣ	OK	��ɫ��������	��ɫ��Ҫ�޸����֣�DNF�Ϸ���				SelectRoleByName		char*
	GT_RESULT SelectRoleByIndex(int);					// 		���ѡ��	�����еĽ�ɫ�����Ϣ	OK	�޷���½����Ž�ɫ					SelectRoleByIndex		int
	GT_RESULT IsExistRoleByName(string role );			// 		��ѯ��ҽ�ɫ��	��������ҽ�ɫ����Ϣ	��	��					IsExistBuyerByName		char*
	GT_RESULT AddRoleToFriend(string role);				// 		�����Ϊ����	��������ҽ�ɫ����Ϣ	OK	�޸����					AddBuyerToFriend		char*		
	GT_RESULT QuerySafeTime(POUT int* );						// 		��ȡ��ȫʱ��			��ȫʱ��					QuerySafeTime		int*		
	GT_RESULT IsExistNPC(Gt_NPCID );								// 		�ж�ָ��NPC�Ƿ��ڸ���	NPCID	��	��					IsExistNPC		int	
	GT_RESULT OpenWarehouse(string passwd);						// 		�򿪲ֿ�	�����еĲֿ�������Ϣ	OK	�������					OpenWarehouse		char*
	GT_RESULT OpenMailBox(string passwd);						//����  ��������
	GT_RESULT OpenBank(string passwd);							//���� ��������
	GT_RESULT OpenExchange(string passwd); 					//������ ��������	
	GT_RESULT OpenGrocer(string passwd); 					//�ӻ��� ��������

	GT_RESULT MoveToByNpcID(Gt_NPCID);							// 		�ܵ�ͼ	NPCID	OK	�޷�����					MoveToByNpcID		int NPCID
	GT_RESULT Talk(Gt_NPCID);											// 		������NPC�Ի�	NPCID	OK	�޷��Ի�					Talk		int NPCID
	//��ѯ��Ʒ���� ,  item - �������Ϸ�ɽ��׵Ķ���(��ҡ�Ԫ������ש������)
	GT_RESULT QueryItemsInBag(Gt_GameItemT item,POUT INT64*);				//����
	GT_RESULT QueryItemsInWarehouse(Gt_GameItemT item,POUT INT64*);	//�ֿ�
	GT_RESULT QueryItemsInBank(Gt_GameItemT item,POUT INT64*);				// ����
	GT_RESULT QueryItemsInExchange(Gt_GameItemT item,POUT INT64*);		//������
	//�ʼ���������
	GT_RESULT IsEnoughItemsInMailbox(Gt_GameItemT item,PINOUT INT64*);		// �������Ƿ�������
	//���ָ����Ʒ���� 
	GT_RESULT WithdrawItemsInWarehouse(Gt_GameItemT item,PINOUT INT64*);	// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInBank(Gt_GameItemT item,PINOUT INT64*);				// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInExchange(Gt_GameItemT item,PINOUT INT64*);		// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT WithdrawItemsInMailbox(Gt_GameItemT item,PINOUT  INT64*);		// 		�������Ƿ�������
	//�����ʼ�
	GT_RESULT SendMail(string reciever,string title,string content,INT64);	
	//�һ���Npc
	GT_RESULT SellItem(int item,int itemNum);							// 		�һ���Ʊ����ש	�������		���ضһ���������	�޷���ȡ				SellItem		int64

	//���� ����GT_TRUE����ɹ���GT_FALSEû��ʧ��
	GT_RESULT Transport( int mapid );
	//��ѯ������� ����GT_TRUE���������GT_FALSEû�н���
	GT_RESULT IsUnlocked();
	//��ѯ����Ƿ���ĳĳ��ͼ ����GT_TRUE�����ǣ�GT_FALSE��
	GT_RESULT IsInMap( int mapid );
	//����ѡ���ɫ����
	GT_RESULT ReturnToSelectRole(  );
	//ʹ����·�ű�ר��(��ʱ����2ר��)
	GT_RESULT MoveTo(int type);
	//�ж�NPC�Ƿ�����ҿɵ���Ի���Χ֮��
	GT_RESULT IsNearBy(Gt_NPCID);
	//��ȡ��ɫ��Ϣ ����1������ ����2������
	GT_RESULT GetAccountInfo(char**,int* );
	GT_RESULT GetRoleList(vector<string>& roles);

	GT_RESULT Begin();				//����
	GT_RESULT End();					//�ᵥ


	void addChecker(GtrChecker* checker);
};
