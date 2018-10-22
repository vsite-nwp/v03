#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT mos_pos;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		// TODO: set initial values to edit controls
		SetInt(IDC_EDIT1, mos_pos.x);
		SetInt(IDC_EDIT2, mos_pos.y);

		return true;
	}
	bool OnOK()
	{
		// TODO: get current values from edit controls
		// TODO: if not valid return false

		try {
			mos_pos.x = GetInt(IDC_EDIT1);
			mos_pos.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl ex) {
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
	// TODO: find current mouse position and transfer to dialog
	GetCursorPos(&dlg.mos_pos);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(dlg.mos_pos.x, dlg.mos_pos.y);

	}
	return 0;
}
