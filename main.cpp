#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>  // I added this.

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT p;

protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		// TODO: set initial values to edit controls
		set_int(IDC_EDIT1, p.x);
		set_int(IDC_EDIT2, p.y);
		return true;
	}
	bool on_ok() override
	{
		// TODO: get current values from edit controls
		// TODO: if not valid return false
		try {
			p.x = get_int(IDC_EDIT1);
			p.y = get_int(IDC_EDIT2);
		}
		catch (std::runtime_error) {
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
	// TODO: find current mouse position and transfer to dialog
	::GetCursorPos(&dlg.p);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		::SetCursorPos(dlg.p.x, dlg.p.y);
	}
	return 0;
}
