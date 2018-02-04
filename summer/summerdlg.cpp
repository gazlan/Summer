#include "stdafx.h"

#include "..\shared\mmf.h"
#include "..\shared\file.h"

#include "Summer.h"
#include "SummerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CSummerDlg::CSummerDlg(CWnd* pParent /*=NULL*/)
:  CDialog(CSummerDlg::IDD, pParent)
{
   //{{AFX_DATA_INIT(CSummerDlg)
   _sRich = _T("");
   _sSum = _T("");
   //}}AFX_DATA_INIT
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSummerDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CSummerDlg)
   DDX_Text(pDX, IDC_RICH, _sRich);
   DDV_MaxChars(pDX, _sRich, 65535);
   DDX_Text(pDX, IDC_EDT_SUM, _sSum);
   DDV_MaxChars(pDX, _sSum, 255);
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSummerDlg, CDialog)
   //{{AFX_MSG_MAP(CSummerDlg)
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_NOTIFY(NM_CLICK, IDC_RICH, OnClickRich)
   ON_WM_DESTROY()
   ON_BN_CLICKED(IDC_BTN_EQU, OnBtnEqu)
   ON_BN_CLICKED(IDC_BTN_CLEAR, OnBtnClear)
   ON_BN_CLICKED(IDC_BTN_SAVE, OnBtnSave)
   ON_BN_CLICKED(IDC_BTN_LOAD, OnBtnLoad)
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSummerDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);       // Set big icon
   SetIcon(m_hIcon, FALSE);      // Set small icon
   
   CenterWindow();
   
   CRichEditCtrl*    pRich = (CRichEditCtrl*)GetDlgItem(IDC_RICH);

   ASSERT(pRich);

   if (pRich)
   {
      CHARFORMAT     CF;

      CF.dwMask    = CFM_BOLD | CFM_SIZE;
      CF.dwEffects = CFE_BOLD;
      CF.yHeight   = 360;

      pRich->SetDefaultCharFormat(CF);
   }

   CRichEditCtrl*    pSum = (CRichEditCtrl*)GetDlgItem(IDC_EDT_SUM);

   ASSERT(pSum);

   if (pSum)
   {
      CHARFORMAT     CF;

      CF.dwMask    = CFM_BOLD | CFM_SIZE;
      CF.dwEffects = CFE_BOLD;
      CF.yHeight   = 360;

      pSum->SetDefaultCharFormat(CF);
   }

   return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSummerDlg::OnPaint() 
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
HCURSOR CSummerDlg::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

void CSummerDlg::OnClickRich(NMHDR* pNMHDR, LRESULT* pResult) 
{
   // TODO: Add your control notification handler code here
   
   *pResult = 0;
}

void CSummerDlg::OnDestroy() 
{
   CDialog::OnDestroy();
   
   // TODO: Add your message handler code here
   
}

void CSummerDlg::OnBtnEqu() 
{
   const char*    pszDelimiters = " \t\v\r\n";

   UpdateData(TRUE);

   if (_sRich.IsEmpty())
   {
      // Nothing to do !
      return;
   }

   _sRich.Replace(',','.');   // Float point 

   DWORD    dwSize = _sRich.GetLength();

   char*    pBuf = new char[dwSize + 1];

   memset(pBuf,0,dwSize + 1);

   strncpy(pBuf,(LPCTSTR)_sRich,dwSize);
   pBuf[dwSize] = 0;    // Ensure ASCIIZ

   double   fSum = 0.0;

   char*    pszLine = strtok(pBuf,pszDelimiters);

   while (pszLine && *pszLine)
   {
      double   fLine = atof(pszLine);

      fSum += fLine;
      
      pszLine = strtok(NULL,pszDelimiters);
   }      

   delete[] pBuf;
   pBuf = NULL;

   _sSum.Format("%.2f",fSum);

   UpdateData(FALSE);
}

void CSummerDlg::OnBtnClear() 
{
   _sRich = _T("");
   _sSum  = _T("");

   UpdateData(FALSE);
}

void CSummerDlg::OnCancel() 
{
   // TODO: Add extra cleanup here
   CDialog::OnCancel();
}

BOOL CSummerDlg::PreTranslateMessage(MSG* pMsg) 
{
   if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
   {  
      // Prevent <ESC> exit !
      return TRUE;
   }
   
   return CDialog::PreTranslateMessage(pMsg);
}

void CSummerDlg::OnBtnSave() 
{
   UpdateData(TRUE);

   char     pszNewFile[MAX_PATH + 1];

   memset(pszNewFile,0,sizeof(pszNewFile));

   DWORD    dwFlags = OFN_EXPLORER | OFN_CREATEPROMPT | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_OVERWRITEPROMPT;
      
   char     pszFilter[] = "*.txt\0*.txt\0*.*\0*.*\0\0";

   char     pszDrive[_MAX_DRIVE];
   char     pszDir  [_MAX_DIR];
   char     pszFName[_MAX_FNAME];
   char     pszExt  [_MAX_EXT];

   CWaitCursor    Waiter;

/*
   if (!_sCipher.IsEmpty())
   {
      _splitpath((LPCTSTR)_sCipher,pszDrive,pszDir,pszFName,pszExt);
   }
*/

   CString     sReport = _T("");

   OPENFILENAME         OFN;

   memset(&OFN,0,sizeof(OPENFILENAME));

   OFN.lStructSize     = sizeof(OPENFILENAME); 
   OFN.hwndOwner       = GetSafeHwnd();
   OFN.lpstrFilter     = pszFilter; 
   OFN.nFilterIndex    = 1;
   OFN.lpstrInitialDir = pszDir;
   OFN.lpstrFile       = pszNewFile;
   OFN.nMaxFile        = MAX_PATH;
   OFN.lpstrFileTitle  = NULL;
   OFN.nMaxFileTitle   = MAX_PATH;
   OFN.Flags           = dwFlags;

   if (GetSaveFileName(&OFN) == TRUE)
   {
      sReport = pszNewFile; 

      FILE*    pReport = fopen((LPCTSTR)sReport,"wt");

      if (!pReport)
      {
         // Error !
         ASSERT(0);
         return;
      }
      
      fprintf(pReport,"%s",(LPCTSTR)_sRich);

      fclose(pReport);
      pReport = NULL;
   }
}

void CSummerDlg::OnBtnLoad() 
{
   DWORD    dwFlags =   OFN_ENABLESIZING     |
                        OFN_FILEMUSTEXIST    |
                        OFN_PATHMUSTEXIST;
                              
   char     pszFilter[MAX_PATH] = "TXT  (*.txt)|*.txt|"
                                  "ALL  (*.*)|*.*||";

   CFileDialog    FileSrc(TRUE,NULL,NULL,dwFlags,pszFilter);

   CWaitCursor    Waiter;

   if (FileSrc.DoModal() == IDOK)
   {  
      CString    sReport = FileSrc.GetPathName();

      MMF      _MF;

      bool     bOpen = _MF.OpenReadOnly((LPCTSTR)sReport) == TRUE;

      if (!bOpen)
      {
         // Error !
         ASSERT(0);

         CString     sMessage = _T("");

         sMessage.Format("Can't Open file [%s] for Read.",(LPCTSTR)sReport);

         MessageBox(sMessage,"Error",MB_OK | MB_ICONEXCLAMATION);
         return;
      }

      _sRich = _MF.Buffer();

      _MF.Close();
   }

   UpdateData(FALSE);
}
