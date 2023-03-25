#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <exception>

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT pixel_coordinate;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		// set initial values to edit controls
		set_int(IDC_EDIT1, pixel_coordinate.x);
		set_int(IDC_EDIT2, pixel_coordinate.y);

		return true;
	}
	bool on_ok() override
	{
		// get current values from edit controls
		try
		{
			pixel_coordinate.x = get_int(IDC_EDIT1);
			pixel_coordinate.y = get_int(IDC_EDIT2);
		}

		catch (const std::exception& e)
		{
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

	// find current mouse position and transfer to dialog
	GetCursorPos(&dlg.pixel_coordinate);

	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// set mouse position to coordinates from dialog
		SetCursorPos(dlg.pixel_coordinate.x, dlg.pixel_coordinate.y);
	}
	return 0;
}
