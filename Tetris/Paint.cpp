#include "pch.h"
#include "Paint.h"

INT CPaint::m_nScore = 0 ; 
INT CPaint::m_nId = 0 ;

const int BLOCK_INTERVAL = 30 ;

CPaint::CPaint(HWND hWnd)
{
    m_bAutoRelease = true ;
    m_hDC = GetDC(hWnd) ;
}

CPaint::CPaint(HWND hWnd, HDC hDC)
{
    m_bAutoRelease = false ;
    m_hDC = hDC ;
    m_hWnd = hWnd ;
}

CPaint::~CPaint() 
{
    if(m_bAutoRelease)
    {
        ReleaseDC(m_hWnd, m_hDC) ;
    }
}

void CPaint::PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB, INT nArrSize) 
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bruBlack { Gdiplus::Color { (BYTE)nR, (BYTE)nG, (BYTE)nB } } ; 
    for(INT nIndex = 0 ; nIndex < nArrSize ; nIndex++)
    {
        if(!spPosArr[nIndex].IsEmpty())
        {
            grap.FillRectangle(&bruBlack, INTERVAL * (spPosArr[nIndex].m_nX - 1) + INTERVAL + 2, INTERVAL * spPosArr[nIndex].m_nY + INTERVAL + 2, INTERVAL - 3, INTERVAL - 3) ; 
        }
    }
}

void CPaint::EraseBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nArrSize)
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bruWhite { Gdiplus::Color { 0, 0, 0 } } ; 
    for(INT nIndex = 0 ; nIndex < nArrSize ; nIndex++)
    {
        if(!spPosArr[nIndex].IsEmpty())
        {
            grap.FillRectangle(&bruWhite, INTERVAL * (spPosArr[nIndex].m_nX - 1) + INTERVAL + 2, INTERVAL * spPosArr[nIndex].m_nY + INTERVAL + 2, INTERVAL - 3, INTERVAL - 3) ; 
        }
    }
}

void CPaint::PaintBoard(INT arrTotalBoard[][21]) 
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bru { Gdiplus::Color { 0, 0, 0} } ;

    for(INT nX = 1 ; nX <= WIDTH ; nX++)
    {
        for(INT nY = 0 ; nY < HEIGHT ; nY++)
        {
            INT nId = arrTotalBoard[nX][nY] ; 
            switch (nId)
            {
                case LICKY :
                {
                    bru.SetColor(Gdiplus::Color { 0, 64, 255 }) ; 
                    break ;
                }
                case RICKY :
                {
                    bru.SetColor(Gdiplus::Color { 255, 127, 0 }) ; 
                    break ;
                }
                case CLEVELAND :
                {
                    bru.SetColor(Gdiplus::Color { 255, 0, 0 }) ; 
                    break ;
                }
                case PHODEISLAND :
                {
                    bru.SetColor(Gdiplus::Color { 0, 128, 0 }) ; 
                    break ;
                }
                case TEEWEE :
                {
                    bru.SetColor(Gdiplus::Color { 102, 0, 153 }) ; 
                    break ;
                }
                case SMASHBOY :
                {
                    bru.SetColor(Gdiplus::Color { 255, 212, 0 }) ; 
                    break ;
                }
                case HERO :
                {
                    bru.SetColor(Gdiplus::Color { 0, 163, 210 }) ; 
                    break ;
                }
                default :
                {
                    continue ; 
                }
            }
            grap.FillRectangle(&bru, INTERVAL * (nX - 1) + INTERVAL + 2, INTERVAL * nY + INTERVAL + 2, INTERVAL - 3, INTERVAL - 3) ; 
        }
    }
}

void CPaint::DrawBoard() 
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::Pen pen { Gdiplus::Color { 255, 255, 255, 255 }, 3.5 } ; 

    grap.DrawRectangle(&pen, INTERVAL, INTERVAL, INTERVAL * 10, INTERVAL * 20) ; 
    pen.SetColor( Gdiplus::Color { 50, 255, 255, 255 } ) ;  
    pen.SetWidth(1) ; 
    
    for(INT i = 0 ; i < WIDTH ; i++)
    {
        grap.DrawLine(&pen, INTERVAL + INTERVAL * i, INTERVAL, INTERVAL + INTERVAL * i, INTERVAL * 21) ; 
    }
    for(INT i = 0 ; i < HEIGHT ; i++)
    {
        grap.DrawLine(&pen, INTERVAL, INTERVAL + INTERVAL * i, INTERVAL * 11, INTERVAL + INTERVAL * i) ; 
    }
}

void CPaint::EraseBoard()
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bruWhite { Gdiplus::Color { 0, 0, 0 } } ; 
    for(INT nX = 1 ; nX <= WIDTH ; nX++)
    {
        for(INT nY = 0 ; nY < HEIGHT ; nY++)
        {
            grap.FillRectangle(&bruWhite, INTERVAL * (nX - 1) + INTERVAL + 2, INTERVAL * nY + INTERVAL + 2, INTERVAL - 3, INTERVAL -3) ; 
        }
    }
}

void CPaint::PrintCastle()
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::Image img { L"Castle.png" } ;
    grap.DrawImage(&img, 373, 180, 160 ,210) ; 
}

void CPaint::PrintNextBlock(INT nId) 
{
    if(nId != 0)
    {
        m_nId = nId ; 
    }
    const INT nX = 357 ;
    const INT nY = 431 ;
    Gdiplus::Graphics grap { m_hDC } ;
    CString str ; 
    switch (m_nId)
    {
        case LICKY :
        {
            str = "LICKY.png" ;  
            break ;
        }
        case RICKY :
        {
            str = "RICKY.png" ;  
            break ;
        }
        case CLEVELAND :
        {
            str = "CLEVELAND.png" ;  
            break ;
        }
        case PHODEISLAND :
        {
            str = "PHODEISLAND.png" ;  
            break ;
        }
        case TEEWEE :
        {
            str = "TEEWEE.png" ;  
            break ;
        }
        case SMASHBOY :
        {
            str = "SMASHBOY.png" ;  
            break ;
        }
        case HERO :
        {
            str = "HERO.png" ;  
            break ;
        }
    }
    Gdiplus::Image Img { str } ; 
    grap.DrawImage(&Img, nX, nY, 200, 200) ; 
}

void CPaint::DrawScores(INT nScore) 
{
    /*
    m_nScore += nScore ; 
    HDC hDC = GetDC(m_hWnd) ; 
    CString str ; 
    str.Format(_T("SCORE : %d   "), m_nScore) ;
	TextOut(hDC, 400, 50, str, str.GetLength()) ;
    ReleaseDC(m_hWnd, hDC) ; 
    */
}
