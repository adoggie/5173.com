#include "AuditReg.h"

extern std::string ws2s(wstring& inputws);
extern std::wstring s2ws(const string& s);

AuditReg::AuditReg(void)
{
}

AuditReg::~AuditReg(void)
{
}

void AuditReg::AddRegular(wxString id, wxString exp)
{
	_regItemAttr[id] = new wxRegEx;
	if( !_regItemAttr[id]->Compile(exp) )
		assert(false);

}

void AuditReg::AddRegular(wxString exp)
{
	wxRegEx* reg = new wxRegEx;
	if ( !reg->Compile(exp) )
	{
		assert(0);
	}

	_regItemType.push_back(reg);
}

/*
*/
wstring AuditReg::GetItemType( list<string>& tip )
{
	list<string>::iterator it = tip.begin();
	while(it != tip.end())
	{
		vector<wxRegEx*>::iterator rit = _regItemType.begin();
		while(rit != _regItemType.end())
		{
			wstring item = s2ws(*it);
			if( (*rit)->Matches(item) )
			{
				wstring ws = (*rit)->GetMatch(item);
				if ( ws.compare(item) == 0 )
				{
					return item;
				}
			}
			rit++;
		}
		it++;
	}
	return _T("其他物品");
}

void AuditReg::GetItemAttr( list<string>& tip, vector<RegItemData>& itemdata )
{
	list<string>::iterator it = tip.begin();
	while(it != tip.end())
	{
		map<wxString, wxRegEx*>::iterator rit = _regItemAttr.begin();
		while(rit != _regItemAttr.end())
		{
			wstring item = s2ws(*it);
			wxRegEx* reg = (*rit).second;
			if( reg->Matches(item) )
			{
				RegItemData data;
				data.ItemPropertyName = (*rit).first;
				data.ItemAttrValue = reg->GetMatch(item, 1);
				itemdata.push_back(data);
				break;
			}
			rit++;
		}
		it++;
	}
}

wstring AuditReg::GetItemType( string& tip )
{
	vector<wxRegEx*>::iterator rit = _regItemType.begin();
	while(rit != _regItemType.end())
	{
		wstring item = s2ws(tip);
		if( (*rit)->Matches(item) )
		{
			wstring ws = (*rit)->GetMatch(item);
			if ( ws.compare(item) == 0 )
			{
				return item;
			}
		}
		rit++;
	}
	return _T("其他物品");
}
void AuditReg::GetItemAttr( string& tip, vector<RegItemData>& itemdata )
{
	map<wxString, wxRegEx*>::iterator rit = _regItemAttr.begin();
	while(rit != _regItemAttr.end())
	{
		wstring item = s2ws(tip);
		wxRegEx* reg = (*rit).second;
		if( reg->Matches(item) )
		{
			RegItemData data;
			data.ItemPropertyName = (*rit).first;
			data.ItemAttrValue = reg->GetMatch(item, 1);
			itemdata.push_back(data);
			break;
		}
		rit++;
	}
}
