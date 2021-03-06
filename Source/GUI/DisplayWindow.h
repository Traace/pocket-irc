#ifndef _DISPLAYWINDOW_H_INCLUDED_
#define _DISPLAYWINDOW_H_INCLUDED_

#include "Window.h"
#include "View.h"

#include "IDisplayWindow.h"
#include "MainWindow.h"

class DisplayWindow : 
	public Window,
	public IDisplayWindow,
	public ITabWindow
{
public:
	enum DISPLAY_IDC { IDC_VIEW = 100 };

	DisplayWindow();
	virtual ~DisplayWindow();

	HRESULT Create();

	virtual void SetMainWindow(MainWindow* pMainWindow);

// IDisplayWindow
	virtual const tstring& GetKey();
	virtual void SetKey(const tstring& sTitle);

	virtual const tstring& GetTitle();
	virtual void SetTitle(const tstring& sTitle);

	virtual int GetHighlight();
	virtual void SetHighlight(int iHighlight);

	virtual void Print(const tstring& sText);
	virtual void PrintEvent(const DisplayEvent& displayEvent);

	virtual void OnEvent(const NetworkEvent& networkEvent);

	virtual void Close();

// ITabWindow
	virtual HWND GetTabWindow(){ return GetWindow(); }
	virtual const tstring GetTabTitle(){ return GetText(); }
	virtual void OnOptionsChanged(){ m_View.Update(true); }
	virtual void DoDefaultAction();
	virtual void DoMenu(POINT pt);

protected:
	virtual LRESULT WndProc(UINT msg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
	virtual void OnDestroy(WPARAM wParam, LPARAM lParam);
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
	virtual void OnActivate(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnNotify(WPARAM wParam, LPARAM lParam);

	virtual bool OnTabMenuCommand(UINT idCmd) { return false; }

	void DoOffChannelMenu(WORD x, WORD y, const tstring& sChannel);
	void DoUrlMenu(WORD x, WORD y, const tstring& sUrl);

	MainWindow* m_pMainWindow;

	tstring m_sKey;
	tstring m_sTitle;
	int m_iHighlight;
	bool m_bActive;

	View m_View;
	HMENU m_hMenu;
};

#endif//_DISPLAYWINDOW_H_INCLUDED_
