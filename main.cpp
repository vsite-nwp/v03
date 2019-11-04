#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{	
public:
	POINT kordinata;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		
		SetInt(IDC_EDIT1, kordinata.x);
		SetInt(IDC_EDIT2, kordinata.y);
		return true;
	}
	bool OnOK() {
		try {
			kordinata.x = GetInt(IDC_EDIT1);
			kordinata.y = GetInt(IDC_EDIT2);

		}
		catch(XCtrl){
			return false;

		}
	}

	
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.kordinata);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.kordinata.x, dlg.kordinata.y);
		
	}
	return 0;
}
