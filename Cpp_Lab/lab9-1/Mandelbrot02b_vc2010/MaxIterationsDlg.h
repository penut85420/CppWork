#if !defined(AFX_MAXITERATIONSDLG_H__2DA5E7CA_FFF4_4D9E_8CAB_22FD9C51CEE6__INCLUDED_)
#define AFX_MAXITERATIONSDLG_H__2DA5E7CA_FFF4_4D9E_8CAB_22FD9C51CEE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MaxIterationsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMaxIterationsDlg dialog

class CMaxIterationsDlg : public CDialog
{
// Construction
public:
	CMaxIterationsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMaxIterationsDlg)
	enum { IDD = IDD_DLG_MAXITERATIONS };
	int		m_maxIterations;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaxIterationsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMaxIterationsDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAXITERATIONSDLG_H__2DA5E7CA_FFF4_4D9E_8CAB_22FD9C51CEE6__INCLUDED_)
