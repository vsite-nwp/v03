#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, pozicija.x);
		SetInt(IDC_EDIT2, pozicija.y);
		return true;
	}
	bool OnOK()
	{
		try {
			pozicija.x = GetInt(IDC_EDIT1);
			pozicija.y = GetInt(IDC_EDIT2);
		}
		catch(XCtrl){
			return false;
		}
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.pozicija);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.pozicija.x, dlg.pozicija.y);
	}
	return 0;
}
