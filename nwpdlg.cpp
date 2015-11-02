#include <windows.h>
#include "nwpdlg.h"
#include <map>

int CALLBACK Dialog::Proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
	static std::map<HWND, Dialog*> wmap;
	if(msg == WM_INITDIALOG)
	{
		Dialog* pThis = reinterpret_cast<Dialog*>(lp);
		pThis->hw = hw;
		wmap[hw] = pThis; 
		return pThis->OnInitDialog();
	}
	Dialog* pThis = wmap[hw];
	if(msg == WM_COMMAND)
	{
		if(LOWORD(wp) == IDOK && pThis->OnOK())
			return EndDialog(hw, IDOK);
		if(LOWORD(wp) == IDCANCEL)
		{
			pThis->OnCancel();
			return EndDialog(hw, IDCANCEL);
		}
		return pThis->OnCommand(LOWORD(wp), HIWORD(wp));
	}
	if(msg == WM_DESTROY)
		wmap.erase(hw);
	return 0;
}

int Dialog::DoModal(HINSTANCE hInst, HWND parent)
{
	return DialogBoxParam(hInst, MAKEINTRESOURCE(IDD()), parent, Proc, 
		reinterpret_cast<LPARAM>(this));
}

void Dialog::SetInt(int idCtrl, int val)
{
	SetDlgItemInt(*this, idCtrl, val, true);
}

int Dialog::GetInt(int idCtrl)
{
	BOOL b;
	int n = GetDlgItemInt(*this, idCtrl, &b, true);
	if(!b) throw XCtrl();
	return n;
}
