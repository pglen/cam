// camcliDlg.h : header file
//

#if !defined(AFX_CAMCLIDLG_H__6A4C68E2_47A0_4F15_8DAF_771BBB5519C9__INCLUDED_)
#define AFX_CAMCLIDLG_H__6A4C68E2_47A0_4F15_8DAF_771BBB5519C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCamcliDlg dialog

class CCamcliDlg : public CDialog
{
// Construction
public:
	CCamcliDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCamcliDlg)
	enum { IDD = IDD_CAMCLI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamcliDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCamcliDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMCLIDLG_H__6A4C68E2_47A0_4F15_8DAF_771BBB5519C9__INCLUDED_)
