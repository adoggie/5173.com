// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "alert_form.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAlertForm *AlertForm;

// ---------------------------------------------------------------------------
__fastcall TAlertForm::TAlertForm(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TAlertForm::_btnEmptySelClick(TObject *Sender) {
	/**
	 * 以下代码未经测试
	 */

	TListItems* lpListItems = _alertList->Items;
	int nIndex = 0;
	TListItem* lpItem = lpListItems->Item[nIndex];
	if ( !lpItem ) {
    	return;
	}

	do {
		if (lpItem->Checked) {
			lpListItems->Delete(nIndex);
		}
		else {
			nIndex++;
		}
		lpItem = lpListItems->Item[nIndex];
	}while (lpItem);
}
// ---------------------------------------------------------------------------

void __fastcall TAlertForm::_btnEmptyAllClick(TObject *Sender) {
	/**
	 * 以下代码未经测试
	 */

	TListItems* lpListItems = _alertList->Items;
	for (int i = 0; i < lpListItems->Count; i++) {
		delete lpListItems->Item[i];
	}
	lpListItems->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TAlertForm::FormCloseQuery(TObject *Sender, bool &CanClose) {
	CanClose = false;
	this->WindowState = wsMinimized;
}
// ---------------------------------------------------------------------------
