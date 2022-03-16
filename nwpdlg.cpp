#include <windows.h>
#include "nwpdlg.h"
#include <map>
#include <stdexcept>

namespace vsite::nwp {

int CALLBACK dialog::proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
	static std::map<HWND, dialog*> wmap;
	if (msg == WM_INITDIALOG)
	{
		dialog* pd = reinterpret_cast<dialog*>(lp);
		pd->hw = hw;
		wmap[hw] = pd;
		return pd->on_init_dialog();
	}
	dialog* pd = wmap[hw];
	if (msg == WM_COMMAND)
	{
		if (LOWORD(wp) == IDOK && pd->on_ok())
			return ::EndDialog(hw, IDOK);
		if (LOWORD(wp) == IDCANCEL)
		{
			pd->on_cancel();
			return ::EndDialog(hw, IDCANCEL);
		}
		return pd->on_command(LOWORD(wp), HIWORD(wp));
	}
	if (msg == WM_DESTROY)
		wmap.erase(hw);
	return 0;
}

int dialog::do_modal(HINSTANCE hInst, HWND parent)
{
	return ::DialogBoxParam(hInst, MAKEINTRESOURCE(idd()), parent, proc,
		reinterpret_cast<LPARAM>(this));
}

void dialog::set_int(int idCtrl, int val)
{
	::SetDlgItemInt(*this, idCtrl, val, true);
}

int dialog::get_int(int idCtrl)
{
	BOOL b;
	int n = ::GetDlgItemInt(*this, idCtrl, &b, true);
	if (!b) throw XCtrl();
	return n;
}

} // namespace
