// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Mandelbrot02.h"
#include "ChildView.h"
#include "MaxIterationsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
    : m_data(0),
      m_windowDimension(500),
      m_maxIterations(25),
      m_mandelbrot(-0.5, 0.0, 2.3),
      m_pBmpMandel(0)
{
}

CChildView::~CChildView()
{
    m_mandelbrot.deleteData(m_data, m_windowDimension);
    delete m_pBmpMandel;
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_MAXITERATIONS, OnMaxIterations)
    ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipNotify) // Unicode
    ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipNotify) // ASCII
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

#pragma pack(push)
#pragma pack(1)
typedef struct ssBGR {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char pad;
} sBGR;

typedef sBGR *pBGR;
#pragma pack(pop)

void CChildView::newBitmap()
{
    if (m_data==0) return;

    int width=m_windowDimension;
    int height=m_windowDimension;

    pBGR mandel = (pBGR) malloc(width*height*4);
    memset(mandel, 0, width*height*4);

	pBGR mandelLine = mandel;
	int stepX, stepY;
	for (stepY=0; stepY<height; stepY++) 
    {
		for (stepX=0; stepX<width; stepX++) 
        {
            ASSERT((m_data[stepX][stepY] <= 255) &&
                   (m_data[stepX][stepY] >= 0)); 
//            TRACE("stepX=%d stepY=%d m_data[stepX][stepY]=%d\n",
//                stepX, stepY, m_data[stepX][stepY]);
            mandelLine[stepX].r = GetRValue(m_colors[m_data[stepX][stepY]]);
            mandelLine[stepX].g = GetGValue(m_colors[m_data[stepX][stepY]]);
            mandelLine[stepX].b = GetBValue(m_colors[m_data[stepX][stepY]]);
		}
		mandelLine += width;
	}

	BITMAPINFO bi;
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biWidth = width;
	bi.bmiHeader.biHeight = height;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 4 * width * height;
	bi.bmiHeader.biClrUsed = 0;
	bi.bmiHeader.biClrImportant = 0;

    CClientDC dc(this);

    HBITMAP hBmpMandel = CreateCompatibleBitmap(dc.GetSafeHdc(), width, height);
    SetDIBits(dc.GetSafeHdc(), hBmpMandel, 0, height, mandel, &bi, DIB_RGB_COLORS);

    // Free the color arrays
	free(mandel);

    delete m_pBmpMandel;
    m_pBmpMandel = new CBitmap;
    m_pBmpMandel->Attach(hBmpMandel);
}


void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// Method 1:
    /*
	int i, j;
    for (i=0; i<m_windowDimension; i++)
        for (j=0; j<m_windowDimension; j++)
            dc.SetPixel(i, j, m_colors[m_data[i][j]]);
    */

    // Method 2:
    if (m_pBmpMandel)
    {
        CDC dcMem;
        dcMem.CreateCompatibleDC(&dc);
        CBitmap *pOldBmp = (CBitmap *)dcMem.SelectObject(m_pBmpMandel);
        dc.BitBlt(0, 0, m_windowDimension, m_windowDimension,
                  &dcMem, 0, 0, SRCCOPY);
        dcMem.SelectObject(pOldBmp);
    }

	// Do not call CWnd::OnPaint() for painting messages
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    CWaitCursor wait;
    m_mandelbrot.generateData(m_data, m_windowDimension, m_maxIterations);

    generateRandomColors();
    newBitmap();

    EnableToolTips(TRUE);

    return 0;
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    generateRandomColors();
    newBitmap();
    Invalidate();
	CWnd ::OnLButtonDown(nFlags, point);
}

void CChildView::generateRandomColors()
{
    int color1, color2, color3, i, mag[255], min;
    COLORREF colors[255];
    m_colors[255] = RGB(255,255,255);
	for (i=0; i<255; i++)
    {
        color1=rand()%210;
        color1 -= color1 %10;
        color2=rand()%210;
        color2 -= color2 %10;
        color3=rand()%210;
        color3 -= color3 %10;
        colors[i] = RGB(color1+55, 
                        color2+55, 
                        color3+55);
        mag[i] = (color1+55)*(color1+55)+
                 (color2+55)*(color2+55)+
                 (color3+55)*(color3+55);
    }
    for (i=0; i<255; i++)
    {
        min = selection(&mag[i], 255-i);
        swap(i, min+i, mag, colors);
    }

    for (i=0; i<255; i++)
    {
        m_colors[i] = colors[i];
    }
}

int CChildView::selection(int mag[], int nMag)
{
    int i, min=0;
    for (i=1; i<nMag; i++)
        if (mag[i]<mag[min]) min = i;
    return min;
}

void CChildView::swap(int i, int j, int mag[], COLORREF colors[])
{
    COLORREF tmpC;
    int tmpM;
    tmpC = colors[i];
    tmpM = mag[i];
    colors[i] = colors[j];
    mag[i] = mag[j];
    colors[j] = tmpC;
    mag[j] = tmpM;
}

void CChildView::OnMaxIterations() 
{
    CMaxIterationsDlg dlg;
    dlg.m_maxIterations = m_maxIterations;
    if (dlg.DoModal()==IDOK)
    {
        m_maxIterations = dlg.m_maxIterations;
        CWaitCursor wait;
        m_mandelbrot.generateData(m_data, m_windowDimension, m_maxIterations);
        newBitmap();
        Invalidate();
    }   
}



INT_PTR CChildView::OnToolHitTest(CPoint point, TOOLINFO* pTI) const
{
    // TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
    pTI->hwnd = this->m_hWnd;
//    TRACE("hwnd=%p uID=%x cbSize=%d\n", pTI->hwnd, pTI->uId, pTI->cbSize);
    pTI->lpszText = LPSTR_TEXTCALLBACK;
    pTI->rect.left = point.x-20;
    pTI->rect.right = point.x+20;
    pTI->rect.top = point.y-20;
    pTI->rect.bottom = point.y+20;
    pTI->uId = 2;
    return pTI->uId+rand()%2;
//    return CWnd::OnToolHitTest(point, pTI);
}

BOOL CChildView::OnToolTipNotify(UINT id, NMHDR *pNMHDR, LRESULT *pResult)
{
   // need to handle both ANSI and UNICODE versions of the message
   TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
   TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
   CString strTipText;
   UINT nID = (UINT) pNMHDR->idFrom;
   strTipText.Format("滑鼠左鍵可更換顯示顏色!");
//   ((CMainFrame *)AfxGetMainWnd())->SetMessageText(strTipText);

   if (pNMHDR->code == TTN_NEEDTEXTA)
      lstrcpyn(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
   else
      ::MultiByteToWideChar( CP_ACP , 0, strTipText, -1, pTTTW->szText, sizeof(pTTTW->szText)/(sizeof pTTTW->szText[0]) );
   *pResult = 0;

   return TRUE;    // message was handled
}
