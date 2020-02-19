#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT p;
	bool flag;
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
		BOOL b1 = false;
		BOOL b2 = false;
		p.x = GetDlgItemInt(*this, IDC_EDIT1, &b1, false);
		p.y = GetDlgItemInt(*this, IDC_EDIT2, &b2, false);
		flag = b1 && b2;
		if (!b1) {
			p.x = 0;
		}
		if (!b2) {
			p.y = 0;
		}
		Postavi(IDC_EDIT1, IDC_EDIT2, p.x, p.y);
		return flag;
	}
	void OnCancel()	{ EndDialog(*this, 2); }
	bool OnCommand(int id, int code) { return false; }
private:
	bool Postavi(int id1, int id2, int value1, int value2) {
		return (SetDlgItemInt(*this, id1, value1, false) && SetDlgItemInt(*this, id2, value2, false));
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
