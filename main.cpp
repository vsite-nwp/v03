#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT cursor;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, cursor.x);
		SetInt(IDC_EDIT2, cursor.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			cursor.x = GetInt(IDC_EDIT1);
			cursor.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl){ return false; }
			
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.cursor);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.cursor.x, dlg.cursor.y);
	}
	return 0;
}
