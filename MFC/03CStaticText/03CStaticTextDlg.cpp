﻿#include "stdafx.h"
#include "03CStaticText.h"
#include "03CStaticTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CMy03CStaticTextDlg::CMy03CStaticTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY03CSTATICTEXT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy03CStaticTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_text);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_BUTTON_Setter, m_btn_setter);
	DDX_Control(pDX, IDC_COMBOX_Grade, m_cmb_grade);
	DDX_Control(pDX, IDC_BUTTON_AddItem, m_btn_AddItem);
	DDX_Control(pDX, IDC_BUTTON_Fly, m_btn_fly);
	DDX_Control(pDX, IDC_LIS_Person, m_list_Control);
}

BEGIN_MESSAGE_MAP(CMy03CStaticTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SetHehe, &CMy03CStaticTextDlg::OnBnClickedButtonSethehe)
	ON_BN_CLICKED(IDC_BUTTON_GetText, &CMy03CStaticTextDlg::OnBnClickedButtonGettext)
	ON_BN_CLICKED(IDC_BUTTON_Setter, &CMy03CStaticTextDlg::OnBnClickedButtonSetter)
	ON_WM_MOUSEMOVE()
	ON_CBN_EDITCHANGE(IDC_COMBOX_Grade, &CMy03CStaticTextDlg::OnCbnEditchangeComboxGrade)
	ON_BN_CLICKED(IDC_BUTTON_AddItem, &CMy03CStaticTextDlg::OnBnClickedButtonAdditem)
	ON_CBN_SELCHANGE(IDC_COMBOX_Grade, &CMy03CStaticTextDlg::OnCbnSelchangeComboxGrade)
END_MESSAGE_MAP()

BOOL CMy03CStaticTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	CRect rect;
	m_pic.GetWindowRect(rect);
	m_pic.SetBitmap(HBMP(TEXT("./res/pic.bmp"), rect.Width(), rect.Height()));

	this->SetWindowTextW(TEXT("XXXXXXXXXXXXXXXXXXXXXXXXXXXX"));
	//this->SetWindowPos(NULL, 220, 220, 0, 0, SW_SHOWNORMAL);//1禁止改变窗口大小
	//this->ShowWindow(SW_MAXIMIZE);//窗口最大化
	//this->ShowWindow(SW_MINIMIZE);//窗口最小化
	//

	this->MoveWindow(50, 100, 900, 900);  //调整对话框的位置和大小

//SW_SHOWMAXIMIZED：激活窗口并将其最大化。
//SW_SHOWMINIMIZED：激活窗口并将其最小化。

	m_cmb_grade.AddString(TEXT("1级"));
	m_cmb_grade.AddString(TEXT("2级"));
	m_cmb_grade.AddString(TEXT("3级"));
	m_cmb_grade.AddString(TEXT("4级"));
	m_cmb_grade.AddString(TEXT("5级"));
	m_cmb_grade.AddString(TEXT("6级"));

	m_cmb_grade.SetCurSel(2);
	//设置： data:1;2;3;4;5;6;
	//m_list_Control.InsertItem(LVIF_TEXT | LVIF_STATE, 0, TEXT("第一列"), LVIS_SELECTED, LVIS_SELECTED, 0, 0);
	//m_list_Control.InsertItem(LVIF_TEXT | LVIF_STATE, 1, TEXT("第二列"), LVIS_SELECTED, LVIS_SELECTED, 0, 0);
	//m_list_Control.InsertItem(LVIF_TEXT | LVIF_STATE, 2, TEXT("第三列"), LVIS_SELECTED, LVIS_SELECTED, 0, 0);
	//m_list_Control.InsertItem(LVIF_TEXT | LVIF_STATE, 3, TEXT("第四列"), LVIS_SELECTED, LVIS_SELECTED, 0, 0);

	m_list_Control.SetExtendedStyle(m_list_Control.GetExtendedStyle() | LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_list_Control.InsertColumn(0, TEXT("第一列"), LVCFMT_CENTER, 100, 0);
	m_list_Control.InsertColumn(1, TEXT("第二列"), LVCFMT_CENTER, 100, 0);
	m_list_Control.InsertColumn(2, TEXT("第三列"), LVCFMT_CENTER, 100, 0);
	m_list_Control.InsertColumn(3, TEXT("第四列"), LVCFMT_CENTER, 100, 0);

	m_list_Control.InsertItem(0, TEXT("第一列数据"));
	m_list_Control.SetItemText(0, 1, TEXT("第二列数据"));
	m_list_Control.SetItemText(0, 2, TEXT("第三列数据"));
	m_list_Control.SetItemText(0, 3, TEXT("第四列数据"));

	m_list_Control.InsertItem(1, TEXT("第一列数据"));
	m_list_Control.SetItemText(1, 1, TEXT("第二列数据"));
	m_list_Control.SetItemText(1, 2, TEXT("第三列数据"));
	m_list_Control.SetItemText(1, 3, TEXT("第四列数据"));

	m_list_Control.InsertItem(2, TEXT("第一列数据"));
	m_list_Control.SetItemText(2, 1, TEXT("第二列数据"));
	m_list_Control.SetItemText(2, 2, TEXT("第三列数据"));
	m_list_Control.SetItemText(2, 3, TEXT("第四列数据"));

	m_list_Control.InsertItem(3, TEXT("第一列数据"));
	m_list_Control.SetItemText(3, 1, TEXT("第二列数据"));
	m_list_Control.SetItemText(3, 2, TEXT("第三列数据"));
	m_list_Control.SetItemText(3, 3, TEXT("第四列数据"));

	// m_list_Control View==>Report

#if 1 /*创建系统托盘图标*/
	NOTIFYICONDATA nd;//类成员变量
					  //创建托盘图标
	nd.cbSize = sizeof(NOTIFYICONDATA);
	nd.hWnd = m_hWnd;
	nd.uID = IDR_MAINFRAME;
	nd.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	//nd.uCallbackMessage = WM_NOTIFYICON;
	nd.hIcon = m_hIcon;

	lstrcpyn(nd.szTip, TEXT("信息管理系统"), sizeof(TEXT("信息管理系统")));
	Shell_NotifyIcon(NIM_ADD, &nd);
#endif // 1 /*创建系统托盘图标*/

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy03CStaticTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CMy03CStaticTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMy03CStaticTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy03CStaticTextDlg::OnBnClickedButtonSethehe()
{
	m_text.SetWindowTextW(TEXT("呵呵🙂"));
}

void CMy03CStaticTextDlg::OnBnClickedButtonGettext()
{
	CString  str;
	m_text.GetWindowTextW(str);
	MessageBox(str);
}

void CMy03CStaticTextDlg::OnBnClickedButtonSetter()
{
	m_btn_setter.SetWindowTextW(TEXT("HELLO"));

	CString str;
	m_btn_setter.GetWindowTextW(str);
	MessageBox(str);

	m_btn_setter.EnableWindow(FALSE);
}

void CMy03CStaticTextDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);

	CString str;
	str.Format(TEXT("X=%d   Y=%d"), point.x, point.y);
	m_text.SetWindowTextW(str);

	m_btn_fly.SetWindowPos(NULL, point.x, point.y, 0, 0, SW_SHOWNORMAL);
}

void CMy03CStaticTextDlg::OnCbnEditchangeComboxGrade()
{
	CString str;

	//m_cmb_grade.GetWindowTextW(str);

	MessageBox(str);

	MessageBox(TEXT("4级"));
}

void CMy03CStaticTextDlg::OnBnClickedButtonAdditem()
{
	m_cmb_grade.AddString(TEXT("9级"));
}

void CMy03CStaticTextDlg::OnCbnSelchangeComboxGrade()
{
	CString str;
	int index = m_cmb_grade.GetCurSel();
	m_cmb_grade.GetLBText(index, str);
	MessageBox(str);
}

/*
在Windows编程中，经常会碰到字符串之间的转换，char*转LPCWSTR也是其中一个比较常见的转换。下面就列出几种比较常用的转换方法。
1、通过MultiByteToWideChar函数转换
MultiByteToWideChar函数是将多字节转换为宽字节的一个API函数，它的原型如下：
[cpp] view plain copy
int MultiByteToWideChar(
UINT CodePage,         // code page
DWORD dwFlags,         // character-type options
LPCSTR lpMultiByteStr, // string to map
int cbMultiByte,       // number of bytes in string
LPWSTR lpWideCharStr,  // wide-character buffer
int cchWideChar        // size of buffer
);
LPCWSTR实际上也是CONST WCHAR *类型

[cpp] view plain copy
char* szStr = "测试字符串";
WCHAR wszClassName[256];
memset(wszClassName,0,sizeof(wszClassName));
MultiByteToWideChar(CP_ACP,0,szStr,strlen(szStr)+1,wszClassName,
sizeof(wszClassName)/sizeof(wszClassName[0]));

2、通过T2W转换宏
[cpp] view plain copy
char* szStr = "测试字符串";
CString str = CString(szStr);
USES_CONVERSION;
LPCWSTR wszClassName = new WCHAR[str.GetLength()+1];
wcscpy((LPTSTR)wszClassName,T2W((LPTSTR)str.GetBuffer(NULL)));
str.ReleaseBuffer();

3、通过A2CW转换
[cpp] view plain copy
char* szStr = "测试字符串";
CString str = CString(szStr);
USES_CONVERSION;
LPCWSTR wszClassName = A2CW(W2A(str));
str.ReleaseBuffer();

上述方法都是UniCode环境下测试的。
*/