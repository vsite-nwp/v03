#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT poz;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, poz.x);
		SetInt(IDC_EDIT2, poz.y);
		return true;
	}
	bool OnOK()
	{

		try
		{
			poz.x = GetInt(IDC_EDIT1);
			poz.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl)
		{
			return FALSE;
		}

		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	
	GetCursorPos(&dlg.poz);

	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.poz.x, dlg.poz.y);
	}
	return 0;
}
