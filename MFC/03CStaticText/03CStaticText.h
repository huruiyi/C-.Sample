// 03CStaticText.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CMy03CStaticTextApp:
// �йش����ʵ�֣������ 03CStaticText.cpp
//

class CMy03CStaticTextApp : public CWinApp
{
public:
	CMy03CStaticTextApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy03CStaticTextApp theApp;
