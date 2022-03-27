#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog 
{
	public:
	POINT pos;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, pos.x);
		set_int(IDC_EDIT2, pos.y);
		return true;
	}
	bool on_ok() override
	{
		try
		{
			get_int(IDC_EDIT1);
			get_int(IDC_EDIT2);
		}
		catch (...)//(XCtrl)
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
	GetCursorPos(&dlg.pos);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(
			dlg.pos.x,
			dlg.pos.y
		);
	}
	return 0;
}
