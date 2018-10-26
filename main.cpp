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
		point.x = 0;
		point.y = 0;
		SetInt(IDC_EDIT1, point.x);
		SetInt(IDC_EDIT2, point.y);
		return true;
	}
	bool OnOK()
	{
		try {
			point.x = GetInt(IDC_EDIT1);
			point.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
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
	GetCursorPos(&dlg.point);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.point.x,dlg.point.y); 
	}
	return 0;
}
