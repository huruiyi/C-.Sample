// 03CStaticTextDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

// CMy03CStaticTextDlg 对话框
class CMy03CStaticTextDlg : public CDialogEx
{
    // 构造
public:
    CMy03CStaticTextDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MY03CSTATICTEXT_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
    HICON m_hIcon;

    // 生成的消息映射函数
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
};
