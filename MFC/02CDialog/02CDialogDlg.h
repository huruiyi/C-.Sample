// 02CDialogDlg.h : ͷ�ļ�
//

#pragma once
#include"DialogShow.h"

// CMy02CDialogDlg �Ի���
class CMy02CDialogDlg : public CDialogEx
{
	// ����
public:
	CMy02CDialogDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY02CDIALOG_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExec();
	afx_msg void OnBnClickedButtonShow();
private:
	CDialogShow dlg;
};
