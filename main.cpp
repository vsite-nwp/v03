#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
class MyDialog : public Dialog
{
public:
	POINT mseCrsr;
protected:
	int IDD()
	{
		return IDD_DIALOG1;
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, mPosition.x);
		SetInt(IDC_EDIT2, mPosition.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			mPosition.x = GetInt(IDC_EDIT1);
			mPosition.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&)
		{
			return false;
		}
		return true;
	}
	void OnCancel() { }
	bool OnCommand(int id, int code) { return false; }
public:
	POINT* operator*()
	{
		return &mPosition;
	}

	bool UpdatePos()
	{
		if (SetCursorPos(mPosition.x, mPosition.y) == 0)
		{
			return false;
		}
		return true;
	}
private:
	POINT mPosition;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(*dlg);

	if (dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(
			dlg.mseCrsr.x,
			dlg.mseCrsr.y
		);
	}
	return 0;
}