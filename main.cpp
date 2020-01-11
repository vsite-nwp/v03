#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT point;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		// TODO: set initial values to edit controls
		SetInt(IDC_EDIT1, point.x);
		SetInt(IDC_EDIT2, point.y);
		return true;
	}
	bool OnOK()
	{
		try 
		{
			point.x = GetInt(IDC_EDIT1);
			point.y = GetInt(IDC_EDIT2);
			return true;
		}
		catch (XCtrl) { return false; }

		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	// TODO: find current mouse position and transfer to dialog
	GetCursorPos(&dlg.point);
	
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(dlg.point.x, dlg.point.y);
	}
	return 0;
}
