// cam.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "cam.h"
#include "camDlg.h"
#include "mmsystem.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString		def_sound(L"notify1.wav");
CString		approot;


/////////////////////////////////////////////////////////////////////////////
// CCamApp

BEGIN_MESSAGE_MAP(CCamApp, CWinApp)
	//{{AFX_MSG_MAP(CCamApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamApp construction

CCamApp::CCamApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCamApp object

CCamApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCamApp initialization

BOOL CCamApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Get where the application lives
	TCHAR *buff = approot.GetBuffer(MAX_PATH + 1);
	GetModuleFileName(AfxGetInstanceHandle(), buff, MAX_PATH);

	// Get application root
	TCHAR *ptr = _tcsrchr(buff, '\\');
	if(ptr)
		*(ptr+1) = '\0';

	approot.ReleaseBuffer();
	
	//PlaySnd();
	
	CCamDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CCamApp::PlaySnd()
{
	CString alarmsound = approot + def_sound;
	PlaySound(alarmsound, NULL, SND_FILENAME | SND_ASYNC );
}

BOOL CCamApp::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinApp::PreTranslateMessage(pMsg);
}
