#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>
#include <iostream>

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT tocka;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, tocka.x);
		set_int(IDC_EDIT2, tocka.y);

		return true;
	}
	bool on_ok() override
	{
		try {
			tocka.x = get_int(IDC_EDIT1);
			tocka.y = get_int(IDC_EDIT2);
		}
		catch (std::runtime_error& ex) {
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
	GetCursorPos(&dlg.tocka);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.tocka.x, dlg.tocka.y);
	}
	return 0;
}
