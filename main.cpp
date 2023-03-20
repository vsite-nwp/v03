#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT cursorPoint; // to save cursor point
protected:

	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		SetDlgItemInt(*this, IDC_EDIT1, cursorPoint.x, false);
		SetDlgItemInt(*this, IDC_EDIT2, cursorPoint.y, false);
		return true;
	}
	bool on_ok() override
	{
		BOOL successX = false;
		BOOL successY = false;
		int x = GetDlgItemInt(*this, IDC_EDIT1, &successX, false);
		int y = GetDlgItemInt(*this, IDC_EDIT2, &successY, false);
		if (successX && successY)
		{
			cursorPoint.x = x;
			cursorPoint.y = y;
		}
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.cursorPoint);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.cursorPoint.x, dlg.cursorPoint.y);
	}
	return 0;
}
