
#include "AccountInfo.h"

#include <string>
#include <windows.h>
#include <wx/string.h>
using namespace std;

AccountInfo::AccountInfo(void)
{
}

AccountInfo::~AccountInfo(void)
{
}
void AccountInfo::AddItemType( wxString exp )
{
	reg.AddRegular(exp);
}
void AccountInfo::AddItemProperty( wxString id, wxString exp )
{
	reg.AddRegular(id,exp);
}

void AccountInfo::AddItemSpecialType( wxString exp )
{
	vSpecialType.push_back(wstring(exp));
}

bool AccountInfo::IsSpecialType( wstring str )
{
	vector<wstring>::iterator it = vSpecialType.begin();
	while( it != vSpecialType.end() )
	{
		if ( str.compare(*it) == 0 )
		{
			return true;
		}
		it++;
	}
	return false;
}


//Converting a WChar string to a Ansi string
std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen<= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen -1] = 0;
	std::string strTemp(pszDst);
	delete [] pszDst;
	return strTemp;
}
string ws2s(wstring& inputws){ return WChar2Ansi(inputws.c_str()); }
//Converting a Ansi string to WChar string
std::wstring Ansi2WChar(LPCSTR pszSrc, int nLen)
{
	if (nLen == 0)
	{
		return std::wstring();
	}
	int nSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, 0, 0);
	if(nSize <= 0) return std::wstring();
	WCHAR *pwszDst = new WCHAR[nSize+1];
	if( NULL == pwszDst) return std::wstring();
	MultiByteToWideChar(CP_ACP, 0,(LPCSTR)pszSrc, nLen, pwszDst, nSize);
	pwszDst[nSize] = 0;
	if( pwszDst[0] == 0xFEFF) // skip Oxfeff
		for(int i = 0; i < nSize; i ++) 
			pwszDst[i] = pwszDst[i+1]; 
	wstring wcharString(pwszDst);
	delete pwszDst;
	return wcharString;
}
std::wstring s2ws(const string& s){ return Ansi2WChar(s.c_str(),s.size());}