// camDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cam.h"
#include "camDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib, "msimg32.lib")

#include "../../common/work2/memdc.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamDlg dialog

CCamDlg::CCamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCamDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_created = 0;
	m_prog = 0;
}

void CCamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCamDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here

	DDX_Control(pDX, IDC_NUM1, m_num1);
	DDX_Control(pDX, IDC_NUM2, m_num2);
	DDX_Control(pDX, IDC_NUM3, m_num3);
	DDX_Control(pDX, IDC_NUM4, m_num4);
	DDX_Control(pDX, IDC_NUM5, m_num5);
	DDX_Control(pDX, IDC_NUM6, m_num6);
	DDX_Control(pDX, IDC_NUM7, m_num7);
	DDX_Control(pDX, IDC_NUM8, m_num8);
	DDX_Control(pDX, IDC_NUM9, m_num9);
	//DDX_Control(pDX, IDC_STATUS, m_status);

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCamDlg, CDialog)
	//{{AFX_MSG_MAP(CCamDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_QUERYENDSESSION()
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamDlg message handlers

BOOL CCamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	WORD wVersionRequested;   WSADATA wsaData;
	int	err;

	wVersionRequested = MAKEWORD( 2, 2 );
    err = WSAStartup( wVersionRequested, &wsaData );

    if ( err != 0 )
        {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        AfxMessageBox ("Cannot initialize Windows Socket, networking functions will not be available.");
        //return;
        }

    //P2N("Winsock Ver %d.%d %s \r\n", HIBYTE(wsaData.wVersion), LOBYTE(wsaData.wVersion), wsaData.szDescription);
    //Exception();


	m_bitmap.LoadBitmap(IDB_BITMAP2);
	//ASSERT(m_bitmap == NULL);
	
	BITMAP BitMap;
    m_bitmap.GetBitmap(&BitMap);
    m_nWidth = BitMap.bmWidth;
    m_nHeight = BitMap.bmHeight;

	 // Cheat on the Desktop one pixel for poppable status bar
    HDC     hdc     = ::GetDC(HWND_DESKTOP);
    int     xsize   =  ::GetDeviceCaps(hdc, HORZRES);
    int     ysize   =  ::GetDeviceCaps(hdc, VERTRES);

    //SetWindowPos( NULL, 1, 1, xsize - 2, ysize - 2, SWP_NOZORDER);
	SetWindowPos( NULL, 0, 0, xsize - 0, ysize - 0, SWP_NOZORDER);

	m_created = 1;		

	SetScroller("No Bus Passes, Food Active, Volunteers Needed. CAM is CLOSED on Wed 3/14/2015");
	//SetScroller("No Messages Today");
	ReSize(xsize, ysize) ;
	
	SetTimer(0, 200, NULL);
	SetTimer(1, 10, NULL);

	P2N("Started cam\n");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCamDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCamDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCamDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CCamDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	RECT rect; GetClientRect(&rect);  

	//CBrush NewBrush(0x0888800);
	//CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&NewBrush);
	//pDC->SetBrushOrg(0,0) ;
    //pDC->PatBlt(rect.left, rect.top, rect.right-rect.left, 
	//		rect.bottom-rect.top ,PATCOPY);
    //return 1;
#if 1
	
    // Pre render before background is erased

    {
	CSaveDC sdc(pDC);

	// Clear it with a brush first

	CBrush NewBrush(0x0555555);
	CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&NewBrush);
	pDC->SetBrushOrg(0,0) ;
    pDC->PatBlt(rect.left, rect.top, rect.right-rect.left, 
			rect.bottom-rect.top ,PATCOPY);
    
    CDC  dcMem; dcMem.CreateCompatibleDC(pDC);
	int save = dcMem.SaveDC();

    CBitmap *pOldBitmap = dcMem.SelectObject(&m_bitmap);


    int xx = 0, yy = 0, 
			ww = rect.right-rect.left, hh = rect.bottom-rect.top;
    int loopx = 0, loopy = 0;
	int cx = 500; int cy = 500;

	// Alpha blend
    BLENDFUNCTION m_bf; 
	
	m_bf.BlendOp	= AC_SRC_OVER;					
	m_bf.BlendFlags = 0;							
	m_bf.SourceConstantAlpha = 20;
	m_bf.AlphaFormat = 0;							
		
	// Put it out
	//AlphaBlend(pDC->GetSafeHdc(), xx, yy, cx, cy, 
	//					dcMem.GetSafeHdc(), 0, 0, cx, cy, m_bf); 	


	//pDC->BitBlt(loopx, loopy, m_nWidth, m_nHeight, 
	//				&dcMem, 0,0, SRCCOPY );
            
    for (loopy = 0; loopy < hh; loopy += m_nHeight)
        {
        for (loopx = 0; loopx < ww; loopx += m_nWidth)
            {
			// Put it out
			AlphaBlend(pDC->GetSafeHdc(), loopx, loopy, m_nWidth, m_nHeight,
							dcMem.GetSafeHdc(), 0, 0, m_nWidth, m_nHeight, m_bf); 	
	       //pDC->BitBlt(loopx, loopy, m_nWidth, m_nHeight, 
			//		&dcMem, 0,0, SRCCOPY );
            }
        }
    dcMem.SelectObject(pOldBitmap);

	dcMem.RestoreDC(save);
	//pDC->SelectObject(pOldBrush);
	}

#endif

	//return CDialog::OnEraseBkgnd(pDC);
	return 1;
}


void CCamDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));	
		
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CCamDlg::OnQueryEndSession() 
{
	if (!CDialog::OnQueryEndSession())
		return FALSE;
			
	return TRUE;
}

void CCamDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default	
	//AfxMessageBox("Query end");
	//CDialog::OnClose();
}

void CCamDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	//if (m_hWnd.isWindow() == 0)
	//		return

	if( m_created == 0)
		return;

	ReSize(cx, cy) ;
}

// -----------------------------------------------------------------------
// 

void CCamDlg::ReSize(int cx, int cy) 

{
	int xsize = cx; int ysize = cy;
	
	int step	= xsize / 2;
	int fstep	= ysize / 2;
	int xstep	= ysize / 12;
	int gap		= xsize / 32;
	int row = 5 * ysize / 8;
	
	// -----------------------------------------------

	m_num1.SetWindowPos(NULL, gap, ysize / 16, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num1.CenterText();
	m_num1.SetFontSize(fstep);
	m_num1.SetTextColor(RGB(0x40, 0x00, 0x00));
	m_num1.SetText("01");
	
	m_num4.SetWindowPos(NULL, gap, gap, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num4.SetFontSize(xstep);
	m_num4.CenterText();
	m_num4.SetText("Food");
	m_num4.SetTextColor(RGB(0xff, 00, 00));
	
	m_num7.SetWindowPos(NULL, gap, 9 * ysize / 16 + gap, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num7.CenterText();
	m_num7.SetFontSize(xstep);
	m_num7.SetText("Active");
	m_num7.SetTextColor(RGB(0x00, 00, 00));
	
	// ----------------------------------------------

	m_num2.SetWindowPos(NULL, step + gap, ysize / 16, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num2.CenterText();
	m_num2.SetFontSize(fstep);
	m_num2.SetTextColor(RGB(0x00, 0x40, 0x00));
	m_num2.SetText("02");
	
	m_num5.SetWindowPos(NULL, step + 2 * gap, gap, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num5.CenterText();
	m_num5.SetFontSize(xstep);
	m_num5.SetText("Bus Pass");
	m_num5.SetTextColor(RGB(0x00, 0xff, 00));
	
	m_num8.SetWindowPos(NULL, gap + step, 9 * ysize / 16 + gap, step - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num8.CenterText();
	m_num8.SetFontSize(xstep);
	m_num8.SetText("Active");
	m_num8.SetTextColor(RGB(0x00, 00, 00));
	
	// -----------------------------------------------

	m_num3.SetFontSize(fstep / 2);
	m_num3.CenterText();
	m_num3.SetWindowPos(NULL, step - fstep / 4, row, step / 2, ysize / 2,SWP_NOOWNERZORDER );
	m_num3.SetTextColor(RGB(0x00, 0x00, 0x40));
	m_num3.SetText("03");

	m_num6.SetWindowPos(NULL, step - fstep / 4, row - 2 * gap, step / 2 - gap, ysize / 2,SWP_NOOWNERZORDER );
	m_num6.CenterText();
	m_num6.SetFontSize(xstep);
	m_num6.SetText("Gas");
	m_num6.SetTextColor(RGB(0x00, 0x00, 0xff));

	// -----------------------------------------------
	
	m_num9.SetFontSize(xstep );
	m_num9.CenterText();
	m_num9.SetWindowPos(NULL, 4, ysize - 4 - xstep, xsize - 4, xstep, SWP_NOOWNERZORDER );

	// -----------------------------------------------
	
}

void CCamDlg::OnTimer(UINT nIDEvent) 

{	
	if(nIDEvent == 0)
		{
		int len = m_scroller.GetLength() ;

		if(m_scroller.GetLength() > 70) {
			m_num9.CenterText(FALSE);
			m_num9.SetWrap(FALSE);
			m_num9.SetSingle();
				  
			CString str3 = m_scroller.Mid(m_prog);  
			m_num9.SetText(str3);
			m_prog++; 

			if(m_prog > len)
				m_prog = 0;	

			}		
		}

	// Set up socket 
	if(nIDEvent == 1) {
		KillTimer(nIDEvent);

		char nd = 1;
		SOCKADDR_IN rec_sin, rec_sin2;

		int     rec_sin_len = sizeof(rec_sin), ndlen  = sizeof(char);
		int     ret_val;

		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		P2N("init Sockets %p\n", m_socket);
		setsockopt (m_socket, SOL_SOCKET, SO_REUSEADDR, &nd, sizeof(int));
    
		memset(&rec_sin, 0, sizeof(rec_sin));

		rec_sin.sin_addr.s_addr = INADDR_ANY;
		rec_sin.sin_port = htons(20000);
		rec_sin.sin_family = AF_INET;

		if (bind(m_socket, (struct sockaddr FAR *) &rec_sin, sizeof(rec_sin))
			== SOCKET_ERROR)
			{
			CString tmp("none"); int err = WSAGetLastError();
			//tmp.Format("%d %s", err, sockerr2str(err));

			TRACE("Cannot Bind socket on port %d %d %s\r\n", 
								rec_sin.sin_port, ntohs(rec_sin.sin_port), tmp);			
			}	
		int ret = WSAAsyncSelect(m_socket, m_hWnd, WM_USER, FD_ACCEPT);
		if (listen(m_socket, 1) < 0)
			{
			CString tmp("none"); int err = WSAGetLastError();
			//tmp.Format("%d is the error %s", err, mxpad.sockerr2str(err));

			TRACE("MxPad::AcceptThreadProc Cannot listen on socket2 %s\r\n", tmp);

			return;
			}
		

	}

	CDialog::OnTimer(nIDEvent);
}


void CCamDlg::SetScroller(const char *text) 

{
	//int len = strlen(text);
	int len = 60;

	m_org = text;

	CString str2;

	// Pad the beginning to match scroler
	for (int aa= 0 ; aa < len; aa++)
		str2 += " ";         

	str2 +=  text;
	
	// Scroller need special label atributes
	m_num9.SetWrap(FALSE);	
	m_num9.CenterText(true);		
	m_scroller = str2;
	m_num9.SetText(m_scroller);

	//P2N("Set scroller", text);

}


BOOL CCamDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_USER)
		{
		SOCKET sock = (SOCKET)pMsg->wParam;
		int event = LOWORD(pMsg->lParam); 

		P2N("WM_USER PreTranslateMessage %p %p", socket, event);		
		}

	return CDialog::PreTranslateMessage(pMsg);
}
