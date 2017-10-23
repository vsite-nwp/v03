#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public: 
	POINT coors;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, coors.x);
		SetInt(IDC_EDIT2, coors.y);
		return true;
	}
	bool OnOK()
	{
		try 
		{
			coors.x = GetInt(IDC_EDIT1);
			coors.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl)
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
	GetCursorPos(&dlg.coors);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.coors.x, dlg.coors.y);
		// TODO: set mouse position to coordinates from dialog
	}
	return 0;
}
