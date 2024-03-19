#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <typeinfo>
#include <iostream>

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
		// : set initial values to edit controls
		set_int(IDC_EDIT1, p.x);
		set_int(IDC_EDIT2, p.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			p.x = get_int(IDC_EDIT1);
			p.y = get_int(IDC_EDIT2);
			// : get current values from edit controls
			// : if not valid return false
			if (typeid(p.x) == typeid(int) || typeid(p.y) == typeid(int))
				throw std::exception();
		}
		catch (std::exception& e)
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
	GetCursorPos(&dlg.p);
	// : find current mouse position and transfer to dialog
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.p.x,dlg.p.y);
		// : set mouse position to coordinates from dialog
	}
	return 0;
}
