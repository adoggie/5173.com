#ifndef UPX_H
#define UPX_H

/*
CREATE TABLE [games] (
[id] INT NOT NULL, 
[name] CHAR(128) NOT NULL, 
[localpath] CHAR(256), 
[remotepath] CHAR(256));

CREATE TABLE [hostgroups] (
[id] INTEGER NOT NULL, 
[name] VARCHAR2(30) NOT NULL, 
[game_id] INTEGER NOT NULL DEFAULT 0);

CREATE TABLE [hosts] (
[id] INTEGER NOT NULL, 
[group_id] INTEGER NOT NULL, 
[address] CHAR(32) NOT NULL);

CREATE TABLE [settings] (
[key] CHAR(30) NOT NULL, 
[value] TEXT(200), 
[howto] TEXT, 
CONSTRAINT [sqlite_autoindex_settings_1] PRIMARY KEY ([key]));

*/


#include <QtGui/QMainWindow>
#include "ui_upx.h"
#include <QSqlDatabase> 
#include <string>
#include <map>
#include <vector>
#include <deque>

//////////////////////////////////////////////////////////////////////////
struct upxHostGroupT{
	quint32 id;
	QString name;
	quint32 gameId;
};

struct upxHostT{
	quint32 id;
	quint32 groupId;
	QString address;
};

struct upxGameT{
	quint32 id;
	QString name;
	QString localpath;
	QString remotepath;
};


struct upxSystemPropertiesT{
	quint32 commport;   //м╗пе╤к©з
};

//////////////////////////////////////////////////////////////////////////

class upx : public QMainWindow
{
	Q_OBJECT

public:
	upx(QWidget *parent = 0, Qt::WFlags flags = 0);
	~upx();

	quint32 newDBSequence();

public slots:
	void addHostGroup();
	void updateHostGroup();
	void delHostGroup();

	void addHost();
	void delHost();
	void	groupClicked( QListWidgetItem * item );

	void saveSettings();
	void saveLog2File();
	void addGame();
	void updateGame();
	void deleteGame();
	void calcGigest();
	void gameRefresh();
	void addGameHost();
	void deleteGameHost();
	void gameStop();
	void gameStart();
	void diffGameFiles();
	void syncGameFiles();
	void selectGamePath();	
	void	selectGameItem ( ) ;
private:
	Ui::upxClass ui;
	QSqlDatabase _db ; 
	std::map< quint32,upxHostGroupT > _hostgroup_list;
	std::map< quint32,upxGameT> _game_list;
	//std::vector<upxHostT>		
	upxSystemPropertiesT	_props;
};

#endif // UPX_H
