#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT coordinates;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
			SetInt(IDC_EDIT1, coordinates.x);
			SetInt(IDC_EDIT2, coordinates.y);
			return true;
	}
	bool OnOK()
	{
		try {
			coordinates.x =GetInt(IDC_EDIT1);
			coordinates.y =GetInt(IDC_EDIT2);
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
	GetCursorPos(&dlg.coordinates);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.coordinates.x, dlg.coordinates.y);
	}
	return 0;
}

