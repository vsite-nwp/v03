#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT xy;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		// TODO: set initial values to edit controls
		SetInt(IDC_EDIT1, xy.x);
		SetInt(IDC_EDIT2, xy.y);
		return true;
	}
	bool OnOK()
	{
		// TODO: get current values from edit controls
		xy.x = GetInt(IDC_EDIT1);
		xy.y = GetInt(IDC_EDIT2);
		// TODO: if not valid return false
		if (GetInt(IDC_EDIT1) == NULL || GetInt(IDC_EDIT2) == NULL)
			return false;
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	// TODO: find current mouse position and transfer to dialog
	SendDlgItemMessage(dlg.operator HWND, IDD_DIALOG1, GetCursorPos(dlg.xy), NULL, NULL);
	//SetDlgItemInt(dlg.operator HWND, IDD_DIALOG1, GetCursorPos(dlg.xy), true);//
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(dlg.xy->x, dlg.xy->y);
	}
	return 0;
}
