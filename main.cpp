#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

class main_dialog : public vsite::nwp::dialog 
{
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, coordinates.x);
		set_int(IDC_EDIT2, coordinates.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			coordinates.x = get_int(IDC_EDIT1);
			coordinates.y = get_int(IDC_EDIT2);
		}
		catch (std::runtime_error exception) { return false; }
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
public:
	POINT coordinates;
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.coordinates);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.coordinates.x, dlg.coordinates.y);
	}
	return 0;
}
