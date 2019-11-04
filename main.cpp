#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT coords;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, coords.x);
		SetInt(IDC_EDIT2, coords.y);
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
	GetCursorPos(&dlg.coords);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.coords.x, dlg.coords.y);
	}
	return 0;
}
