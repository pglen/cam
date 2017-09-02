//

#if !defined(AFX_CAM_H__CEE89614_29C8_4C81_BFFB_4596664D05B3__INCLUDED_)
#define AFX_CAM_H__CEE89614_29C8_4C81_BFFB_4596664D05B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "../../common/work2/label.h"

class CCamDlg: public CDialog
{
public:

	CCamDlg(CWnd* pParent=NULL);
	BOOL InitInstance();
	void DoDataExchange(CDataExchange* pDX);

	HICON	m_hIcon;
	int created;
	int m_nWidth, m_nHeight;

	CBitmap m_bitmap;

	CLabel m_num1;
	CLabel m_num2;
	CLabel m_num3;
	CLabel m_num4;
	CLabel m_num5;
	CLabel m_num6;
	CLabel m_num7;
	CLabel m_num8;
	CLabel m_num9;
	CLabel m_status;

protected:
	void CCamDlg::ReSize(int cx, int cy);

	// Dialog Data
	//{{AFX_DATA(CMsgBox)
	enum { IDD = IDD_CAM_DIALOG};
	
	//}}AFX_DATA

	// Generated message map functions
	//{{AFX_MSG(CCamDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);


	//afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif