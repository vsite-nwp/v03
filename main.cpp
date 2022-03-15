#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT c;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		
		set_int(IDC_EDIT1, c.x);
		set_int(IDC_EDIT2, c.y);
		return true;
	}
	bool on_ok() override
	{
		
		try {
			c.x = get_int(IDC_EDIT1);
			c.y = get_int(IDC_EDIT2);


		}

		catch (std::runtime_error exception) {
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
	
	GetCursorPos(&dlg.c);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		
		SetCursorPos(dlg.c.x, dlg.c.y);
	}

	return 0;
}
