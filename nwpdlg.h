class XCtrl {};

class Dialog
{
	HWND hw;
public:
	static int CALLBACK Proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp);
	operator HWND() const { return hw; }
	int DoModal(HINSTANCE, HWND parent=0);
	
protected:
//	operations
	void SetInt(int idCtrl, int val);
	int GetInt(int idCtrl) throw (XCtrl);

//	overridables
	virtual int IDD() = 0;
	virtual bool OnInitDialog() { return false; }
	virtual bool OnCommand(int id, int code) { return false; }
	virtual bool OnOK() { return true; }
	virtual void OnCancel() { }
};
