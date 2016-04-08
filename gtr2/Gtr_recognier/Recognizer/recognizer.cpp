#include "recognizer.h"
#include "InterFace.h"

Recognizer::Recognizer(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags),m_sound(QCoreApplication::applicationDirPath() + "\\sound.wav")
{
	ui.setupUi(this);
	ui.answerLineEdit->installEventFilter(this);
	//SocketManager &socketManager = SocketManager::GetInstance();
	//////////////////////////////////////////////////////////////////////////
	init();
	int n;
	for(n=0;n<_socklist.size();n++){
	//connect(this, SIGNAL(sendAnswer(const QString &, const QString &, const bool &)), &socketManager, SLOT(sendAnswer(const QString &, const QString &, const bool &)));
		connect(_socklist[n], SIGNAL(displayMbkImage(const MbkImage &)), this, SLOT(displayMbkImage(const MbkImage &)));
		connect(_socklist[n], SIGNAL(displayYzmImage(const YzmImage &)), this, SLOT(displayYzmImage(const YzmImage &)));
		connect(_socklist[n], SIGNAL(showMessage(const QString &)), this, SLOT(showMessage(const QString &)));
		connect(_socklist[n], SIGNAL(connected(SocketManager*)), this, SLOT(on_connected(SocketManager*)));
		connect(_socklist[n], SIGNAL(loginResult(eLoginResult)), this, SLOT(on_loginResult(eLoginResult)));
	}
	//////////////////////////////////////////////////////////////////////////
	pImageManager = &ImageManager::GetInstance();

	connect(ui.treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)), this, SLOT(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)));

	ui.treeWidget->setColumnWidth(0, 200);
	ui.treeWidget->setColumnWidth(1, 50);
	ui.treeWidget->setColumnWidth(2, 150);

	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timer()));

	SetStartState(false);
	m_actionState = ONLINE;
}

void Recognizer::init(){
	QString path = QCoreApplication::applicationDirPath();
	QString s = path+tr("\\Setting.ini");
	QSettings settings(s, QSettings::IniFormat);
	s =  settings.value("Server/addr").toString();
	QStringList hosts = s.split("%");
	
	for(int n= 0; n<hosts.size();n++){
		QStringList item;
		item = hosts[n].trimmed().split(":");
		if(item.size()!=2){
			continue;
		}
		SocketManager* mgr = new SocketManager();
		QString host;
		int port;
		settings.setArrayIndex(n);
		host  = item[0].trimmed();
		port = item[1].trimmed().toInt();
		mgr->init(host,port);
		_socklist.push_back(mgr);
	}
	
}



void Recognizer::SetStartState( bool s )
{
	m_startState = s;
	ui.m_login->setEnabled(!m_startState);
	ui.m_logout->setEnabled(m_startState);
	ui.m_count->setEnabled( !m_startState );
	ui.m_password->setEnabled( !m_startState );
}
void Recognizer::SetActionState( eActionState s )
{
	switch ( s )
	{
	case LEAVE:
		{
			ui.m_leave->setChecked( true );
			break;
		}
	case ONLINE:
		{
			ui.m_online->setChecked( true );
			break;
		}
	}
}
void Recognizer::on_timer()
{
	QMutexLocker locker(&_mtx_socklist);
	if( m_actionState==ONLINE )
	{	
		//SocketManager::GetInstance().initNet();
		for(int n=0;n<_socklist.size();n++){
			_socklist[n]->initNet();
		}

		unsigned int ct = timeGetTime();

		ImageManager &ims = ImageManager::GetInstance();
		if( ims.YzmNumber()!=0 || ims.MbkNumber()!=0 )
		{
			if( m_beepTimes==0 )
				m_sound.play();
			++m_beepTimes;
			if( m_beepTimes>3 )
				m_beepTimes = 0;

			m_freeDT = 0;
		}
		else
		{ //没有任务发送心跳消息
			
//////////////////////////////////////////////////////////////////////////
// 			if( SocketManager::GetInstance().isLogin() )
// 			{
// 				if( (ct - m_freeDT)>1000 )
// 				{
// 					SocketManager::GetInstance().SendGetTaskPacket();
// 					m_freeDT = ct;
// 				}
// 			}
//////////////////////////////////////////////////////////////////////////
// 			if( (ct-m_freeDT)>1000){
// 				for(int n=0;n<_socklist.size();n++){
// 					if(_socklist[n]->isLogin()){
// 						_socklist[n]->SendGetTaskPacket();
// 					}
// 				}
// 				m_freeDT = ct;
// 			}
			//////////////////////////////////////////////////////////////////////////			
		}
	}
}

Recognizer::~Recognizer()
{

}

void Recognizer::on_submitPushButton_clicked()
{
	if(ui.answerLineEdit->text().isEmpty())
	{
		QMessageBox::information(this,tr("提示"),tr("请输入答案。"));
		return;
	}

	QTreeWidgetItem *item=ui.treeWidget->currentItem();
	SocketManager * socket;
	
	if(item!=NULL)
	{
		QString NO=item->text(0);
		QString type=item->text(1);
		QString result=ui.answerLineEdit->text().trimmed();
		socket = (SocketManager *)item->data(0,Qt::UserRole).toUInt();
		
		if(type == "密保卡")
		{
			if( !result.isEmpty() && result.length()!=6)
			{//长度为空的时候也要发，服务器会主动丢弃这一单
				QMessageBox::information(this,tr("提示"),tr("请输入正确的长度。"));
				return;
			}

			//emit sendAnswer(NO,ui.answerLineEdit->text(),true);
			socket->sendAnswer(NO,ui.answerLineEdit->text(),true);
			
			pImageManager->DeleteMbkImage(NO);
		}
		else
		{
			if(result.length()<4)
			{
				QMessageBox::information(this,tr("提示"),tr("请输入正确的长度。"));
				return;
			}

			//emit sendAnswer(NO,ui.answerLineEdit->text(),false);
			socket->sendAnswer(NO,ui.answerLineEdit->text(),false);
			pImageManager->DeleteYzmImage(NO);
		}

		ui.logTextEdit->append(tr("单号：%1   答案：%2   类型：%3   时间：%4").arg(NO).arg(ui.answerLineEdit->text()).arg(type).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		delete item;
		ui.answerLineEdit->clear();
	}
}


void Recognizer::ClearDuplicateItem(QString NO)
{
	for(int i=0;i<ui.treeWidget->topLevelItemCount();i++)
	{
		QTreeWidgetItem *treeWidgetItem = ui.treeWidget->topLevelItem(i);

		if(treeWidgetItem->text(0)==NO)
		{
			delete treeWidgetItem;
		}

	}
}
void SavePix( const QByteArray &data, const QString &pathName )
{
	QString pix_path = QCoreApplication::applicationDirPath()+pathName;
	QDir dir;
	if( !dir.exists(pix_path) )
		dir.mkpath( pix_path );

	//为了简单，图片的命名就用当前时间，重名也没关系，大不了覆盖一副图片
	QString name = QString("%1.jpeg").arg(timeGetTime());
	QFile file( name );
	if( file.open( QIODevice::WriteOnly ) ){
		file.write( data );
		Sleep(1);//睡1ms，降低重名的概率（答题器的效率不在程序部分，睡一下没关系）
	}
}

void Recognizer::displayMbkImage(const MbkImage &mbkImage)
{
	ClearDuplicateItem(mbkImage.NO);

	QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(ui.treeWidget);
	treeWidgetItem->setText(0, tr("%1").arg(mbkImage.NO));
	treeWidgetItem->setText(1, tr("密保卡"));
	treeWidgetItem->setText(2, tr("%1").arg(mbkImage.CreateTime.toString("yyyy-MM-dd hh:mm:ss")));
	treeWidgetItem->setData(0,Qt::UserRole,(int)mbkImage.socket);
	
	pImageManager->AddMbkImage(mbkImage);
	if( ui.m_saveMBKPositionPix->checkState()==Qt::Checked )
		SavePix( mbkImage.positionPixData, "/mbk" );
	

	// Set default select item.
	if(ui.treeWidget->currentItem() == NULL)
	{
		//currentItemChanged(treeWidgetItem,NULL);
		ui.treeWidget->setCurrentItem(treeWidgetItem);
	}

	m_beepTimes = 0;
}

void Recognizer::displayYzmImage(const YzmImage &yzmImage)
{
	ClearDuplicateItem(yzmImage.NO);

	QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(ui.treeWidget);
	treeWidgetItem->setText(0, tr("%1").arg(yzmImage.NO));
	treeWidgetItem->setText(1, tr("验证码"));
	treeWidgetItem->setText(2, tr("%1").arg(yzmImage.CreateTime.toString("yyyy-MM-dd hh:mm:ss")));
	treeWidgetItem->setData(0,Qt::UserRole,(int)yzmImage.socket);
	
	pImageManager->AddYzmImage(yzmImage);
	if( ui.m_saveYZMPix->checkState()==Qt::Checked )
		SavePix( yzmImage.pixData, "/yzm" );

	// Set default select item.
	if(ui.treeWidget->currentItem() == NULL)
	{
		//currentItemChanged(treeWidgetItem,NULL);
		ui.treeWidget->setCurrentItem(treeWidgetItem);
	}


	ui.submitPushButton->setDisabled(false);
	ui.answerLineEdit->setFocus();

	m_beepTimes = 0;
}


void Recognizer::showMessage(const QString &msg)
{
	ui.statusBar->showMessage(msg);
}



bool  Recognizer::autoRecognize(MbkImage* mbk ){

	TGetCardDataByCoordinate metrix={};
	std::string  text;
	TGetCoordinateTable tabel={};
	char recvbuff[128];
	HRESULT cr;
	
	TPicBuffInfo picbuffinfo;
	
	int type =1;
	if(mbk->positionPixData.size() < 16){ // 图片+文本
		type = 2;
		text.assign(mbk->positionPixData.data(),mbk->positionPixData.data()+mbk->positionPixData.size());
	}

	
	if(type == 1 ){
		//识别坐标图片
		picbuffinfo.cPicBuff =(char*)mbk->Position.bits();
		picbuffinfo.dwPicBuffLen = mbk->Position.byteCount();
		tabel.PicInfo = &picbuffinfo;

		tabel.cRelBuff = recvbuff;
		tabel.dwRelBuffLen = sizeof(recvbuff);		
		tabel.iType = (int)mbk->gameId; //atoi(q.content.gameId.c_str());	
		cr = g_AUTOPICAPI.GetCoordinateTable(&tabel);
		if( cr==S_OK){
			text.assign(tabel.cRelBuff,tabel.dwRelBuffLen);
		}		
	}

//识别矩阵		
	picbuffinfo.cPicBuff = (char*)mbk->Image.bits();
	picbuffinfo.dwPicBuffLen = mbk->Image.byteCount();
	metrix.PicInfo = &picbuffinfo;

	metrix.cCoordinateBuff = (char*)text.c_str();
	metrix.dwCoordinateBuffLen = text.size();
	metrix.cRelBuff = recvbuff;
	metrix.iType = (int)mbk->gameId; //atoi(q.content.gameId.c_str());
	cr = g_AUTOPICAPI.GetCardDataByCoordinate(&metrix);
	std::string result;
	if( cr == S_OK){
		result.assign(metrix.cRelBuff,metrix.cRelBuff+ text.size());
		PGetLinePic regpic =g_AUTOPICAPI.GetLinePicBuff();
		if(regpic){
			QImage image;
			image = QImage::fromData((uchar*)regpic->cPicBuff,(int)regpic->dwPicBuffLen);
			ui.imageLabel->setPixmap(QPixmap::fromImage(image));
		}
		
	}else{
		ui.imageLabel->setPixmap(QPixmap::fromImage(mbk->Image));		
	}
	ui.positionLabel->setPixmap(QPixmap::fromImage(mbk->Position));
	ui.answerLineEdit->setText(QString::fromStdString(result));
// 		FILE * fp = fopen("c:/test-image.txt","wb");
// 		fwrite(&q.content.image.bytes[0],q.content.image.bytes.size(),1,fp);
// 		fclose(fp);

	return false;

}


void Recognizer::currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
	if(current!=NULL)
	{
		QString NO=current->text(0);
		QString type=current->text(1);

		if(type == "密保卡")
		{
			MbkImage *pMbkImage = pImageManager->GetMbkImage(NO);
			if(pMbkImage != NULL)
			{
				autoRecognize(pMbkImage);
				//ui.imageLabel->setPixmap(QPixmap::fromImage(pMbkImage->Image));
				//ui.positionLabel->setPixmap(QPixmap::fromImage(pMbkImage->Position));
			}
		}
		else
		{
			YzmImage *pYzmImage = pImageManager->GetYzmImage(NO);
			if(pYzmImage != NULL)
			{
				ui.imageLabel->setPixmap(NULL);
				ui.positionLabel->setPixmap(QPixmap::fromImage(pYzmImage->Image));
			}
		}

		ui.submitPushButton->setDisabled(false);
		ui.answerLineEdit->setFocus();
	}
	else
	{
		ui.imageLabel->setPixmap(NULL);
		ui.positionLabel->setPixmap(NULL);
		ui.submitPushButton->setDisabled(true);
		
	}
}


void Recognizer::keyPressEvent(QKeyEvent* e){
	if(e->key()==Qt::Key_Escape){
		escape_answer()	;	
	}else if(e->key()==Qt::Key_Return || e->key()==Qt::Key_Enter){
		on_submitPushButton_clicked();
	}
}


bool Recognizer::eventFilter(QObject* obj, QEvent *event){
	if (obj == ui.answerLineEdit){
		if (event->type() == QEvent::KeyPress){
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
			if (keyEvent->key() == Qt::Key_Space){
				on_submitPushButton_clicked();
				return true;
			}
		}		
	}
	return QObject::eventFilter(obj, event);
//	return Recognizer::eventFilter(obj, event);
}

void Recognizer::escape_answer(){
	
	QTreeWidgetItem *item=ui.treeWidget->currentItem();
	SocketManager * socket;
	
	ui.answerLineEdit->clear();
	if(item!=NULL){
		QString NO=item->text(0);
		QString type=item->text(1);
		QString result=ui.answerLineEdit->text().trimmed();
		socket = (SocketManager *)item->data(0,Qt::UserRole).toUInt();
		bool isMbk = false;
		if(type == "密保卡")
		{
			isMbk = true;
			}
		socket->sendAnswer(NO,ui.answerLineEdit->text(),isMbk);
		pImageManager->DeleteYzmImage(NO);	
		//ui.logTextEdit->append(tr("单号：%1   答案：%2   类型：%3   时间：%4").arg(NO).arg(ui.answerLineEdit->text()).arg(type).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		delete item;		
	}
}


void Recognizer::on_m_login_clicked()
{
	SetStartState( true );
	m_timer->start(1000);
	ui.m_online->setChecked(true);
	on_timer();
//	m_actionState=ONLINE;
}

void Recognizer::on_m_logout_clicked()
{
	SetStartState( false );
	m_timer->stop();
	
	//SocketManager::GetInstance().closeNet();
	QMutexLocker l(&_mtx_socklist);
	for(int n=0;n<_socklist.size();n++){
		_socklist[n]->SendGetTaskPacket();
		//_socklist[n]->SendLeavePacket();
		_socklist[n]->closeNet();
	}
	//m_actionState = LEAVE;
}

void Recognizer::on_m_saveYZMPix_stateChanged(int)
{
	
}

void Recognizer::on_m_saveMBKPositionPix_stateChanged(int)
{
	
}

void Recognizer::on_m_leave_toggled(bool t)
{
QMutexLocker l(&_mtx_socklist);
	if( t )
	{
		m_actionState = LEAVE;
// 		if( SocketManager::GetInstance().isLogin() )
// 			SocketManager::GetInstance().SendLeavePacket();
		for(int n=0;n<_socklist.size();n++){
			if(_socklist[n]->isLogin()){
				_socklist[n]->SendLeavePacket();
			}
		}
		
	}	
}

void Recognizer::on_m_online_toggled(bool t)
{
	if( t )
	{
		m_actionState = ONLINE;
// 		if( SocketManager::GetInstance().isLogin() )
// 			SocketManager::GetInstance().SendGoBackpacket();
		QMutexLocker l(&_mtx_socklist);
		for(int n=0;n<_socklist.size();n++){
			if( _socklist[n]->isLogin()){
				_socklist[n]->SendGoBackpacket();
			}
		}
	}
	
}

//必须处理多个socket链接情况 
void Recognizer::on_connected(SocketManager* sock)
{
	QString account = ui.m_count->currentText().trimmed();
	QString pwd = ui.m_password->text().trimmed();
	//SocketManager::GetInstance().SendLoginInfoPacket( account, pwd );
	sock->SendLoginInfoPacket(account,pwd);
	showMessage("登陆中,等待...");
}


void Recognizer::on_loginResult(eLoginResult r)
{
	switch( r )
	{
	case LR_ACCOUNTERR:
		{
			on_m_logout_clicked();
			showMessage("账号错误：该账号没有注册。");
			break;
		}
	case LR_PWDERR:
		{
			on_m_logout_clicked();
			showMessage("密码错误。");
			break;
		}
	case LR_ISUSING:
		{
			on_m_logout_clicked();
			showMessage("账号正在使用。");
			break;
		}
	case LR_SUCCESS:
		{
			showMessage("登陆成功。");
			break;
		}
	default:
		{
			on_m_logout_clicked();
			showMessage("错误的登陆结果。");
			break;
		}
	}
}