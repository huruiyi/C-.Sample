// 03CStaticTextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "03CStaticText.h"
#include "03CStaticTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// CMy03CStaticTextDlg 对话框

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

// CMy03CStaticTextDlg 消息处理程序

BOOL CMy03CStaticTextDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
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

    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);			// 设置大图标
    SetIcon(m_hIcon, FALSE);		// 设置小图标

    // TODO: 在此添加额外的初始化代码

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
//
//SW_SHOWMINIMIZED：激活窗口并将其最小化。

    m_cmb_grade.AddString(TEXT("1级"));
    m_cmb_grade.AddString(TEXT("2级"));
    m_cmb_grade.AddString(TEXT("3级"));
    m_cmb_grade.AddString(TEXT("4级"));
    m_cmb_grade.AddString(TEXT("5级"));
    m_cmb_grade.AddString(TEXT("6级"));

    m_cmb_grade.SetCurSel(2);
    //设置： data:1;2;3;4;5;6;
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy03CStaticTextDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMy03CStaticTextDlg::OnBnClickedButtonSethehe()
{
    // TODO: 在此添加控件通知处理程序代码

    m_text.SetWindowTextW(TEXT("呵呵🙂"));
}

void CMy03CStaticTextDlg::OnBnClickedButtonGettext()
{
    // TODO: 在此添加控件通知处理程序代码
    CString  str;
    m_text.GetWindowTextW(str);
    MessageBox(str);
}

void CMy03CStaticTextDlg::OnBnClickedButtonSetter()
{
    // TODO: 在此添加控件通知处理程序代码
    m_btn_setter.SetWindowTextW(TEXT("HELLO"));

    CString str;
    m_btn_setter.GetWindowTextW(str);
    MessageBox(str);

    m_btn_setter.EnableWindow(FALSE);
}

void CMy03CStaticTextDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

    CDialogEx::OnMouseMove(nFlags, point);

    CString str;
    str.Format(TEXT("X=%d   Y=%d"), point.x, point.y);
    m_text.SetWindowTextW(str);

    m_btn_fly.SetWindowPos(NULL, point.x, point.y, 0, 0, SW_SHOWNORMAL);
}

void CMy03CStaticTextDlg::OnCbnEditchangeComboxGrade()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;

    //m_cmb_grade.GetWindowTextW(str);

    MessageBox(str);

    MessageBox(TEXT("4级"));
}

void CMy03CStaticTextDlg::OnBnClickedButtonAdditem()
{
    // TODO: 在此添加控件通知处理程序代码
    m_cmb_grade.AddString(TEXT("9级"));
}

void CMy03CStaticTextDlg::OnCbnSelchangeComboxGrade()
{
    // TODO: 在此添加控件通知处理程序代码

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