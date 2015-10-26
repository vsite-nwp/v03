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
		// TODO: set initial values to edit controls
		SetInt(IDC_EDIT1, cords.x);
		SetInt(IDC_EDIT2, cords.y);
		return true;
	}
	bool OnOK()
	{
		// TODO: get current values from edit controls
		cords.x = GetInt(IDC_EDIT1);
		cords.y = GetInt(IDC_EDIT2);


		// TODO: if not valid return false
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	// TODO: find current mouse position and transfer to dialog	/pokupi i prosljedi u dijalog
	GetCursorPos(&dlg.cords);

	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog	//setcurpos na te kordinare
		SetCursorPos(dlg.cords.x, dlg.cords.y);
	}
	return 0;
}
