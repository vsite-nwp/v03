#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>
#include <exception>

class main_dialog : public vsite::nwp::dialog
{
public:
	POINT point;
protected:
	int idd() const override
	{
		return IDD_DIALOG1;
	}
	bool on_init_dialog() override
	{
		// TODO: set initial values to edit controls
		set_int(IDC_EDIT1, point.x);
		set_int(IDC_EDIT2, point.y);
		return true;
	}
	bool on_ok() override
	{
		// TODO: get current values from edit controls
		// TODO: if not valid return false
		try {
			point.x = get_int(IDC_EDIT1);
			point.y = get_int(IDC_EDIT2);
			return true;
		}
		catch (std::runtime_error& e) {
			return false;

		}
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.point);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(dlg.point.x, dlg.point.y);
	}
	return 0;
}
