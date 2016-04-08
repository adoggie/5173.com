#include "utilitymanager.h"

namespace UtilityManager
{
	void MoveCenter(QWidget &widget)
	{
		// Get the size of screen
		QDesktopWidget* desktop = QApplication::desktop();
		int desktopWidth = desktop->width();
		int desktopHeight = desktop->height();

		// Move window
		widget.move((desktopWidth - widget.width())/2, (desktopHeight - widget.height())/2);
	}



	bool IsNumeric(const QString &val)
	{
		if(val.isEmpty())
		{
			return FALSE;
		}

		for(int i=0;i<val.length();i++)   
		{   
			if(!val[i].isDigit())   
			{   
				return FALSE;
			}
		}

		return TRUE;
	}

}