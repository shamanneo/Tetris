#include "pch.h"
#include "Paint.h"

const int BLOCK_INTERVAL = 30 ;

CPaint::CPaint(HWND hWnd)
{
    m_hWnd = hWnd ; 
    m_hDC = GetDC(m_hWnd) ;
    m_bAutoRelease = true ;
}

CPaint::CPaint(HWND hWnd, HDC hDC)
{
    m_hWnd = hWnd ;
    m_hDC = hDC ;
    m_bAutoRelease = false ;
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
            grap.FillRectangle(&bruBlack, BLOCK_INTERVAL * (spPosArr[nIndex].m_nX - 1) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL * spPosArr[nIndex].m_nY + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
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
            grap.FillRectangle(&bruWhite, BLOCK_INTERVAL * (spPosArr[nIndex].m_nX - 1) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL * spPosArr[nIndex].m_nY + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
        }
    }
}

void CPaint::PaintBoard(INT arrTotalBoard[][21]) 
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bru { Gdiplus::Color { 0, 0, 0} } ;

    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        for(INT nY = 0 ; nY < BLOCK_HEIGHT_COUNT ; nY++)
        {
            BlockId eId = (BlockId)arrTotalBoard[nX][nY] ; 
            switch (eId)
            {
                case ID_LICKY :
                {
                    bru.SetColor(Gdiplus::Color { 0, 64, 255 }) ; 
                    break ;
                }
                case ID_RICKY :
                {
                    bru.SetColor(Gdiplus::Color { 255, 127, 0 }) ; 
                    break ;
                }
                case ID_CLEVELAND :
                {
                    bru.SetColor(Gdiplus::Color { 255, 0, 0 }) ; 
                    break ;
                }
                case ID_PHODEISLAND :
                {
                    bru.SetColor(Gdiplus::Color { 0, 128, 0 }) ; 
                    break ;
                }
                case ID_TEEWEE :
                {
                    bru.SetColor(Gdiplus::Color { 102, 0, 153 }) ; 
                    break ;
                }
                case ID_SMASHBOY :
                {
                    bru.SetColor(Gdiplus::Color { 255, 212, 0 }) ; 
                    break ;
                }
                case ID_HERO :
                {
                    bru.SetColor(Gdiplus::Color { 0, 163, 210 }) ; 
                    break ;
                }
                default :
                {
                    continue ; 
                }
            }
            grap.FillRectangle(&bru, BLOCK_INTERVAL * (nX - 1) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL * nY + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
        }
    }
}

void CPaint::DrawBoard() 
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::Pen pen { Gdiplus::Color { 255, 255, 255, 255 }, 3.5 } ; 

    grap.DrawRectangle(&pen, BLOCK_INTERVAL, BLOCK_INTERVAL, BLOCK_INTERVAL * 10, BLOCK_INTERVAL * 20) ; 
    pen.SetColor( Gdiplus::Color { 50, 255, 255, 255 } ) ;  
    pen.SetWidth(1) ; 
    
    for(INT i = 0 ; i < BLOCK_WIDTH_COUNT ; i++)
    {
        grap.DrawLine(&pen, BLOCK_INTERVAL + BLOCK_INTERVAL * i, BLOCK_INTERVAL, BLOCK_INTERVAL + BLOCK_INTERVAL * i, BLOCK_INTERVAL * 21) ; 
    }
    for(INT i = 0 ; i < BLOCK_HEIGHT_COUNT ; i++)
    {
        grap.DrawLine(&pen, BLOCK_INTERVAL, BLOCK_INTERVAL + BLOCK_INTERVAL * i, BLOCK_INTERVAL * 11, BLOCK_INTERVAL + BLOCK_INTERVAL * i) ; 
    }
}

void CPaint::EraseBoard()
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::SolidBrush bruWhite { Gdiplus::Color { 0, 0, 0 } } ; 
    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        for(INT nY = 0 ; nY < BLOCK_HEIGHT_COUNT ; nY++)
        {
            grap.FillRectangle(&bruWhite, BLOCK_INTERVAL * (nX - 1) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL * nY + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL -3) ; 
        }
    }
}

void CPaint::PrintCastle()
{
    Gdiplus::Graphics grap { m_hDC } ; 
    Gdiplus::Image img { L"Castle.png" } ;
    grap.DrawImage(&img, 373, 180, 160 ,210) ; 
}

void CPaint::PrintNextBlock() 
{
    BlockId eId = CMainApp::GetInstance().GetBlockId() ; 
    const INT nX = 357 ;
    const INT nY = 431 ;
    Gdiplus::Graphics grap { m_hDC } ;
    CString str ; 
    switch (eId)
    {
        case ID_LICKY :
        {
            str = "LICKY.png" ;  
            break ;
        }
        case ID_RICKY :
        {
            str = "RICKY.png" ;  
            break ;
        }
        case ID_CLEVELAND :
        {
            str = "CLEVELAND.png" ;  
            break ;
        }
        case ID_PHODEISLAND :
        {
            str = "PHODEISLAND.png" ;  
            break ;
        }
        case ID_TEEWEE :
        {
            str = "TEEWEE.png" ;  
            break ;
        }
        case ID_SMASHBOY :
        {
            str = "SMASHBOY.png" ;  
            break ;
        }
        case ID_HERO :
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
