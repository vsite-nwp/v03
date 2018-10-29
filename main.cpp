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
		SetInt(IDC_EDIT1, point.x);
		SetInt(IDC_EDIT2, point.y);
		return true;
	}
	bool OnOK()
	{
		// TODO: get current values from edit controls
		// TODO: if not valid return false
		try {
			int x = GetInt(point.x);
			int y = GetInt(point.y);
		}
		catch (XCtrl&) { return false; }
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
public:
	POINT point;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	// TODO: find current mouse position and transfer to dialog
	GetCursorPos(&dlg.point);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(&dlg.point.x, &dlg.point.y;);
	}
	return 0;
}
