// 03CStaticTextDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

// CMy03CStaticTextDlg �Ի���
class CMy03CStaticTextDlg : public CDialogEx
{
	// ����
public:
	CMy03CStaticTextDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY03CSTATICTEXT_DIALOG };
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
private:
	//Static Text
	CStatic m_text;
public:
	afx_msg void OnBnClickedButtonSethehe();
	afx_msg void OnBnClickedButtonGettext();
private:
	//Static Text
	CStatic m_pic;
	CButton m_btn_setter;
public:
	afx_msg void OnBnClickedButtonSetter();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CComboBox m_cmb_grade;
public:
	afx_msg void OnCbnEditchangeComboxGrade();
	afx_msg void OnBnClickedButtonAdditem();
private:
	CButton m_btn_AddItem;
public:
	afx_msg void OnCbnSelchangeComboxGrade();
private:
	CButton m_btn_fly;
	CListCtrl m_list_Control;
};
