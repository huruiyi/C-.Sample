#pragma once

// CDialogShow �Ի���

class CDialogShow : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogShow)

public:
	CDialogShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogShow();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Show };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
