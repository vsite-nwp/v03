#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
class MyDialog : public Dialog 
{
public:
	POINT pos;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1,pos.x);
		SetInt(IDC_EDIT2, pos.y);
		return true;
	}
	bool OnOK()
	{
		try {
			pos;
			pos.x=GetInt(IDC_EDIT1);
			pos.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl a) {
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
	GetCursorPos(&dlg.pos);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.pos.x, dlg.pos.y);
	}
	return 0;
}
