#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT cords;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, cords.x);
		SetInt(IDC_EDIT2, cords.y);
		return true;
	}
	bool OnOK()
	{
		try {
			cords.x=GetInt(IDC_EDIT1);
			cords.y=GetInt(IDC_EDIT2);

		}catch (XCtrl&) {
			MessageBox(*this, "Wrong Input", "Error", IDOK);
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
	GetCursorPos(&dlg.cords);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.cords.x,dlg.cords.y);
	}
	return 0;
}
