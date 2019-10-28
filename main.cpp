#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT mouseCursor;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mouseCursor.x);
		SetInt(IDC_EDIT2, mouseCursor.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			GetInt(IDC_EDIT1);
			GetInt(IDC_EDIT2);
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
	GetCursorPos(&dlg.mouseCursor);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(
			dlg.mouseCursor.x,
			dlg.mouseCursor.y
		);
	}
	return 0;
}
