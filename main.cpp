#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

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
		set_int(IDC_EDIT1, cursorPoint.x);
		set_int(IDC_EDIT2, cursorPoint.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			cursorPoint.x = get_int(IDC_EDIT1);
			cursorPoint.y = get_int(IDC_EDIT2);
			return true;
		}
		catch (const std::exception& e)
		{
			// Just inform about the error
			MessageBox(*this, e.what(), "ERROR", MB_OK);
			return false;
		}
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
