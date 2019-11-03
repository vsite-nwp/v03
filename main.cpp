#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog
{
	
	public:
		POINT cur;
	protected:
		int IDD()
		{
			return IDD_DIALOG1;
		}
		bool OnInitDialog()
		{
			SetInt(IDC_EDIT1, cur.x);
			SetInt(IDC_EDIT2, cur.y);
			return true;

		}
		bool OnOK()

		{

			try
			{
				cur.x = GetInt(IDC_EDIT1);
				cur.y = GetInt(IDC_EDIT2);
			}
			catch (XCtrl)
			{
				return false;
			}

			return true;

		}
	
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.cur);
	if (dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.cur.x, dlg.cur.y);

	}
	return 0;
}
