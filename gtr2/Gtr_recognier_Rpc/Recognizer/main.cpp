#include <QtGui/QApplication>
#include "recognizer.h"
#include "utilitymanager.h"

#include <QTextCodec>
#include "answerServant.h"

int main(int argc, char *argv[])
{
	// Support chinese charactor
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	QApplication a(argc, argv);

	Recognizer w;
	UtilityManager::MoveCenter(w);
	w.show();

	return a.exec();
}