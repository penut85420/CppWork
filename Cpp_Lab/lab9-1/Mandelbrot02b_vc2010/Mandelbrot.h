// Mandelbrot.h: interface for the Mandelbrot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_)
#define AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Mandelbrot  
{
public:
	void generateData(int ** &data, int windowSize, int maxIterations);
	void deleteData(int ** &data, int windowSize);
	Mandelbrot(double centerX, double centerY, double range);

private:
};

#endif // !defined(AFX_MANDELBROT_H__B5AEAA3B_9D8D_484D_AB31_932C210B233F__INCLUDED_)
