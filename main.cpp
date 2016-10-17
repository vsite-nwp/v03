#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT mouse_pos;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mouse_pos.x);
		SetInt(IDC_EDIT2, mouse_pos.y);
		return true;
	}
	bool OnOK()
	{
		try {
			mouse_pos.x = GetInt(IDC_EDIT1);
			mouse_pos.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl ex){
			return false;
		}
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.mouse_pos);

	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.mouse_pos.x, dlg.mouse_pos.y);
	}
	return 0;
}
