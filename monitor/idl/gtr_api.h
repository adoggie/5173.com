/*
gtr_api.h
========================
��������Ϸ�߼������Ľӿ�
2009.12.12 zhangbin  created
	1. �޸Ķ�����ͼƬ�Ĵ��䷽ʽ��ͨ��context���
	2. ��������ӿ� init()/cleanup(),��������ͨ���ڲ��Ǽ���ʵ��
2009.12.13 zhangbin
	1.�����־�ص�

2010.3.25 zhangbin 
	1.��� auth() �ܱ���֤�ص�;captureImage()ץ��Ļ�ص�
	3.��� Gt_CallContext.id�ֶ�
2010.3.29 zhangbin
1.�������������Ĵ���

2010.4.6 zhangbin 
1. ����Gt_ReturnValueT����ֵ
2. ͨ��GetProcAddress��̬��ȡgame dll�Ľӿ�,������Ϸdll������� Gt_CallContext.apilist
3. ���� auth_result�ص�

*/


#ifndef _GT_API_H
#define _GT_API_H
#include <windows.h>


enum Gt_ReturnValueT{	
	GT_FALSE=0,									//��
	GT_TRUE=1,									//��
	GT_UNABLECONNECT=2,							//�޷�����
	GT_PASSWORDERROR=3,							//�˺��������
	GT_PLAYERINLINE=4,							//�������
	GT_VERSIONERROR=5,							//�汾����
	GT_UNABLEGETINFO=6,							//�޷����
	GT_VERIFYCODEERROR=7,						//��֤�����
	GT_ROLELOCK=8,								//��ɫ����
	GT_MBERROR=9,								//�ܱ�������
	GT_ROLENEEDCHANGENAME=10,					//��ɫ��Ҫ�޸����֣�DNF�Ϸ���
	GT_ROLEKICK=11,								//��ɫ��������
	GT_SECONDPWDERROR=12,						//����������ֿ߲��������
	GT_UNABLEMOVETO=13,							//�޷�����
	GT_UNABLETALKTO=14,							//�޷��Ի�
	GT_TIMEOUT=15,								//��ʱ
	GT_PlAYERNOFEE=16,							//������Ϸ�㿨����
	GT_CONNECTBREAK=17,							//�����ж�
	GT_NOTEXISTED=18,							//���ʶ��󲻴��� 2010.3.27
	GT_SKIP_PASS=19,							//�˵��������жϣ�ֱ�Ӻ���
	GT_OK = GT_TRUE,							//�ɹ�
	GT_MAIlBOXFULL=20,							//��������
	GT_MAIlBOXLOCKED=21,						//(��һ�����)���䶳��
	GT_UNKNOWN=0xffff
};

typedef int		GT_BOOL;
#define POUT
#define PIN
#define PINOUT

typedef Gt_ReturnValueT GT_RESULT;
typedef int Gt_NPCID;

enum Gt_ImageTypeT{
	GT_IMAGEJPEG =1,
	GT_IMAGEPNG,
	GT_IMAGEBMP
};

enum Gt_GameItemT{
	GT_ITEM_1,		//���
	GT_ITEM_2,		//��ש
	GT_ITEM_MAX
};

struct Gt_ApiList;

typedef struct Gt_CallContext{
	int			timeout	;			// msec ���ó�ʱ
	void*		cookie;				// �ⲿʹ��
	void*		cookie2;			// ��Ϸ�ڲ�ʹ��,�����ڱ���״̬
	char*		xdata;				// ���ݽ�����ַ,���ݱ������̸���
	int			xsize;				// ���ݽ�����С
	int			xtype;				// ������������
	Gt_ApiList*		apilist;	//������ڱ� ��Ϸdll�ڲ�ά�ֽӿڱ��ڳ�ʼ��ʱ��ֵ���˱���
	 void	 (__stdcall *log)  (Gt_CallContext* ctx,char* msg);						//��Ϸ�߼�����ʱ��־���
	void  (__stdcall *log2)(Gt_CallContext* ctx,char* data,int size); //��Ϸ�߼�����ʱ��־���	
	char* (__stdcall *auth_coords)(Gt_CallContext* ctx,char* coords); //������֤
	char* (__stdcall *auth_image)(Gt_CallContext* ctx,Gt_ImageTypeT imagetype,char* imagedata,int size,int width,int height);
	void 	(__stdcall *capture_image)(Gt_CallContext* ctx,char* excName,char* imagedata,int size,int width,int height);	
	int		id;		//��Ϸ�߼�ʹ��	
	int  (__stdcall *auth_result)(Gt_CallContext* ctx,int succ) ;  //������֤������ر���������ȷ���(succ: 0 - ����; 1 - ��ȷ)�����ڴ���Ա����( type : 1 - �ܱ��� ; 2 - ��֤�� )
	
}CALLCTX;


struct Gt_ApiList{	
	GT_RESULT (__stdcall *SelectServer)(char *,CALLCTX*);						//ѡ����	�����д�����Ϣ	OK	�޷�����					SelectServer		char*
	GT_RESULT (__stdcall *SelectArea)(char*,CALLCTX*);							//ѡС��	������С����Ϣ	OK	�޷�����					SelectArea		char*
	// null �Զ�ѡ����·
	GT_RESULT (__stdcall *SelectLineByName)(char* line,CALLCTX*);		// 		ѡ��·	Pingֵ�ϵ�	OK	�޷�����					SelectLine		void
	// -1 �Զ�ѡ����·
	GT_RESULT (__stdcall *SelectLineByIndex)(int line,CALLCTX*);		// 		ѡ��·	Pingֵ�ϵ�	OK	�޷�����					SelectLine		void	
	GT_RESULT (__stdcall *Login)(char* usr,char* passwd,CALLCTX*);	// 		�˺���������	�������˺�������Ϣ	OK	�˺��������	�������		�汾����		Login		char* account, char* pwd
	GT_RESULT (__stdcall *IsExistDynMB)(CALLCTX*);									// 		��ѯ��̬�ܱ�		��	��					IsExistDynMB		void	
	GT_RESULT (__stdcall *IsRightClass)(int,CALLCTX* );							// 		��ѯ��ɫ��Ӫ	������������Ӫ	��	��					IsRightClass		int	
	GT_RESULT (__stdcall *IsExistBackHomeSkill)(CALLCTX*);					// 		��ѯ�سǼ���		��	��					IsExistBackHomeSkill		void
	GT_RESULT (__stdcall *UseBackHomeSkill)(CALLCTX*);							// 		ʹ�ûسǼ���		OK	ʧ��					UseBackHomeSkill		void
	GT_RESULT (__stdcall *IsExistBackHomeItem)(CALLCTX*);					// 		��ѯ�Ƿ���ڻس���Ʒ		��	��					
	GT_RESULT (__stdcall *UseBackHomeItem)(CALLCTX*);							// 		ʹ�ûس���Ʒ		OK	ʧ��						
	GT_RESULT (__stdcall *QueryRoleLevel)(char* ,POUT int *,CALLCTX*); // 		��ѯ���ҽ�ɫ�ȼ�		OK	ʧ��					QuerySellerLevel		char*, int*
	GT_RESULT (__stdcall *SelectRoleByName)(char*,CALLCTX*);				// 		��ɫѡ��	�����еĽ�ɫ����Ϣ	OK	��ɫ��������	��ɫ��Ҫ�޸����֣�DNF�Ϸ���				SelectRoleByName		char*
	GT_RESULT (__stdcall *SelectRoleByIndex)(int,CALLCTX*);					// 		���ѡ��	�����еĽ�ɫ�����Ϣ	OK	�޷���½����Ž�ɫ					SelectRoleByIndex		int
	GT_RESULT (__stdcall *IsExistRoleByName)(char* ,CALLCTX*);			// 		��ѯ��ҽ�ɫ��	��������ҽ�ɫ����Ϣ	��	��					IsExistBuyerByName		char*
	GT_RESULT (__stdcall *AddRoleToFriend)(char*,CALLCTX*);				// 		�����Ϊ����	��������ҽ�ɫ����Ϣ	OK	�޸����					AddBuyerToFriend		char*		
	GT_RESULT (__stdcall *QuerySafeTime)(POUT int* ,CALLCTX*);						// 		��ȡ��ȫʱ��			��ȫʱ��					QuerySafeTime		int*		
	GT_RESULT (__stdcall *IsExistNPC)(Gt_NPCID ,CALLCTX*);								// 		�ж�ָ��NPC�Ƿ��ڸ���	NPCID	��	��					IsExistNPC		int	
	GT_RESULT (__stdcall *OpenWarehouse)(char* passwd,CALLCTX*);						// 		�򿪲ֿ�	�����еĲֿ�������Ϣ	OK	�������					OpenWarehouse		char*
	GT_RESULT (__stdcall *OpenMailBox)(char* passwd,CALLCTX*);						//����  ��������
	GT_RESULT (__stdcall *OpenBank)(char* passwd,CALLCTX*);							//���� ��������
	GT_RESULT (__stdcall *OpenExchange)(char* passwd,CALLCTX*); 					//������ ��������	
	GT_RESULT (__stdcall *OpenGrocer)(char* passwd,CALLCTX*); 					//�ӻ��� ��������
	
	GT_RESULT (__stdcall *MoveToByNpcID)(Gt_NPCID,CALLCTX*);							// 		�ܵ�ͼ	NPCID	OK	�޷�����					MoveToByNpcID		int NPCID
	GT_RESULT (__stdcall *Talk)(Gt_NPCID,CALLCTX*);											// 		������NPC�Ի�	NPCID	OK	�޷��Ի�					Talk		int NPCID
	//��ѯ��Ʒ���� ,  item - �������Ϸ�ɽ��׵Ķ���(��ҡ�Ԫ������ש������)
	GT_RESULT (__stdcall *QueryItemsInBag)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				//����
	GT_RESULT (__stdcall *QueryItemsInWarehouse)(Gt_GameItemT item,POUT INT64*,CALLCTX*);	//�ֿ�
	GT_RESULT (__stdcall *QueryItemsInBank)(Gt_GameItemT item,POUT INT64*,CALLCTX*);				// ����
	GT_RESULT (__stdcall *QueryItemsInExchange)(Gt_GameItemT item,POUT INT64*,CALLCTX*);		//������
	//�ʼ���������
	GT_RESULT (__stdcall *IsEnoughItemsInMailbox)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);		// �������Ƿ�������
	//���ָ����Ʒ���� 
	GT_RESULT (__stdcall *WithdrawItemsInWarehouse)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);	// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInBank)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);				// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInExchange)(Gt_GameItemT item,PINOUT INT64*,CALLCTX*);		// 		��ȡ�ֿ�����Ϣ			���زֿ��н������	�޷���ȡ				QueryGoldsInWarehouse		int64*
	GT_RESULT (__stdcall *WithdrawItemsInMailbox)(Gt_GameItemT item,PINOUT  INT64*,CALLCTX*);		// 		�������Ƿ�������
	//�����ʼ�
	GT_RESULT (__stdcall *SendMail)(char* reciever,char* title,char* content,INT64,CALLCTX*);	
	//�һ���Npc
	GT_RESULT (__stdcall *SellItem)(int item,int itemNum,CALLCTX*);							// 		�һ���Ʊ����ש	�������		���ضһ���������	�޷���ȡ				SellItem		int64

	//���� ����GT_TRUE����ɹ���GT_FALSEû��ʧ��
	GT_RESULT (__stdcall *Transport)( int mapid, CALLCTX* );
	//��ѯ������� ����GT_TRUE���������GT_FALSEû�н���
	GT_RESULT (__stdcall *IsUnlocked)(CALLCTX*);
	//��ѯ����Ƿ���ĳĳ��ͼ ����GT_TRUE�����ǣ�GT_FALSE��
	GT_RESULT (__stdcall *IsInMap)( int mapid, CALLCTX* );

	GT_RESULT (__stdcall *ReturnToSelectRole)( CALLCTX* );

	GT_RESULT (__stdcall *MoveTo)(int type, CALLCTX *ctx);

	GT_RESULT (__stdcall *IsNearBy)(Gt_NPCID, CALLCTX *ctx);

	GT_RESULT (__stdcall *Begin)(CALLCTX*);				//����
	GT_RESULT (__stdcall *End)(CALLCTX*);					//�ᵥ
	GT_BOOL (__stdcall *Init)(char * gamedir,CALLCTX* ctx);
	void		(__stdcall *CleanUp)(CALLCTX* ctx);
};


//////////////////////////////////////////////////////////////////////////
//������
// -- --- ------  ����״̬ -- --- ------ 
#define GT_ERR_1000 1000	//���׳ɹ�
#define GT_ERR_2000	2000	//�˺��������
#define GT_ERR_2010	2010	//�޽�ɫ
#define GT_ERR_2020	2020	//�ֿ���������������
#define GT_ERR_2030	2030	//���㷢�����
#define GT_ERR_2040	2040	//���������Ӫ
#define GT_ERR_2050	2050	//����ɫ������
#define GT_ERR_2060	2060	//���ҵȼ�����
#define GT_ERR_2070	2070	//���ҽ������
#define GT_ERR_2080	2080	//���������
#define GT_ERR_2090	2090	//�ܱ��ϴ���������ϵ�У�
#define GT_ERR_3000	3000	//�����޷�����
#define GT_ERR_3010	3010	//��̬�ܱ�ֱ��ת�˹�
#define GT_ERR_3020	3020	//С���޷�����
#define GT_ERR_3030	3030	//��ȫʱ�����5����
#define GT_ERR_3040	3040	//��ǰ��ͼ����ָ������NPC�ǳ�
#define GT_ERR_3050	3050	//������������
#define GT_ERR_3060	3060	//�ʼĴ������ޣ�DNF��
#define GT_ERR_3070	3070	//���������
#define GT_ERR_3080	3080	//��ҵȼ�������DNF��
#define GT_ERR_3090	3090	//���ұ������ˣ��ֿ��������޷�ȡ�ʼ���DNF��
#define GT_ERR_3100	3100	//���Һ���Ϸ��������
#define GT_ERR_3110	3110	//���Ұ󶨾�̬�ܱ�δ�ϴ���
#define GT_ERR_3120	3120	//���ֲ��ɿ����ص��µĳ�ʱ��(����)
//-- --- ------ ���״̬ -- --- ------ 
#define GT_ERR_4000	4000	//�˺��������
#define GT_ERR_4010	4010	//��ɫ�޷���½���޽�ɫ��
#define GT_ERR_4020	4020	//�ֿ��������
#define GT_ERR_4030	4030	//���㷢�����
#define GT_ERR_4040	4040	//�ܱ�������
#define GT_ERR_4050	4050	//���ҵȼ�����
#define GT_ERR_4060	4060	//���Һ���Ϸ��������
#define GT_ERR_5000	5000	//��̬�ܱ�ֱ��ת�˹�
#define GT_ERR_5010	5010	//�����޷����ӣ�������ά����������ʱ�������
#define GT_ERR_5020	5020	//�ܱ�������
#define GT_ERR_5030	5030	//С���޷�����
#define GT_ERR_5040	5040	//��ǰ��ͼ����ָ������NPC�ǳ�
#define GT_ERR_5050	5050	//������������
#define GT_ERR_5060	5060	//���ֲ��ɿ����ص��µĳ�ʱ��(����)
#define GT_ERR_5070	5070	//��˳ɹ�




#endif