// Mandelbrot02.h : main header file for the MANDELBROT02 application
//

#if !defined(AFX_MANDELBROT02_H__BCD81713_C7E4_4191_B11D_F0FFD92DCF5B__INCLUDED_)
#define AFX_MANDELBROT02_H__BCD81713_C7E4_4191_B11D_F0FFD92DCF5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMandelbrot02App:
// See Mandelbrot02.cpp for the implementation of this class
//

class CMandelbrot02App : public CWinApp
{
public:
	CMandelbrot02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelbrot02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMandelbrot02App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELBROT02_H__BCD81713_C7E4_4191_B11D_F0FFD92DCF5B__INCLUDED_)
