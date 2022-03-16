
namespace vsite::nwp {

class XCtrl {};

class dialog
{
	HWND hw;
public:
	static int CALLBACK proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp);
	operator HWND() const { return hw; }
	int do_modal(HINSTANCE, HWND parent = 0);
protected:
//	operations
	void set_int(int id_ctrl, int val);
	int get_int(int id_ctrl) throw (XCtrl);

//	overridables
	virtual int idd() const = 0;
	virtual bool on_init_dialog() { return false; }
	virtual bool on_command(int id, int code) { return false; }
	virtual bool on_ok() { return true; }
	virtual void on_cancel() { }
};

} // namespace
