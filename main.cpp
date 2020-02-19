#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT p;
	
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		Postavi(IDC_EDIT1, IDC_EDIT2, p.x, p.y);
		return true;
	}
	bool OnOK()
	{
		bool flag=true;
		try {
			p.x = GetInt(IDC_EDIT1);
		}
		catch (XCtrl ex)
		{
			p.x = 0;
			flag = false;
		}
		try {
			p.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl ex)
		{
			p.y = 0;
			flag = false;
		}
		Postavi(IDC_EDIT1, IDC_EDIT2, p.x, p.y);
		return flag;
	}
	void OnCancel()	{ EndDialog(*this, 2); }
	bool OnCommand(int id, int code) { return false; }
private:
	void Postavi(int id1, int id2, int value1, int value2) {
		SetInt(id1, value1); 
		SetInt(id2, value2);
	}

};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.p);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.p.x, dlg.p.y);
		EndDialog(dlg, 1);
	}
	return 0;
}
