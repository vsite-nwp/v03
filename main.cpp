#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <exception>

using namespace std;

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT kordinata;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, kordinata.x);
		set_int(IDC_EDIT2, kordinata.y);
		return true;
	}
	bool on_ok() override
	{
		try
		{
			kordinata.x = get_int(IDC_EDIT1);
			kordinata.y = get_int(IDC_EDIT2);
		}
		catch (exception& e){return false;}
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.kordinata);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.kordinata.x, dlg.kordinata.y);
	}
	return 0;
}
