#include "upx.h"
#include <QSqlQuery>
#include <QSqlQueryModel> 

#include <QMessageBox> 
#include <QTextcodec> 
#include <QHostAddress>
#include <QFileInfo>
#include <QFileDialog>

upx::upx(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	_db = QSqlDatabase::addDatabase("QSQLITE"); 
	_db.setDatabaseName("c:/upx.db3");
	if ( !_db.open()){
		QMessageBox::critical(NULL, QObject::tr("Collection"), QObject::tr("????聺卢????"));
	} 
	newDBSequence();


	connect(ui.btnAddHostGroup,SIGNAL(clicked()),this,SLOT(addHostGroup())) ;
	connect(ui.btnUpdateHostGroup,SIGNAL(clicked()),this,SLOT(updateHostGroup())) ;
	connect(ui.btnDelHostGroup,SIGNAL(clicked()),this,SLOT(delHostGroup())) ;
	connect(ui.btnAddHost,SIGNAL(clicked()),this,SLOT(addHost()));
	connect(ui.btnDelHost,SIGNAL(clicked()),this,SLOT(delHost()));
	connect(ui.listHostGroup,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(groupClicked(QListWidgetItem *)));
	
	connect(ui.btnSettingsSave,SIGNAL(clicked()),this,SLOT(saveSettings()));

	connect(ui.btnSaveToFile,SIGNAL(clicked()),this,SLOT(saveLog2File()));

	connect(ui.btnAddGame,SIGNAL(clicked()),this,SLOT(addGame()));
	connect(ui.btnUpdateGame,SIGNAL(clicked()),this,SLOT(updateGame()));
	connect(ui.btnDelGame,SIGNAL(clicked()),this,SLOT(deleteGame()));
	connect(ui.btnCalcDigest,SIGNAL(clicked()),this,SLOT(calcGigest()));
	connect(ui.btnRefresh,SIGNAL(clicked()),this,SLOT(gameRefresh()));
	connect(ui.btnGameAddHost,SIGNAL(clicked()),this,SLOT(addGameHost()));
	connect(ui.btnGameDelHost,SIGNAL(clicked()),this,SLOT(deleteGameHost()));
	connect(ui.btnStopGame,SIGNAL(clicked()),this,SLOT(gameStop()));

	connect(ui.btnStartGame,SIGNAL(clicked()),this,SLOT(gameStart()));
	connect(ui.btnFileDiffer,SIGNAL(clicked()),this,SLOT(diffGameFiles()));
	connect(ui.btnFileSync,SIGNAL(clicked()),this,SLOT(syncGameFiles()));

	connect(ui.btnSelectPath,SIGNAL(clicked()),this,SLOT(selectGamePath()));

	connect(ui.listGames,SIGNAL(itemSelectionChanged()),this,SLOT(selectGameItem()));
	


	//////////////////////////////////////////////////////////////////////////
	//InitData
	QSqlQuery query("select * from hostgroups   order by name");
	query.exec();
	while (query.next()) {	
		upxHostGroupT group;
		group.id =query.value(0).toUInt();
		group.name = query.value(1).toString();
		group.gameId = query.value(2).toUInt();
		_hostgroup_list[group.id] = group ;
		QListWidgetItem* item = new QListWidgetItem(group.name,ui.listHostGroup)	;
		item->setData(Qt::UserRole,group.id);
		ui.listHostGroup->addItem(item);
	}
	
	//////////////////////////////////////////////////////////////////////////
	QTableWidgetItem* item = new  QTableWidgetItem(tr("游戏名称"));
	QStringList headers;
	headers<<tr("游戏名称")<<tr("本地路径")<<tr("远程路径")<<tr("计算摘要时间");
	ui.listGames->setHorizontalHeaderLabels(headers);
	//ui.listGames->takeHorizontalHeaderItem(0); //->setText(tr("游戏名"));
	//////////////////////////////////////////////////////////////////////////
	//load gamelist
	query.clear();
	query.exec("select id,name,localpath,remotepath,calc_time from games order by name;");
	quint32 n=0;
	while (query.next()) {	
		quint32 id;
		id = query.value(0).toUInt();
		ui.listGames->setRowCount(n+1);

		item = new  QTableWidgetItem(query.value(1).toString());
		item->setData(Qt::UserRole,id);
		ui.listGames->setItem(n,0,item);
		
		item = new  QTableWidgetItem(query.value(2).toString());
		item->setData(Qt::UserRole,id);
		ui.listGames->setItem(n,1,item);

		item = new  QTableWidgetItem(query.value(3).toString());
		item->setData(Qt::UserRole,id);
		ui.listGames->setItem(n,2,item);

		item = new  QTableWidgetItem(query.value(4).toString());
		item->setData(Qt::UserRole,id);
		ui.listGames->setItem(n,3,item);	 
		n++;
	}

}


void	upx::groupClicked( QListWidgetItem * item ){
	ui.edtHostGrpName->setText(item->text());
	quint32 id;
	id = item->data(Qt::UserRole).toUInt();
	ui.listHosts->clear();
	QSqlQuery query("select id,group_id,address from hosts   where group_id ="+QString::number(id) +" order by address");
	query.exec();
	while (query.next()) {			
		QListWidgetItem* item = new QListWidgetItem(query.value(2).toString(),ui.listHosts)	;
		id = query.value(0).toUInt();
		item->setData(Qt::UserRole,query.value(0));
		ui.listHosts->addItem(item);
	}
}

upx::~upx()
{

}

void upx::addHostGroup(){
	if( ui.edtHostGrpName->text().trimmed().size() == 0){
		return ;
	}
	quint32 id;
	upxHostGroupT group;
	group.id = newDBSequence();
	group.name = ui.edtHostGrpName->text().trimmed();

	QSqlQuery query;
	query.prepare("INSERT INTO hostgroups (id, name,game_id) VALUES (?, ?, 0)");
	query.bindValue(0, group.id);
	query.bindValue(1, group.name);
	if( query.exec()){
		_hostgroup_list[group.id] = group;
		QListWidgetItem* item = new QListWidgetItem(group.name,ui.listHostGroup)	;
		item->setData(Qt::UserRole,group.id);
		ui.listHostGroup->addItem(item);
	}

}

void upx::updateHostGroup(){
	if( ui.edtHostGrpName->text().trimmed().size() == 0){
		return ;
	}
	QList<QListWidgetItem *>	items = ui.listHostGroup->selectedItems();
	if( items.size() ==0){
		return;
	}
	QListWidgetItem * item = items[0];
	quint32 id;
	upxHostGroupT group;
	id = item->data(Qt::UserRole).toUInt();
	QSqlQuery query;
	query.prepare("update hostgroups set name=? where id=?");
	query.bindValue(0, ui.edtHostGrpName->text().trimmed());
	query.bindValue(1, id);
	if(query.exec()){
		item->setText(ui.edtHostGrpName->text().trimmed());
	}	 
}

void upx::delHostGroup(){
	QList<QListWidgetItem *>	items = ui.listHostGroup->selectedItems();
	if( items.size() !=1){
		return;
	}
	QListWidgetItem *  item = items[0];
	quint32 id = item->data(Qt::UserRole).toUInt();
	std::map< quint32,upxHostGroupT >::iterator itr;
	itr = _hostgroup_list.find(id);
	if( itr!=_hostgroup_list.end()){
		_hostgroup_list.erase(itr);
	}
	//map to db
	QSqlQuery query( QString("delete from hostgroups where id=%1").arg(id));
	query.exec();
	ui.edtHostGrpName->setText("");
	ui.listHosts->clear();
	ui.listHostGroup->removeItemWidget(item);
	delete item;
}

void upx::addHost(){
	QList<QListWidgetItem *>	items = ui.listHostGroup->selectedItems();
	if( items.size() !=1){
		return;
	}
	QListWidgetItem *  gitem = items[0];
	quint32 gid = gitem->data(Qt::UserRole).toUInt();

	QHostAddress addr1,addr2;
	if( addr1.setAddress(ui.edtHostAddr1->text()) == false){
		QMessageBox::critical(this,"",tr("地址错误!"));
		return;
	}
	quint32 id = newDBSequence();
	QString sql;
	if(addr2.setAddress(ui.edtHostAddr2->text()) == false){ //单地址加入
		{
			sql = QString("select count(*) from  hosts   where group_id =%1 and address='%2'").arg(gid).arg(ui.edtHostAddr1->text());
			QSqlQuery query(sql);
			 
			query.next();
			if(query.value(0).toUInt() !=0){
				QMessageBox::critical(this,"",tr("重复的地址!"));
				return;
			}
		}
		{
			QSqlQuery query( QString("insert into hosts values(%1,%2,'%3')").arg(id).arg(gid).arg(ui.edtHostAddr1->text()));			 
			QListWidgetItem* item = new QListWidgetItem(ui.edtHostAddr1->text(),ui.listHosts);
			ui.listHosts->addItem(item);
		}
	}else{ //多地址加入 
		 QStringList first = ui.edtHostAddr1->text().split('.');
		 QStringList second = ui.edtHostAddr2->text().split('.');
		 if(first[3].toUInt()> second[3].toUInt()){
			 QMessageBox::critical(this,"",tr("地址区间错误!"));
			 return;
		 }
		 quint32 n;
		 for(n=first[3].toUInt();n<=second[3].toUInt();n++){
			 QStringList addrs = first;
			 addrs[3] = QString::number(n);
			 QString addr = addrs.join("."); 

			 sql = QString("select count(*) from  hosts   where group_id =%1 and address='%2'").arg(gid).arg(addr);
			 QSqlQuery query(sql);
			 query.next();
			 if(query.value(0).toUInt() !=0){
				 continue;
			 }
				query.clear();
				id = newDBSequence();
			 query.exec(QString("insert into hosts values(%1,%2,'%3')").arg(id).arg(gid).arg(addr));			 
			 QListWidgetItem* item = new QListWidgetItem(addr,ui.listHosts);
			 ui.listHosts->addItem(item);
		 }

	} 
}

void upx::delHost(){
	QList<QListWidgetItem *>	items = ui.listHosts->selectedItems();
	if( items.size() ==0){
		return;
	}
	std::deque<quint32> ids;
	QList<QListWidgetItem *>::Iterator itr;
	for(itr = items.begin();itr!=items.end();itr++){
		quint32 id;
		id = (*itr)->data(Qt::UserRole).toUInt();
		QSqlQuery query( QString("delete from hosts where id=%1").arg(id));
		query.exec();		
		ids.push_back(id);
	}

	while(ids.size()){
		for(itr = items.begin();itr!=items.end();itr++){
			quint32 id;
			id = (*itr)->data(Qt::UserRole).toUInt();
			if( id == ids[0]){

				//ui.listHosts->removeItemWidget( ui.listHosts->row(*itr));
				ui.listHosts->removeItemWidget( ui.listHosts->takeItem(ui.listHosts->row(*itr)));
				//delete (*itr);
				ids.pop_front();
				break;
			}
			
		}
	}
	
}


quint32 upx::newDBSequence(){
	static quint32 seqno = 0;
	QSqlQuery query;
	if(seqno==0){ //第一次检索数据库最大值
		query.exec("select max(id) from games");
		if(query.next()){
			seqno = query.value(0).toUInt();
		}
		query.exec("select max(id) from hostgroups");
		if(query.next()){
			seqno = qMax(query.value(0).toUInt(),seqno);
		}
		query.exec("select max(id) from hosts");
		if(query.next()){
			seqno = qMax(query.value(0).toUInt(),seqno);
		}
	}
	seqno++;


// 	QSqlQuery query("select value from settings   where key ='dbseqno'");
// 	query.exec();
// 	quint32 seqno = 0;
// 	if(query.next()) {			
// 		seqno = query.value(0).toUInt();
// 		query.clear();
// 		query.exec(QString("update settings set value =%1 where key='dbseqno';").arg(seqno+1));
// 	}
	return seqno;
}




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void upx::saveSettings(){

}

void upx::saveLog2File(){

}

void upx::addGame(){
	if( ui.edtGameName->text().trimmed().size() == 0){
		QMessageBox::critical(this,"",tr("无效的名称!"));		
		return;
	}
	if( ui.edtRemotePath->text().trimmed().size() == 0){
		QMessageBox::critical(this,"",tr("无效的远程路径!"));		
		return;
	}

	QFileInfo fi(ui.edtLocalPath->text());
	if( !fi.isDir()){
		QMessageBox::critical(this,"",tr("无效的本地路径!"));		
		return;
	}

// 	fi.setFile(ui.edtRemotePath->text());
// 	if(!fi.isDir()){
// 		QMessageBox::critical(this,"",tr("无效的远程路径!"));		
// 		return;
// 	}

	QSqlQuery query;
	quint32 id,pos;
	id = newDBSequence();
	query.prepare("INSERT INTO games VALUES (?, ?, ?,?,'')");
	query.bindValue(0,id);
	query.bindValue(1,ui.edtGameName->text().trimmed());
	query.bindValue(2,ui.edtLocalPath->text().trimmed());
	query.bindValue(3,ui.edtRemotePath->text().trimmed());
	if(!query.exec()){
		return;
	}

	pos = ui.listGames->rowCount();
	
	ui.listGames->setRowCount(pos+1);

	QTableWidgetItem* item;
	item = new  QTableWidgetItem(ui.edtGameName->text().trimmed());
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,0,item);

	item = new  QTableWidgetItem(ui.edtLocalPath->text().trimmed());
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,1,item);

	item = new  QTableWidgetItem(ui.edtRemotePath->text().trimmed());
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,2,item);

	item = new  QTableWidgetItem("");
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,3,item);	 

}

void upx::updateGame(){
	QTableWidgetItem * item;
	QList<QTableWidgetItem *> items = ui.listGames->selectedItems();
	if(items.size() == 0){
		return;
	}
	quint32 id;
	quint32 pos;
	id = items.at(0)->data(Qt::UserRole).toUInt();
	pos = items.at(0)->row();
	//
	//////////////////////////////////////////////////////////////////////////

	if( ui.edtGameName->text().trimmed().size() == 0){
		QMessageBox::critical(this,"",tr("无效的名称!"));		
		return;
	}
	if( ui.edtRemotePath->text().trimmed().size() == 0){
		QMessageBox::critical(this,"",tr("无效的远程路径!"));		
		return;
	}

	QFileInfo fi(ui.edtLocalPath->text());
	if( !fi.isDir()){
		QMessageBox::critical(this,"",tr("无效的本地路径!"));		
		return;
	}
 
	QSqlQuery query;
	
	//id = newDBSequence();
	query.prepare("update games set name=?,localpath=?,remotepath=? where id=?");	
	query.bindValue(0,ui.edtGameName->text().trimmed());
	query.bindValue(1,ui.edtLocalPath->text().trimmed());
	query.bindValue(2,ui.edtRemotePath->text().trimmed());
	query.bindValue(3,id);
	if(!query.exec()){
		return;
	}

	 

//	QTableWidgetItem* item;
	item = new  QTableWidgetItem(ui.edtGameName->text().trimmed());
	items.at(0)->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,0,item);

	item = new  QTableWidgetItem(ui.edtLocalPath->text().trimmed());
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,1,item);

	item = new  QTableWidgetItem(ui.edtRemotePath->text().trimmed());
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,2,item);

	item = new  QTableWidgetItem("");
	item->setData(Qt::UserRole,id);
	ui.listGames->setItem(pos,3,item);		
}

void upx::deleteGame(){	
	QList<QTableWidgetItem *> items = ui.listGames->selectedItems ();
	QList<QTableWidgetItem *>::iterator itr;
	for(itr = items.begin();itr!=items.end();itr++){		
		ui.listGames->removeRow((*itr)->row());//,(*itr)->column());
		break;
	}
//	QMessageBox::about(this,"",QString::number(ui.listGames->rowCount()));
}

void upx::calcGigest(){

}

void upx::gameRefresh(){

}

void upx::addGameHost(){

}

void upx::deleteGameHost(){

}
void upx::gameStop(){

}
void upx::gameStart(){

}
void upx::diffGameFiles(){

}
void upx::syncGameFiles(){

}

void upx::selectGamePath(){
	QFileDialog dlg;
	dlg.setFileMode(QFileDialog::Directory);
	//dlg.setDirectory("c:");
	if( QFileDialog::Accepted == dlg.exec()){
		ui.edtLocalPath->setText(dlg.selectedFile());
	}
}

void	upx::selectGameItem (   ){
	QTableWidgetItem * item;
	//item = ui.listGames->item(row,column);
	quint32 id;
	//id = item->data(Qt::UserRole).toUInt();
	QList<QTableWidgetItem *> items = ui.listGames->selectedItems ();
	quint32 r,c;
	r = items.at(0)->row();
	ui.edtGameName->setText(items.at(0)->text());
	ui.edtLocalPath->setText(items.at(1)->text());
	ui.edtRemotePath->setText(items.at(2)->text());

}


