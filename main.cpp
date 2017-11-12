#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog
{
public:
	POINT mousePos;
protected:
	int IDD()
	{
		return IDD_DIALOG1;
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mousePos.x);
		SetInt(IDC_EDIT2, mousePos.y);
		return true;
	}
	bool OnOK()
	{
		try {
			mousePos.x = GetInt(IDC_EDIT1);
			mousePos.x = GetInt(IDC_EDIT2);
		}
		catch (XCtrl X) {
			return false;
		}
		return true;
	}
	void OnCancel() { }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.mousePos);
	if (dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.mousePos.x, dlg.mousePos.y);
	}
	return 0;
}
