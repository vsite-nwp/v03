#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog
{
public:
	POINT mseCrsr;
protected:
	int IDD()
	{
		return IDD_DIALOG1;
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mseCrsr.x);
		SetInt(IDC_EDIT2, mseCrsr.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			mseCrsr.x = GetInt(IDC_EDIT1);
			mseCrsr.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&)
		{
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
	GetCursorPos(&dlg.mseCrsr);

	if (dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.mseCrsr.x, dlg.mseCrsr.y);
	}
	return 0;
}