#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT t1;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, t1.x);
		SetInt(IDC_EDIT2, t1.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			t1.x = GetInt(IDC_EDIT1);
			t1.y = GetInt(IDC_EDIT2);
			SetCursorPos(t1.x, t1.y);
			return true;
		}
		catch (XCtrl e)
		{
			return false;
		}		
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.t1);
	
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		GetCursorPos(&dlg.t1);
	}
	return 0;
}



