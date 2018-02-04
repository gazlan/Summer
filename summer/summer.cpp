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

#ifdef NDEBUG
#pragma optimize("gsy",on)
#pragma comment(linker,"/FILEALIGN:512 /MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR /IGNORE:4078")
#endif 

/* ******************************************************************** **
** @@ internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@ external global variables
** ******************************************************************** */

extern DWORD   dwKeepError = 0;

/* ******************************************************************** **
** @@ static global variables
** ******************************************************************** */
                 
CSummerApp     theApp;

/* ******************************************************************** **
** @@ real code
** ******************************************************************** */

BEGIN_MESSAGE_MAP(CSummerApp, CWinApp)
   //{{AFX_MSG_MAP(CSummerApp)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
   //}}AFX_MSG
   ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CSummerApp::CSummerApp()
{
   // TODO: add construction code here,
   // Place all significant initialization in InitInstance
}

BOOL CSummerApp::InitInstance()
{
   AfxInitRichEdit();
   AfxEnableControlContainer();

   // Standard initialization
   // If you are not using these features and wish to reduce the size
   //  of your final executable, you should remove from the following
   //  the specific initialization routines you do not need.

   #ifdef _AFXDLL
   Enable3dControls();        // Call this when using MFC in a shared DLL
   #else
   Enable3dControlsStatic();  // Call this when linking to MFC statically
   #endif

   CSummerDlg dlg;
   
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
