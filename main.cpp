#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT cursor;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, cursor.x);
		set_int(IDC_EDIT2, cursor.y);
		return true;
	}
	bool on_ok() override
	{
		try
		{
			cursor.x = get_int(IDC_EDIT1);
			cursor.y = get_int(IDC_EDIT2);
		}
		catch (std::runtime_error& e) { return false; }
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.cursor);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.cursor.x, dlg.cursor.y);
	}
	return 0;
}