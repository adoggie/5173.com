#pragma once

#include <sstream>

#include "Markup.h"
#include "RDataStream.h"
#include "AuditReg.h"

using namespace std;

class AccountInfo
{
public:
	AccountInfo(void);
	virtual ~AccountInfo(void);

	CMarkup m_markup;
	AuditReg reg;

	virtual void parse(void *lpData ,int nSize) = 0;
	virtual void save() = 0;
	void AddItemType( wxString exp );
	void AddItemProperty( wxString id, wxString exp );
	void AddItemSpecialType( wxString exp );

	bool IsSpecialType( wstring str );
protected:
	vector<wstring> vSpecialType;
};
