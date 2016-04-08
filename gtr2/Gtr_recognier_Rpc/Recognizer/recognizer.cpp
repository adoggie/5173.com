

/*
2010.5.24 scott
1.����Զ�ʶ��
2.��Ϸ�����ʾ

*/

#include "recognizer.h"
#include "InterFace.h"


Recognizer::Recognizer(QWidget *parent, Qt::WFlags flags)
:_mtx_rpc(QMutex::Recursive), QMainWindow(parent, flags),m_sound(QCoreApplication::applicationDirPath() + "\\sound.wav")
{
	__handle = this;
	ui.setupUi(this);
	//////////////////////////////////////////////////////////////////////////
	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timer()));
	m_timer->setInterval(1000*2);
	
	init();
	//////////////////////////////////////////////////////////////////////////
//	connect(AnswerServer::instance(),SIGNAL(addQuestion( QuestionT& )),this,SLOT(recvQuestion( QuestionT& )));
	

	//////////////////////////////////////////////////////////////////////////
	connect(ui.treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)), this, SLOT(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)));

	ui.treeWidget->setColumnWidth(0, 200);
	ui.treeWidget->setColumnWidth(1, 50);
	ui.treeWidget->setColumnWidth(2, 150);


	
	//SetStartState(false);
	m_actionState = ONLINE;
	
	ui.answerLineEdit->installEventFilter(this);
}

void Recognizer::init(){
	QString path = QCoreApplication::applicationDirPath();
	QString s = path+tr("\\Setting.ini");
	QSettings settings(s, QSettings::IniFormat);
	//////////////////////////////////////////////////////////////////////////
	//s =  settings.value("Server/impgames").toString();
	//int  i = settings.value("Server/autorec").toInt();
	s =  settings.value("Server/addr").toString();
	QStringList hosts = s.split("%");
	
	for(int n= 0; n<hosts.size();n++){
		QStringList item;
		item = hosts[n].trimmed().split(":");
		if(item.size()!=2){
			continue;
		}		
		//settings.setArrayIndex(n);
		QString connstr("GtrServerAnswer:tcp -h %1 -p %2");
		connstr = connstr.arg(item[0].trimmed()).arg(item[1].trimmed());
		_serverconnstrs.push_back(connstr);
	}
	//////////////////////////////////////////////////////////////////////////
	_impgames =  settings.value("Server/impgames").toStringList();
	 //= s.split(",");
	//////////////////////////////////////////////////////////////////////////
	_autorec = settings.value("Server/autorec").toInt()?true:false;
	//////////////////////////////////////////////////////////////////////////
	HRESULT r =InitExportFunc(NULL);
	//Recognizer::instance()->_communicator = Ice::initialize(argc, argv);
	//Ice::ObjectAdapterPtr adapter = Recognizer::instance()->_communicator->createObjectAdapter("answeradapter");
	//Ice::ObjectAdapterPtr adapter = Recognizer::instance()->_communicator->createObjectAdapterWithEndpoints("answeradapter","tcp -p 10099");
	//answeradapter
	
	_rpcThread.start();
	setoffline();
}


void Recognizer::on_timer(){
//����������
	if( !ui.m_login->isEnabled() && ui.m_online->isChecked()){
		;
	}else{return;}
	
	QMutexLocker l(&_mtx_rpc);
	gtr::IQuestionServerPrx prx;
	size_t n;
	gtr::CallReturnT cr;
	for(n=0;n<_serverProxies.size();n++){
		try{
			prx = _serverProxies[n]->ice_timeout(1000*3);
			prx->heartbeat("answerEndpoint","undefined");
		}catch(std::exception& e){
			std::string what = e.what();
			QMessageBox::warning(this,tr("����"),QString(tr("���ӷ�����ʧ��:%1")).arg(_serverconnstrs[n]));
			setoffline();
			return ;
		}
	}
}

// bool Recognizer::sendAnswer(gtr::QuestionResultT result){
// 	gtr::QuestionResultT qrst;
// 	qrst.value = ui.answerLineEdit->text().trimmed().toStdString();
// 	qrst.cookie = q->content.cookie;
// 	try{		
// 		q->server->answerResult(q->no,qrst);
// 		AnswerServer::instance()->shiftQuestion(q->no);
// 	}catch(...){
// 		return false;
// 	}
// 	return true;
// }

bool  Recognizer::autoRecognize(QuestionT& q){
	if( !_autorec ){
		return false;
	}

	TGetCardDataByCoordinate metrix={};
	std::string  text;
	TGetCoordinateTable tabel={};
	char recvbuff[128];
	HRESULT cr;
	gtr::QuestionResultT qrst;
	TPicBuffInfo picbuffinfo;
	
	if(q.content.type == 3){
		//tabel.PicInfo->cPicBuff =(char*)&q.content.image.bytes[0];
		//tabel.PicInfo->dwPicBuffLen = q.content.image.bytes.size();
		picbuffinfo.cPicBuff =(char*)&q.content.image.bytes[0];
		picbuffinfo.dwPicBuffLen = q.content.image.bytes.size();
		tabel.PicInfo = &picbuffinfo;
		tabel.cRelBuff = recvbuff;
		tabel.dwRelBuffLen = sizeof(recvbuff);		
		tabel.iType = atoi(q.content.gameId.c_str());
		cr = g_AUTOPICAPI.GetCoordinateTable(&tabel);
		if(cr == S_OK){
			qrst.value.assign(tabel.cRelBuff,tabel.dwRelBuffLen);
			qrst.cookie = q.content.cookie;
			try{		
				q.server->answerResult(q.no,qrst);
				AnswerServer::instance()->shiftQuestion(q.no);				
			}catch(...){
				return false;
			}
			return true;
		}
	}else{
		text = q.content.text;
		if(q.content.type == 1 ){
			//tabel.PicInfo->cPicBuff =(char*)&q.content.image2.bytes[0];
			//tabel.PicInfo->dwPicBuffLen = q.content.image2.bytes.size();
			
			picbuffinfo.cPicBuff =(char*)&q.content.image2.bytes[0];
			picbuffinfo.dwPicBuffLen = q.content.image2.bytes.size();
			tabel.PicInfo = &picbuffinfo;
			
			tabel.cRelBuff = recvbuff;
			tabel.dwRelBuffLen = sizeof(recvbuff);		
			tabel.iType = atoi(q.content.gameId.c_str());	
			cr = g_AUTOPICAPI.GetCoordinateTable(&tabel);
			if( cr!=S_OK){
				return false;
			}
			text.assign(tabel.cRelBuff,tabel.dwRelBuffLen);
		}
		//ʶ�����
		//metrix.PicInfo->cPicBuff = (char*)&q.content.image.bytes[0];
		//metrix.PicInfo->dwPicBuffLen = q.content.image.bytes.size();
		
		picbuffinfo.cPicBuff = (char*)&q.content.image.bytes[0];
		picbuffinfo.dwPicBuffLen = q.content.image.bytes.size();
		metrix.PicInfo = &picbuffinfo;
		
		metrix.cCoordinateBuff = (char*)text.c_str();
		metrix.dwCoordinateBuffLen = text.size();
		metrix.cRelBuff = recvbuff;
		metrix.iType = atoi(q.content.gameId.c_str());
		cr = g_AUTOPICAPI.GetCardDataByCoordinate(&metrix);
		if( cr == S_OK){
			qrst.value.assign(metrix.cRelBuff,text.c_str());
			qrst.cookie = q.content.cookie;
			try{		
				q.server->answerResult(q.no,qrst);
				AnswerServer::instance()->shiftQuestion(q.no);				
			}catch(...){
				return false;
			}
			return true;
		}
		FILE * fp = fopen("c:/test-image.txt","wb");
		fwrite(&q.content.image.bytes[0],q.content.image.bytes.size(),1,fp);
		fclose(fp);
	}
	return false;

}

void Recognizer::recvQuestion( QuestionT& q){
	QPixmap pixmap;	
	if( q.content.image2.bytes.size()==0 && q.content.type == 1){
		QMessageBox::warning(this,"����","�ܱ�������1������ͼƬΪ�գ��Ƿ�!");
		return;
	}
	if(q.content.image.bytes.size()){
		pixmap.loadFromData(&q.content.image.bytes[0],q.content.image.bytes.size());		
		q.image = pixmap.toImage();	
	}
	if(q.content.image2.bytes.size()){
		pixmap.loadFromData(&q.content.image2.bytes[0],q.content.image2.bytes.size());		
		q.image2 = pixmap.toImage();
	}
	//////////////////////////////////////////////////////////////////////////
	//�Զ�ʶ��
	if( autoRecognize(q)) return;
	//////////////////////////////////////////////////////////////////////////
	if(q.content.type == 2){
		if( q.content.text.size()==6 ){
			pixmap = QPixmap( 126, 50 );
			pixmap.fill();
			QPainter painter(&pixmap);
			painter.setFont( QFont("����", 24) );
			QRect rect( 0, 0, pixmap.width(), pixmap.height() );
			painter.drawText( rect, Qt::AlignCenter, QString(q.content.text.c_str()) );
			q.image2 = pixmap.toImage();
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//ClearDuplicateItem(mbkImage.NO);
	QString pathName;
	QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(ui.treeWidget);
	treeWidgetItem->setText(0, tr("%1").arg(QString::fromStdString(q.no)));
	if( q.content.type == 1 ||q.content.type==2){
		treeWidgetItem->setText(1, tr("�ܱ���"));
		pathName = "/mbk";
	}else{
		treeWidgetItem->setText(1, tr("��֤��"));
		pathName = "/yzm";
	}
	//treeWidgetItem->setText(2, tr("%1").arg(mbkImage.CreateTime.toString("yyyy-MM-dd hh:mm:ss")));
	treeWidgetItem->setText(2, tr("%1").arg(QDateTime::currentDateTime().toString()));
	treeWidgetItem->setData(0,Qt::UserRole,(int)&q);

	//pImageManager->AddMbkImage(mbkImage);
	
	
	//if( ui.m_saveMBKPositionPix->checkState()==Qt::Checked ){
	if(1){
		//SavePix( mbkImage.positionPixData, "/mbk" );				
		QString pix_path = QCoreApplication::applicationDirPath()+pathName;
		QDir dir;
		if( !dir.exists(pix_path) )
			dir.mkpath( pix_path );
// 		QString name = QString("%1.jpeg").arg(timeGetTime());
// 		QFile file( name );
// 		if( file.open( QIODevice::WriteOnly ) ){
// 			file.write( data );
// 			Sleep(1);//˯1ms�����������ĸ��ʣ���������Ч�ʲ��ڳ��򲿷֣�˯һ��û��ϵ��
// 		}		
	}


	// Set default select item.
	if(ui.treeWidget->currentItem() == NULL)
	{
		//currentItemChanged(treeWidgetItem,NULL);
		ui.treeWidget->setCurrentItem(treeWidgetItem);
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

Recognizer::~Recognizer()
{

}

void Recognizer::on_submitPushButton_clicked()
{
	if(ui.answerLineEdit->text().isEmpty())
	{
		QMessageBox::information(this,tr("��ʾ"),tr("������𰸡�"));
		return;
	}

	QTreeWidgetItem *item=ui.treeWidget->currentItem();
	
	if(!item){
		return;
	}
	QuestionT * q = (QuestionT*)(int)item->data(0,Qt::UserRole).toInt();	
	QString NO(q->no.c_str());
	QString type=item->text(1);
	QString result=ui.answerLineEdit->text().trimmed();		
	
	if(type == "�ܱ���"){
		if( !result.isEmpty() && result.length()!=6){//����Ϊ�յ�ʱ��ҲҪ����������������������һ��
			QMessageBox::information(this,tr("��ʾ"),tr("��������ȷ�ĳ��ȡ�"));
			return;
		}			
	}else{
		if(result.length()!=4){
			QMessageBox::information(this,tr("��ʾ"),tr("��������ȷ�ĳ��ȡ�"));
			return;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//���͸�������
	QMutexLocker l(&_mtx_rpc);
	
	
	gtr::QuestionResultT qrst;
	qrst.value = ui.answerLineEdit->text().trimmed().toStdString();
	qrst.cookie = q->content.cookie;
	try{		
		q->server->answerResult(q->no,qrst);
		AnswerServer::instance()->shiftQuestion(q->no);
	}catch(...){}
	
	ui.logTextEdit->append(tr("���ţ�%1   �𰸣�%2   ���ͣ�%3   ʱ�䣺%4").arg(NO).arg(ui.answerLineEdit->text()).arg(type).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
	delete item;
	ui.answerLineEdit->clear();
	
	 
}

void Recognizer::setoffline(bool lock){
	QMutexLocker l(&_mtx_rpc);
	m_timer->stop();
	SetStartState( false );
	_serverProxies.clear();
	showMessage(tr("δ���ӵ�������!"));
}


void Recognizer::ClearDuplicateItem(QString NO){
	for(int i=0;i<ui.treeWidget->topLevelItemCount();i++){
		QTreeWidgetItem *treeWidgetItem = ui.treeWidget->topLevelItem(i);
		if(treeWidgetItem->text(0)==NO){
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

	//Ϊ�˼򵥣�ͼƬ���������õ�ǰʱ�䣬����Ҳû��ϵ�����˸���һ��ͼƬ
	QString name = QString("%1.jpeg").arg(timeGetTime());
	QFile file( name );
	if( file.open( QIODevice::WriteOnly ) ){
		file.write( data );
		Sleep(1);//˯1ms�����������ĸ��ʣ���������Ч�ʲ��ڳ��򲿷֣�˯һ��û��ϵ��
	}
}



void Recognizer::showMessage(const QString &msg)
{
	ui.statusBar->showMessage(msg);
}

void Recognizer::currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous){
	if(current!=NULL){
		QString NO=current->text(0);
		QString type=current->text(1);
		QuestionT *q;
		q = (QuestionT *) (int)current->data(0,Qt::UserRole).toInt();
		if(q->content.type == 1 || q->content.type==2){
				ui.imageLabel->setPixmap(QPixmap::fromImage(q->image));
				ui.positionLabel->setPixmap(QPixmap::fromImage(q->image2));							
		}else{ // - 3			
				ui.imageLabel->setPixmap(NULL);
				ui.positionLabel->setPixmap(QPixmap::fromImage(q->image2));			 
		}

		ui.submitPushButton->setDisabled(false);
		ui.answerLineEdit->setFocus();
	}else{
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
//	SocketManager * socket;

	ui.answerLineEdit->clear();
	
	if(item!=NULL){
		QString NO=item->text(0);
		QString type=item->text(1);
		QString result=ui.answerLineEdit->text().trimmed();
		QMutexLocker l(&_mtx_rpc);


		gtr::QuestionResultT qrst;
		QuestionT * q = (QuestionT*)(int)item->data(0,Qt::UserRole).toInt();	
		qrst.value ="";
		qrst.cookie = q->content.cookie;
		try{		
			q->server->answerResult(q->no,qrst);
			AnswerServer::instance()->shiftQuestion(q->no);
		}catch(...){
			
		}
	//	socket = (SocketManager *)item->data(0,Qt::UserRole).toUInt();
	//	socket->sendAnswer(NO,ui.answerLineEdit->text(),false);
	//	pImageManager->DeleteYzmImage(NO);	
		//ui.logTextEdit->append(tr("���ţ�%1   �𰸣�%2   ���ͣ�%3   ʱ�䣺%4").arg(NO).arg(ui.answerLineEdit->text()).arg(type).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		delete item;		
	}
}



//����Ա��ʼ
void Recognizer::on_m_login_clicked(){
	QMutexLocker l(&_mtx_rpc);
	
	int n ;
	QString s;
	gtr::IQuestionServerPrx prx;
	
	QString account = ui.m_count->currentText().trimmed();
	QString pwd = ui.m_password->text().trimmed();
	gtr::CallReturnT cr;
	_serverProxies.clear();
	for(n=0;n<_serverconnstrs.size();n++){		
		try{			
			prx = gtr::IQuestionServerPrx::checkedCast(_communicator->stringToProxy(_serverconnstrs[n].toStdString()));
			if(!prx){
				return;
			}
			if(prx){
				cr = prx->ice_timeout(2000)->login(AnswerServer::answerPrx,account.toStdString(),pwd.toStdString());
				if( cr.succ){
					_serverProxies.push_back(prx);
				}
			}
			showMessage(QString(tr("�����Ϸ�����:%1")).arg(_serverconnstrs[n]));
		}catch(std::exception& e){
			std::string what = e.what();
			//continue;
			QMessageBox::warning(this,tr("����"),QString(tr("���ӷ�����ʧ��:%1")).arg(_serverconnstrs[n]));
			return ;
		}
	}
	
	SetStartState( true );
	ui.m_online->setChecked(true);
	m_timer->start();
}

void Recognizer::on_m_logout_clicked(){
	{
		QMutexLocker l(&_mtx_rpc);
		int n;
		QString account = ui.m_count->currentText().trimmed();
		gtr::IQuestionServerPrx serverPrx;
		for(n=0;n<_serverProxies.size();n++){
			serverPrx = _serverProxies[n];
			try{
			serverPrx->ice_timeout(2000)->logout(AnswerServer::answerPrx,account.toStdString());
			}catch(...){}
		}
		_serverProxies.clear();
	}
	setoffline();
	//SetStartState( false );
}

/*
void Recognizer::on_m_saveYZMPix_stateChanged(int)
{
	
}

void Recognizer::on_m_saveMBKPositionPix_stateChanged(int)
{
	
}
*/
/*
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

//���봦����socket������� 
void Recognizer::on_connected(SocketManager* sock)
{
	QString account = ui.m_count->currentText().trimmed();
	QString pwd = ui.m_password->text().trimmed();
	//SocketManager::GetInstance().SendLoginInfoPacket( account, pwd );
	sock->SendLoginInfoPacket(account,pwd);
	showMessage("��½��,�ȴ�...");
}



void Recognizer::on_loginResult(eLoginResult r)
{
	switch( r )
	{
	case LR_ACCOUNTERR:
		{
			on_m_logout_clicked();
			showMessage("�˺Ŵ��󣺸��˺�û��ע�ᡣ");
			break;
		}
	case LR_PWDERR:
		{
			on_m_logout_clicked();
			showMessage("�������");
			break;
		}
	case LR_ISUSING:
		{
			on_m_logout_clicked();
			showMessage("�˺�����ʹ�á�");
			break;
		}
	case LR_SUCCESS:
		{
			showMessage("��½�ɹ���");
			break;
		}
	default:
		{
			on_m_logout_clicked();
			showMessage("����ĵ�½�����");
			break;
		}
	}
}
*/

//////////////////////////////////////////////////////////////////////////
Recognizer * Recognizer::__handle = NULL;

Recognizer* Recognizer::instance(){
	return __handle;
}

//////////////////////////////////////////////////////////////////////////
void	Recognizer::RpcThread::run (){
	int argc;	
	char* argv[]={"this","--Ice.Config=answer.conf"};
	argc = 2;
	Recognizer::instance()->_communicator = Ice::initialize(argc, argv);
	Ice::ObjectAdapterPtr adapter = Recognizer::instance()->_communicator->createObjectAdapter("answeradapter");
	//Ice::ObjectAdapterPtr adapter = Recognizer::instance()->_communicator->createObjectAdapterWithEndpoints("answeradapter","tcp -p 10099");
	 
	adapter->add( AnswerServer::instance() , Recognizer::instance()->_communicator->stringToIdentity("AnswerEndpoint"));
	adapter->activate();
	AnswerServer::answerPrx = gtr::IAnswerEndpointPrx::uncheckedCast(adapter->createProxy(
																									Recognizer::instance()->_communicator->stringToIdentity("AnswerEndpoint")
																									));

	
	Recognizer::instance()->_communicator->waitForShutdown();
}




