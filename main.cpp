#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <exception>

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
		// set initial values to edit controls
		set_int(IDC_EDIT1, coords.x);
		set_int(IDC_EDIT2, coords.y);
		return true;
	}
	bool on_ok() override
	{
		// get current values from edit controls
		// if not valid return false
		try
		{
			if (get_int(IDC_EDIT1) < 0 || get_int(IDC_EDIT2) < 0) {
				return false;
			}
			get_int(IDC_EDIT1);
			get_int(IDC_EDIT2);
		}
		catch(const std::exception&)
		{
			return false;
		}
		coords.x= get_int(IDC_EDIT1);
		coords.y= get_int(IDC_EDIT2);
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.coords);
	// find current mouse position and transfer to dialog
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// set mouse position to coordinates from dialog
		SetCursorPos(dlg.coords.x,dlg.coords.y);
	}
	return 0;
}