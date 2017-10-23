#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public: 
	POINT a;
	
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, a.x);
		SetInt(IDC_EDIT2, a.y);
		return true;
	}
	bool OnOK()
	{
		try {
			a.x = GetInt(IDC_EDIT1);
			a.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
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

	GetCursorPos(&dlg.a);
	
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.a.x, dlg.a.y);
	}
	return 0;
}
