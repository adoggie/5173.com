#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <QtGui>
#include <QPointer>

#include <QMutexLocker>

#include "ui_recognizer.h"

#include "socketmanager.h"
#include "imagemanager.h"
#include "utilitymanager.h"

#include "Windows.h"

class Recognizer : public QMainWindow
{
	Q_OBJECT

public:
	Recognizer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Recognizer();

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
	
	bool  autoRecognize(MbkImage* mbk ); // ×Ô¶¯´ðÌâ 2010.5.27
signals:
	void sendAnswer(QString NO, QString answer, bool isMbk);
private slots:
	void on_connected(SocketManager* sock);
	void on_loginResult(eLoginResult);

	void on_m_online_toggled(bool);
	void on_m_leave_toggled(bool);
	void on_m_saveMBKPositionPix_stateChanged(int);
	void on_m_saveYZMPix_stateChanged(int);
	void on_timer();
	void on_m_logout_clicked();
	void on_m_login_clicked();
	void displayMbkImage(const MbkImage &mbkImage);
	void displayYzmImage(const YzmImage &yzmImage);
	void showMessage(const QString &msg);
	void on_submitPushButton_clicked();
	void currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);
private:
	QString			m_count;
	QString			m_password;
	ImageManager	*pImageManager;
	QTimer			*m_timer;
	eActionState	m_actionState;
	bool			m_startState;
	int				m_beepTimes;

	unsigned int	m_freeDT;
	QSound			m_sound;
	
	QMutex		_mtx_socklist;
	std::vector< QPointer<SocketManager> > _socklist;
};

#endif // RECOGNIZER_H
