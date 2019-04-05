#include "mfc.h"
#include<Windows.h>
#include<WinUser.h>
#include "resource.h"

//在共享 DLL 中使用 MFC
WinApp app;

BOOL WinApp::InitInstance()
{
	MyFrame* frame = new  MyFrame;
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();
	m_pMainWnd = frame;
	return TRUE;
}

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	//ON_WM_LBUTTONDOWN(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, TEXT("Hello MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	TCHAR buf[1024];
	wsprintf(buf, TEXT("X=%d   Y=%d"), point.x, point.y);
	MessageBox(buf, TEXT("坐标"), SW_NORMAL);
	// MessageBox(buf);

	CString str;
	str.Format(TEXT("X=%d   Y=%d"), point.x, point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;
	str.Format(TEXT("你按下了键：%c"), nChar);
	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CTime theTime = CTime::GetCurrentTime();
	TCHAR* ch = TEXT("Hello World");

	CPaintDC dc(this);

	dc.Ellipse(10, 10, 500, 500);
	SetWindowText(TEXT("这是我的第一个MFC应用程序"));

	CFont font;
	font.CreatePointFont(100, TEXT("微软雅黑"));
	dc.SelectObject(&font);
	dc.SetBkColor(RGB(214, 219, 233));
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(64, 158, 254));
	dc.TextOut(100, 100, "Hello World,世界你好！！");

	dc.Draw3dRect(100, 200, 300, 100, RGB(214, 219, 233), RGB(64, 158, 254));

	HWND win = FindWindowA("Qt5QWindowIcon", "HydraViewer");//获取窗口
	if (win)
	{
		SetWindowTextA(win, "23期MFC课程讲解");
	}
}

void MyFrame::OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct)
{
}