#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT polozaj;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, polozaj.x);
		SetInt(IDC_EDIT2, polozaj.y);
		return true;
	}
	bool OnOK()
	{
		try {
			polozaj.x = GetInt(IDC_EDIT1);
			polozaj.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl) {
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
	GetCursorPos(&dlg.polozaj);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.polozaj.x, dlg.polozaj.y);
	}
	return 0;
}
