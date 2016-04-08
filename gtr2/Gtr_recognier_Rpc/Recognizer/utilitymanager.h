#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include <QWidget>
#include <QDesktopWidget>
#include <QApplication>
#include <QString>


namespace UtilityManager
{
	void MoveCenter(QWidget &widget);
	bool IsNumeric(const QString &value);
};

#endif // UTILITYMANAGER_H
