#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT koor;

protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, koor.x);
		set_int(IDC_EDIT2, koor.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			koor.x = get_int(IDC_EDIT1);
			koor.y = get_int(IDC_EDIT2);
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
	GetCursorPos(&dlg.koor);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.koor.x, dlg.koor.y);
	}
	return 0;
}
