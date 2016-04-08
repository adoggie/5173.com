#include "upx.h"
#include <QtGui/QApplication>
#include <QSqlQuery>
#include <QSqlQueryModel> 
#include <QSqlDatabase> 
#include <QMessageBox> 
#include <QTextcodec> 

int main(int argc, char *argv[])
{
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK")); 
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
	QApplication a(argc, argv);
	upx w;
	w.show();
	
//		QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	/*QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));*/
	//QMessageBox::critical(NULL,QObject::tr("√¿¿ˆ"),QObject::tr("dsfsdf"));
	return a.exec();
}
