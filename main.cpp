#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"


class MyDialog : public Dialog 
{
public: POINT mouseCoord;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mouseCoord.x);
		SetInt(IDC_EDIT2, mouseCoord.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			mouseCoord.x = GetInt(IDC_EDIT1);
			mouseCoord.y = GetInt(IDC_EDIT2);
			
		}
		catch (XCtrl e)
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
	
	GetCursorPos(&dlg.mouseCoord);

	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.mouseCoord.x, dlg.mouseCoord.y);
		
	}
	return 0;
}
