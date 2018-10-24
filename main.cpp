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
		SetInt(IDC_EDIT1, curpos.x);
		SetInt(IDC_EDIT2, curpos.y);
		return true;
	}
	bool OnOK()
	{
		try {
			curpos.x = GetInt(IDC_EDIT1);
			curpos.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl) { return false; }
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
public:
	POINT curpos;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.curpos);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.curpos.x, dlg.curpos.y);
	}
	return 0;
}
