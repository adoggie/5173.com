#pragma once

#include <wx\regex.h>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

struct RegItemData
{
	wstring ItemPropertyName;
	wstring ItemAttrValue;
};

class AuditReg
{
	map<wxString, wxRegEx*> _regItemAttr;
	vector<wxRegEx*>	  _regItemType;
public:
	AuditReg(void);
	~AuditReg(void);

	wstring GetItemType( list<string>& tip );
	void	GetItemAttr( list<string>& tip, vector<RegItemData>& itemdata );

	wstring GetItemType( string& tip );
	void	GetItemAttr( string& tip, vector<RegItemData>& itemdata );

	void AddRegular(wxString id,wxString exp);
	void AddRegular(wxString exp);
};
