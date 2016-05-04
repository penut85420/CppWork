// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_)
#define AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_

#include "Mandelbrot.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMaxIterations();
    afx_msg BOOL OnToolTipNotify(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void newBitmap();
	CBitmap *m_pBmpMandel;
	Mandelbrot m_mandelbrot;
	int selection(int mag[], int nMag);
	void swap(int i, int j, int mag[], COLORREF colors[]);
	int m_maxIterations;
	void generateRandomColors();
	COLORREF m_colors[256];
	int m_windowDimension;
	int ** m_data;
public:
    virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__58A748C4_986F_46C5_A166_D2E0BF3DAEE7__INCLUDED_)
