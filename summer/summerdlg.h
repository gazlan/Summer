#if !defined(AFX_SUMMERDLG_H__9953386A_5ED4_4F31_9631_DB20E375EB27__INCLUDED_)
#define AFX_SUMMERDLG_H__9953386A_5ED4_4F31_9631_DB20E375EB27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSummerDlg : public CDialog
{
// Construction
public:
   CSummerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
   //{{AFX_DATA(CSummerDlg)
	enum { IDD = IDD_SUMMER };
   CString  _sRich;
	CString	_sSum;
	//}}AFX_DATA

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CSummerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
   virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   HICON m_hIcon;

   // Generated message map functions
   //{{AFX_MSG(CSummerDlg)
   virtual BOOL OnInitDialog();
   afx_msg void OnPaint();
   afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnClickRich(NMHDR* pNMHDR, LRESULT* pResult);
   afx_msg void OnDestroy();
	afx_msg void OnBtnEqu();
	afx_msg void OnBtnClear();
	virtual void OnCancel();
	afx_msg void OnBtnSave();
	afx_msg void OnBtnLoad();
	//}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUMMERDLG_H__9953386A_5ED4_4F31_9631_DB20E375EB27__INCLUDED_)
