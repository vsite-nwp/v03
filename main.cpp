#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog
{
public:
	POINT coords;

protected:
	int idd() const override
	{
		return IDD_DIALOG1;
	}

	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, coords.x);
		set_int(IDC_EDIT2, coords.y);
		return true;
	}

	bool on_ok() override
	{
		try {
			coords.x = get_int(IDC_EDIT1);
			coords.y = get_int(IDC_EDIT2);
			return true;
		}
		catch (...) {
			return false;
		}
	}

	void on_cancel() override { }

	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	POINT position;
	GetCursorPos(&position);
	dlg.coords = position;
	if (dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.coords.x, dlg.coords.y);
	}
	return 0;
}
