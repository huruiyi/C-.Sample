// DialogShow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02CDialog.h"
#include "DialogShow.h"
#include "afxdialogex.h"

// CDialogShow �Ի���

IMPLEMENT_DYNAMIC(CDialogShow, CDialogEx)

CDialogShow::CDialogShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Show, pParent)
{
}

CDialogShow::~CDialogShow()
{
}

void CDialogShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDialogShow, CDialogEx)
END_MESSAGE_MAP()

// CDialogShow ��Ϣ�������