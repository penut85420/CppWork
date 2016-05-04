// MaxIterationsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mandelbrot02.h"
#include "MaxIterationsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMaxIterationsDlg dialog


CMaxIterationsDlg::CMaxIterationsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMaxIterationsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMaxIterationsDlg)
	m_maxIterations = 0;
	//}}AFX_DATA_INIT
}


void CMaxIterationsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMaxIterationsDlg)
	DDX_Text(pDX, IDC_MAXITERATIONS, m_maxIterations);
	DDV_MinMaxInt(pDX, m_maxIterations, 10, 120);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMaxIterationsDlg, CDialog)
	//{{AFX_MSG_MAP(CMaxIterationsDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMaxIterationsDlg message handlers
