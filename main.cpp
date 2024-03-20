#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include "iostream"

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT point_of_cursor;

protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		// DID_IT: set initial values to edit controls
		dialog::set_int(IDC_EDIT1, point_of_cursor.x);
		dialog::set_int(IDC_EDIT2, point_of_cursor.y);
		return true;
	}
	bool on_ok() override
	{
		// DID_IT: get current values from edit controls
		// DID_IT: if not valid return false
		try {
			point_of_cursor.x = dialog::get_int(IDC_EDIT1);
			point_of_cursor.y = dialog::get_int(IDC_EDIT2);
			return true;
		}
		catch (const std::runtime_error& e){
			return false;
		}
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	// DID_IT: find current mouse position and transfer to dialog

	GetCursorPos(&dlg.point_of_cursor);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		// TODO: set mouse position to coordinates from dialog
		SetCursorPos(dlg.point_of_cursor.x, dlg.point_of_cursor.y);
	}
	return 0;
}
