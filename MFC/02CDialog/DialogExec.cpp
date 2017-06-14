// DialogExec.cpp : 实现文件
//

#include "stdafx.h"
#include "02CDialog.h"
#include "DialogExec.h"
#include "afxdialogex.h"

// CDialogExec 对话框

IMPLEMENT_DYNAMIC(CDialogExec, CDialogEx)

CDialogExec::CDialogExec(CWnd* pParent /*=NULL*/)
    : CDialogEx(IDD_DIALOG_Exec, pParent)
{
}

CDialogExec::~CDialogExec()
{
}

void CDialogExec::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDialogExec, CDialogEx)
END_MESSAGE_MAP()

// CDialogExec 消息处理程序