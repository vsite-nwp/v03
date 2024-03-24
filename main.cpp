#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <iostream>

class main_dialog : public vsite::nwp::dialog 
{
	public: POINT koordinata;

protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		//set initial values to edit controls
		set_int(IDC_EDIT1, koordinata.x);
		set_int(IDC_EDIT2, koordinata.y);

		return true;
	}
	bool on_ok() override
	{
		//get current values from edit controls
		try {
			koordinata.x = get_int(IDC_EDIT1);
			koordinata.y = get_int(IDC_EDIT2);
		}
		//if not valid return false
		catch (const std::runtime_error& ex) {
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
	//find current mouse position and transfer to dialog
	GetCursorPos(&dlg.koordinata);

	if(dlg.do_modal(instance, 0) == IDOK)
	{
		//set mouse position to coordinates from dialog
		SetCursorPos(dlg.koordinata.x, dlg.koordinata.y);
	}
	return 0;
}
