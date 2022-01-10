#include "pch.h"
#include "resource.h"
#include "Paint.h"

const int BLOCK_INTERVAL = 30 ;
using namespace Gdiplus ; 

CPaint::CPaint(HWND hWnd)
    : m_bAutoRelease(true) 
{
    m_hWnd = hWnd ; 
    m_hDC = GetDC(m_hWnd) ;
    GetClientRect(m_hWnd, &m_rcClient) ; 
}

CPaint::CPaint(HWND hWnd, HDC hDC)
    : m_bAutoRelease(true)
{
    m_hWnd = hWnd ;
    m_hDC = hDC ;
    GetClientRect(m_hWnd, &m_rcClient) ; 
}

CPaint::~CPaint() 
{
    if(m_bAutoRelease)
    {
        ReleaseDC(m_hWnd, m_hDC) ;
    }
}

Gdiplus::Image *CPaint::LoadPNG(HMODULE hModule, LPCWSTR lp)
{
    Image *pImg = nullptr ; 
    IStream *pStream = nullptr ; 

    HRSRC hResource = ::FindResource(hModule, lp, L"PNG") ; 
    if(::CreateStreamOnHGlobal(NULL, NULL, &pStream) == S_OK)
    {
        PVOID pResource = ::LockResource(LoadResource(hModule, hResource)) ; 
        DWORD dwImageSize = ::SizeofResource(hModule, hResource) ; 
        DWORD dwReadWrite = 0 ; 
        pStream->Write(pResource, dwImageSize, &dwReadWrite) ; 
        pImg = pImg->FromStream(pStream) ; 
        pStream->Release() ; 
    }
    return pImg ; 
}

void CPaint::PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nA, INT nR, INT nG, INT nB, INT nArrSize) 
{
    INT nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ; 
    Graphics grfx { m_hDC } ; 
    SolidBrush brush { Gdiplus::Color { (BYTE)nA, (BYTE)nR, (BYTE)nG, (BYTE)nB } } ; 
    for(INT nIndex = 0 ; nIndex < nArrSize ; nIndex++)
    {
        if(!spPosArr[nIndex].IsEmpty())
        {
            grfx.FillRectangle(&brush, (BLOCK_INTERVAL * (spPosArr[nIndex].m_nX - 2) + nInitX + 2), (BLOCK_INTERVAL * (spPosArr[nIndex].m_nY - 2) + BLOCK_INTERVAL + 2), BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
        }
    }
}

void CPaint::PaintBoard(INT arrTotalBoard[][BLOCK_HEIGHT_COUNT]) 
{
    INT nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ; 
    Graphics grfx { m_hDC } ; 
    SolidBrush brush { Gdiplus::Color { 0, 0, 0 } } ;
    bool IsGameOver = CMainApp::GetInstance().GetIsGameOver() ; 
    BlockId eId = BlockId::ID_VOID ; 
    for(INT nX = 1 ; nX <= 11 ; nX++)
    {
        for(INT nY = 1 ; nY <= 21 ; nY++)
        {
            if(!IsGameOver)
            {
                eId = (BlockId)arrTotalBoard[nX][nY] ; 
                switch (eId)
                {
                    case BlockId::ID_LICKY :
                    {
                        brush.SetColor(Gdiplus::Color { 0, 64, 255 }) ; 
                        break ;
                    }
                    case BlockId::ID_RICKY :
                    {
                        brush.SetColor(Gdiplus::Color { 255, 127, 0 }) ; 
                        break ;
                    }
                    case BlockId::ID_CLEVELAND :
                    {
                        brush.SetColor(Gdiplus::Color { 255, 0, 0 }) ; 
                        break ;
                    }
                    case BlockId::ID_PHODEISLAND :
                    {
                        brush.SetColor(Gdiplus::Color { 0, 128, 0 }) ; 
                        break ;
                    }
                    case BlockId::ID_TEEWEE :
                    {
                        brush.SetColor(Gdiplus::Color { 102, 0, 153 }) ; 
                        break ;
                    }
                    case BlockId::ID_SMASHBOY :
                    {
                        brush.SetColor(Gdiplus::Color { 255, 212, 0 }) ; 
                        break ;
                    }
                    case BlockId::ID_HERO :
                    {
                        brush.SetColor(Gdiplus::Color { 0, 163, 210 }) ; 
                        break ;
                    }
                    default :
                    {
                        continue ; 
                    }
                }
                grfx.FillRectangle(&brush, BLOCK_INTERVAL * (nX - 2) + nInitX + 2, BLOCK_INTERVAL * (nY - 2) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
            }
            else // When game over
            {
                eId = (BlockId)arrTotalBoard[nX][nY] ; 
                if(((INT)eId != 0) && ((INT)eId != BOARD_BOUND)) 
                {
                    brush.SetColor(Color { 255, 255, 255 } ) ;
                    grfx.FillRectangle(&brush, BLOCK_INTERVAL * (nX - 2) + nInitX + 2, BLOCK_INTERVAL * (nY - 2) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
                }
            }
        }
    }
}

void CPaint::DrawBoard() 
{
    INT nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ; 
    Graphics grfx { m_hDC } ; 
    Pen pen { Gdiplus::Color { 255, 255, 255 }, 3.5 } ; 

    grfx.DrawRectangle(&pen, nInitX, 0, BLOCK_INTERVAL * 10, BLOCK_INTERVAL * 21) ; 
    pen.SetColor( Gdiplus::Color { 50, 255, 255, 255 } ) ;  
    pen.SetWidth(1) ; 
    
    for(INT i = 0 ; i < 10 ; i++)
    {
        grfx.DrawLine(&pen, nInitX + BLOCK_INTERVAL * i, BLOCK_INTERVAL, nInitX + BLOCK_INTERVAL * i, BLOCK_INTERVAL * 21) ; 
    }
    for(INT i = 0 ; i < 20 ; i++)
    {
        grfx.DrawLine(&pen, nInitX, BLOCK_INTERVAL + BLOCK_INTERVAL * i, nInitX + BLOCK_INTERVAL * 10, BLOCK_INTERVAL + BLOCK_INTERVAL * i) ; 
    }
}

void CPaint::EraseBoard()
{
    INT nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ; 
    Graphics grfx { m_hDC } ; 
    SolidBrush bruWhite { Gdiplus::Color { 0, 0, 0 } } ; 
    for(INT nX = 2 ; nX < 12 ; nX++)
    {
        for(INT nY = 0 ; nY < 20 ; nY++) // -2 : 가상의 공간까지 지워져야함
        {
            grfx.FillRectangle(&bruWhite, BLOCK_INTERVAL * (nX - 2) + nInitX + 2, BLOCK_INTERVAL * nY + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
        }
    } 
}

void CPaint::PrintMain()
{
    static INT nCount = 1 ;
    Graphics grfx { m_hDC } ; 
    Image *pImg = nullptr ; 
    if(nCount++ % 2 == 1)
    {
        pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_MAIN)) ; 
    }
    else
    { 
        pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_MAIN_PRESS)) ; 
    }
    grfx.DrawImage(pImg, -1, 0, pImg->GetWidth(), pImg->GetHeight()) ;    
}

void CPaint::PrintNextBlock() 
{
    BlockId eId = CMainApp::GetInstance().GetBlockId() ; 
    const INT nX = (m_rcClient.right / 2) + BLOCK_INTERVAL * 6 ; 
    const INT nY = 431 ; 
    Graphics grfx { m_hDC } ;
    Image *pImg = nullptr ; 
    switch (eId)
    {
        case BlockId::ID_LICKY :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_LICKY)) ;  
            break ;
        }
        case BlockId::ID_RICKY :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_RICKY)) ;  
            break ;
        }
        case BlockId::ID_CLEVELAND :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_CLEVELAND)) ;  
            break ;
        }
        case BlockId::ID_PHODEISLAND :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_PHODEISLAND)) ;  
            break ;
        }
        case BlockId::ID_TEEWEE :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_TEEWEE)) ;  
            break ;
        }
        case BlockId::ID_SMASHBOY :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_SMASHBOY)) ;  
            break ;
        }
        case BlockId::ID_HERO :
        {
            pImg = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_BLOCK_HERO)) ;  
            break ;
        }
    }
    grfx.DrawImage(pImg, nX, nY, 200, 200) ; 
}

void CPaint::PrintGameOver()
{
    const INT nX = (m_rcClient.right / 2) + BLOCK_INTERVAL * 6 ; 
    const INT nY = 431 ; 
    Graphics grfx { m_hDC } ;
    Image *img = LoadPNG(CMainApp::GetInstance().GetMainInStance(), MAKEINTRESOURCE(IDP_TETRIS_GAMEOVER)) ; 
    grfx.DrawImage(img, nX, nY, 200, 200) ; 
}

void CPaint::DrawInfo(INT nScore, INT nLevel, INT nLine) 
{
    const INT nY = 215 ; 
    const INT nWidth = 197 ; 
    const INT nHeight = 200 ; 
    Graphics grfx { m_hDC } ;
    SolidBrush brushBlack { Gdiplus::Color { 0, 0, 0 } } ;
    Rect rc { (m_rcClient.right / 2) + BLOCK_INTERVAL * 6, nY, nWidth, nHeight } ; 
    Pen pen { Gdiplus::Color { 255, 255, 255 }, 2.8f } ; 

    grfx.FillRectangle(&brushBlack, rc) ;

    CString strText ;
    strText.Format(_T("SCORE \n%d\nLEVEL \n%d\nLINE \n%d\n"), nScore, nLevel, nLine) ;  
   
    StringFormat stringFormat ;
    stringFormat.SetAlignment(StringAlignmentNear) ; 

    FontFamily fontFamily { L"Arial" } ; 
    Font font { &fontFamily, 22, Gdiplus::FontStyleBold } ; 
    RectF rectF { (Gdiplus::REAL)(m_rcClient.right / 2) + BLOCK_INTERVAL * 6, (REAL)nY, (REAL)nWidth, (REAL)nHeight } ; 
    SolidBrush solidBrush { Gdiplus::Color { 255, 255 ,255 } } ; 

    grfx.DrawString(strText, -1, &font, rectF, &stringFormat, &solidBrush) ; 
}
