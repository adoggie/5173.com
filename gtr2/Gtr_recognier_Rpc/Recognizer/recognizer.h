#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <QtGui>
#include <QPointer>

#include <QMutexLocker>
#include <QThread>

#include "ui_recognizer.h"

//#include "socketmanager.h"
//#include "imagemanager.h"
#include "utilitymanager.h"

#include "Windows.h"

#include "answerServant.h"



 

class Recognizer : public QMainWindow
{
	Q_OBJECT

public:
	Recognizer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Recognizer();
	static Recognizer* instance();
	static Recognizer * __handle;
private:
	enum	eActionState{ LEAVE, ONLINE };

	Ui::RecognizerClass ui;

	void ClearDuplicateItem(QString NO);
	void init();
protected:
	virtual void keyPressEvent(QKeyEvent* e);
	void SetStartState( bool s );
	void SetActionState( eActionState s );
	void escape_answer();
	bool eventFilter(QObject* obj, QEvent *event);
	void setoffline(bool lock = true);
	bool  autoRecognize(QuestionT& q);
	bool sendAnswer(gtr::QuestionResultT result);
signals:
	void sendAnswer(QString NO, QString answer, bool isMbk);
private slots:
//	void on_connected(SocketManager* sock);
//	void on_loginResult(eLoginResult);

//	void on_m_online_toggled(bool);
//	void on_m_leave_toggled(bool);
//	void on_m_saveMBKPositionPix_stateChanged(int);
//	void on_m_saveYZMPix_stateChanged(int);
	void on_timer();
	void on_m_logout_clicked();
	void on_m_login_clicked();

//	void displayMbkImage(const MbkImage &mbkImage);
//	void displayYzmImage(const YzmImage &yzmImage);
	void showMessage(const QString &msg);
	void on_submitPushButton_clicked();
	void currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);
public:	
	void recvQuestion( QuestionT& q); //接收到题目
	
protected:
	class RpcThread:public QThread{
	
public:
		void	run ();
	};
	
public:
	
private:
	QString			m_count;
	QString			m_password;
//	ImageManager	*pImageManager;
	QTimer			*m_timer;
	eActionState	m_actionState;
	bool			m_startState;
	int				m_beepTimes;

	unsigned int	m_freeDT;
	QSound			m_sound;
	
 
	QMutex		_mtx_rpc;
	
	std::vector< QString> _serverconnstrs;								//连接信息
	std::vector<gtr::IQuestionServerPrx> _serverProxies;	//服务器的链接
	
	RpcThread  _rpcThread;
	Ice::CommunicatorPtr _communicator;	
	QStringList _impgames;	//提示的游戏编号 
	bool _autorec;	//自动识别是否开启 
};

#endif // RECOGNIZER_H
