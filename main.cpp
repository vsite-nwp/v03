#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

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
		set_int(IDC_EDIT1, p.x);
		set_int(IDC_EDIT2, p.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			p.x = get_int(IDC_EDIT1);
			p.y = get_int(IDC_EDIT2);
		}
		catch (const std::runtime_error& e) {
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
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.p.x, dlg.p.y);
	}
	return 0;
}
