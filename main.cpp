#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"


class MyDialog : public Dialog 
{	public:
	POINT p;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1,p.x);
		SetInt(IDC_EDIT2,p.y);
		// TODO: set initial values to edit controls
		return true;
	}
	bool OnOK()
	{
		// TODO: get current values from edit controls
		p.x=GetInt(IDC_EDIT1);
		p.y=GetInt(IDC_EDIT2);
		// TODO: if not valid return false
		return true;
	}
	void OnCancel()	{  }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.p);// TODO: find current mouse position and transfer to dialog
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{	
		int x = dlg.p.x;
		int y = dlg.p.y;

		SetCursorPos(x,y);
		// TODO: set mouse position to coordinates from dialog
	}
	return 0;
}
