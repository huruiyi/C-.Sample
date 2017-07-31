#pragma once
#include <afxwin.h>
class WinApp :public CWinApp
{
	virtual BOOL InitInstance();
};

class MyFrame :public CFrameWnd
{
public:
	MyFrame();

	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT, CPoint point);

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

	afx_msg void OnPaint();

	afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
};