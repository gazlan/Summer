// Summer.h : main header file for the SUMMER application
//

#if !defined(AFX_SUMMER_H__8ED9C476_2644_4256_AEE0_E76AF97636FA__INCLUDED_)
#define AFX_SUMMER_H__8ED9C476_2644_4256_AEE0_E76AF97636FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSummerApp:
// See Summer.cpp for the implementation of this class
//

class CSummerApp : public CWinApp
{
public:
	CSummerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSummerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSummerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUMMER_H__8ED9C476_2644_4256_AEE0_E76AF97636FA__INCLUDED_)
