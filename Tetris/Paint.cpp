#include "pch.h"
#include "Paint.h"

HWND CPaint::m_hWnd = 0 ; 

CPaint::CPaint()
{

}

CPaint::~CPaint() 
{

}

void CPaint::PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB) 
{
    HDC hDC = GetDC(m_hWnd) ; 
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush blackBru { Gdiplus::Color { (BYTE)nR, (BYTE)nG, (BYTE)nB } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * (spPosArr[i].m_nX - 1) + 32, 30 * (spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
    ReleaseDC(m_hWnd, hDC) ; 
}

void CPaint::EraseBlock(std::unique_ptr<CSpace[]> &spPosArr)
{
    HDC hDC = GetDC(m_hWnd) ; 
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush whiteBru { Gdiplus::Color { 255, 255, 255 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&whiteBru, 30 * (spPosArr[i].m_nX - 1) + 32, 30 * (spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
    ReleaseDC(m_hWnd, hDC) ; 
}

void CPaint::Assign(HWND hWnd) 
{
    m_hWnd = hWnd ; 
}