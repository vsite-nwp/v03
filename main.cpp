#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog
{
protected:
public:
	POINT pointer;
protected:
	int IDD()
	{
		return IDD_DIALOG1;
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, pointer.x);
		SetInt(IDC_EDIT2, pointer.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			pointer.x = GetInt(IDC_EDIT1);
			pointer.y = GetInt(IDC_EDIT2);
		}

		catch (XCtrl& a)
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
	GetCursorPos(&dlg.pointer);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.pointer.x, dlg.pointer.y);
	}
	return 0;
}
