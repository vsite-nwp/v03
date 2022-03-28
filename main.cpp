#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"
#include <stdexcept>

using namespace std;

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT point;


protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override
	{
		set_int(IDC_EDIT1, point.x);
		set_int(IDC_EDIT2, point.y);
		return true;
	}
	bool on_ok() override
	{
		try {
			point.x = get_int(IDC_EDIT1);
			point.y = get_int(IDC_EDIT2);
		}
		/*catch (const bool runtime_error) {
			return false;
		}*/
		catch (std::runtime_error& e) {
			//cout << e.what() << "\n";
			//MessageBox(hw, e.wath(), "NWP", MB_ICONWARNING | MB_OK);
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
	GetCursorPos(&dlg.point);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.point.x, dlg.point.y);
	}
	return 0;
}
