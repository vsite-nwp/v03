#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT p1;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		// set initial values to edit controls

		set_int(IDC_EDIT1, p1.x);
		set_int(IDC_EDIT2, p1.y);
		return true;
	}
	bool on_ok() override
	{
		// get current values from edit controls
		// if not valid return false
		try {
			p1.x = get_int(IDC_EDIT1);
			p1.y = get_int(IDC_EDIT2);
		}
		catch (std::runtime_error& e) {
			MessageBox(*this, e.what(), "Error", MB_OK | MB_ICONERROR);
			return false;
		}
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	// : find current mouse position and transfer to dialog
	GetCursorPos(&dlg.p1);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// : set mouse position to coordinates from dialog
		SetCursorPos(dlg.p1.x, dlg.p1.y);
	}
	return 0;
}
