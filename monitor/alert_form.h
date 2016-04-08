//---------------------------------------------------------------------------

#ifndef alert_formH
#define alert_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TAlertForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *_btnEmptySel;
	TButton *_btnEmptyAll;
	TListView *_alertList;
	void __fastcall _btnEmptySelClick(TObject *Sender);
	void __fastcall _btnEmptyAllClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TAlertForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAlertForm *AlertForm;
//---------------------------------------------------------------------------
#endif
