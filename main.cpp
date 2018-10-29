#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT kord;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1,kord.x);
		SetInt(IDC_EDIT2, kord.y);
		return true;
	}
	bool OnOK()
	{
		try {
			kord.x=GetInt(IDC_EDIT1);
			kord.y=GetInt(IDC_EDIT2);
		}
		catch (XCtrl&)
		{
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
	GetCursorPos(&dlg.kord);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.kord.x, dlg.kord.y);
	}
	return 0;
}
