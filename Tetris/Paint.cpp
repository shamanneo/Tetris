#include "pch.h"
#include "SQLlite/sqlite3.h" 
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
    m_nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ;  
}

CPaint::CPaint(HWND hWnd, HDC hDC)
    : m_bAutoRelease(true)
{
    m_hWnd = hWnd ;
    m_hDC = hDC ;
    GetClientRect(m_hWnd, &m_rcClient) ; 
    m_nInitX = (m_rcClient.right / 2) - BLOCK_INTERVAL * 5 ;  
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

void CPaint::PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB, INT nGhost, INT nArrSize) 
{
    SolidBrush brush { Gdiplus::Color { (BYTE)nR, (BYTE)nG, (BYTE)nB } } ; 
    for(INT nIndex = 0 ; nIndex < nArrSize ; nIndex++)
    {
        if(!spPosArr[nIndex].IsEmpty())
        {
            if(nGhost == GHOST_BLOCK)
            {
                brush.SetColor(Gdiplus::Color { 255, 255 ,255 }) ; // Ghost color 
                FillRect(brush, spPosArr[nIndex].m_nX, spPosArr[nIndex].m_nY) ; 
            }
            else 
            {
                FillRect(brush, spPosArr[nIndex].m_nX, spPosArr[nIndex].m_nY) ; 
            }
        }
    }
}

void CPaint::PaintBoard(INT arrTotalBoard[][BLOCK_HEIGHT_COUNT]) 
{
    SolidBrush brush { Gdiplus::Color { 0, 0, 0 } } ;
    bool IsGameOver = CMainApp::GetInstance().GetIsGameOver() ; 
    BlockId eId = BlockId::ID_VOID ; 
    for(INT nX = 1 ; nX < 12 ; nX++)
    {
        for(INT nY = 1 ; nY < 22 ; nY++)
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
                FillRect(brush, nX, nY) ; 
            }
            else // When game over
            {
                eId = (BlockId)arrTotalBoard[nX][nY] ; 
                if(((INT)eId != 0) && ((INT)eId != BOARD_BOUND)) 
                {
                    brush.SetColor(Gdiplus::Color { 255, 255, 255 } ) ;
                    FillRect(brush, nX, nY) ; 
                }
            }
        }
    }
}

void CPaint::DrawBoard() 
{
    Graphics grfx { m_hDC } ; 
    Pen pen { Gdiplus::Color { 255, 255, 255 }, 3.5 } ; 

    grfx.DrawRectangle(&pen, m_nInitX, 0, BLOCK_INTERVAL * 10, BLOCK_INTERVAL * 21) ; 
    pen.SetColor( Gdiplus::Color { 30, 255, 255, 255 } ) ;  
    pen.SetWidth(1) ; 
    
    for(INT i = 0 ; i < 10 ; i++)
    {
        grfx.DrawLine(&pen, m_nInitX + BLOCK_INTERVAL * i, BLOCK_INTERVAL, m_nInitX + BLOCK_INTERVAL * i, BLOCK_INTERVAL * 21) ; 
    }
    for(INT i = 0 ; i < 20 ; i++)
    {
        grfx.DrawLine(&pen, m_nInitX, BLOCK_INTERVAL + BLOCK_INTERVAL * i, m_nInitX + BLOCK_INTERVAL * 10, BLOCK_INTERVAL + BLOCK_INTERVAL * i) ; 
    }
}

void CPaint::EraseBoard()
{
    Graphics grfx { m_hDC } ; 
    SolidBrush brush { Gdiplus::Color { 0, 0, 0 } } ; 
    for(INT nX = 2 ; nX < 12 ; nX++)
    {
        for(INT nY = 2 ; nY < 24 ; nY++) // -2 : 가상의 공간까지 지워져야함
        {
            FillRect(brush, nX, nY) ; 
        }
    } 
}

void CPaint::EraseAnimation(INT /*arrTotalBoard*/[][BLOCK_HEIGHT_COUNT], INT nLine) 
{
    Graphics grfx { m_hDC } ; 
    SolidBrush brush { Gdiplus::Color { 204, 255, 255 } } ; 

    for(INT nX = 2 ; nX < 12 ; nX++)
    {
        FillRect(brush, nX, nLine) ; 
    }
    Sleep(100) ; 
}

void CPaint::PrintMain()
{
    static INT nCount = 1 ;
    HINSTANCE hInstance = _AtlBaseModule.GetModuleInstance() ;
    Graphics grfx { m_hDC } ; 
    Image *pImg = nullptr ; 
    if(nCount++ % 2 == 1)
    {
        pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_MAIN)) ; 
    }
    else
    { 
        pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_MAIN_PRESS)) ; 
    }
    grfx.DrawImage(pImg, -1, 0, pImg->GetWidth(), pImg->GetHeight()) ;    
}

void CPaint::PrintNextBlock() 
{
    BlockId eId = CMainApp::GetInstance().GetBlockId() ; 
    HINSTANCE hInstance = _AtlBaseModule.GetModuleInstance() ;
    const INT nX = (m_rcClient.right / 2) + BLOCK_INTERVAL * 6 ; 
    const INT nY = 431 ; 
    Graphics grfx { m_hDC } ;
    Image *pImg = nullptr ; 
    switch (eId)
    {
        case BlockId::ID_LICKY :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_LICKY)) ;  
            break ;
        }
        case BlockId::ID_RICKY :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_RICKY)) ;  
            break ;
        }
        case BlockId::ID_CLEVELAND :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_CLEVELAND)) ;  
            break ;
        }
        case BlockId::ID_PHODEISLAND :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_PHODEISLAND)) ;  
            break ;
        }
        case BlockId::ID_TEEWEE :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_TEEWEE)) ;  
            break ;
        }
        case BlockId::ID_SMASHBOY :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_SMASHBOY)) ;  
            break ;
        }
        case BlockId::ID_HERO :
        {
            pImg = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_BLOCK_HERO)) ;  
            break ;
        }
    }
    grfx.DrawImage(pImg, nX, nY, 200, 200) ; 
}

void CPaint::FillRect(Gdiplus::Brush &brush, INT nX, INT nY)
{
    Graphics grfx { m_hDC } ; 
    grfx.FillRectangle(&brush, BLOCK_INTERVAL * (nX - 2) + m_nInitX + 2, BLOCK_INTERVAL * (nY - 2) + BLOCK_INTERVAL + 2, BLOCK_INTERVAL - 3, BLOCK_INTERVAL - 3) ; 
}

void CPaint::PrintGameOver()
{
    HINSTANCE hInstance = _AtlBaseModule.GetModuleInstance() ;
    const INT nX = (m_rcClient.right / 2) + BLOCK_INTERVAL * 6 ; 
    const INT nY = 431 ; 
    Graphics grfx { m_hDC } ;
    Image *img = LoadPNG(hInstance, MAKEINTRESOURCE(IDP_TETRIS_GAMEOVER)) ; 
    grfx.DrawImage(img, nX, nY, 200, 200) ; 
}

void CPaint::DrawInfo(INT nScore, INT nLevel, INT nLine) 
{
    const INT nY = 215 ; 
    const INT nWidth = 200 ; 
    const INT nHeight = 200 ; 
    Graphics grfx { m_hDC } ;
    
    SolidBrush brush { Gdiplus::Color { 0, 0, 0 } } ;
    Rect rc { (m_rcClient.right / 2) + BLOCK_INTERVAL * 6, nY, nWidth, nHeight } ; 
    Pen pen { Gdiplus::Color { 255, 255, 255 }, 2.8f } ; 
    grfx.FillRectangle(&brush, rc) ; // 제거 작업
    
    CString strText ;
    strText.Format(_T("SCORE \n%d\nLEVEL \n%d\nLINE \n%d\n"), nScore, nLevel, nLine) ;  
    FontFamily fontFamily { L"Arial" } ; 
    Font font { &fontFamily, 22, Gdiplus::FontStyleBold } ; 
    RectF rectF { (Gdiplus::REAL)(m_rcClient.right / 2) + BLOCK_INTERVAL * 6, (REAL)nY, (REAL)nWidth, (REAL)nHeight } ; 
    SolidBrush solidBrush { Gdiplus::Color { 255, 255 ,255 } } ; 
    grfx.DrawString(strText, -1, &font, rectF, nullptr, &solidBrush) ; 
}

void CPaint::DrawLeaderBoard() 
{
    const INT nY = 30 ; 
    const INT nWidth = 400 ; 
    const INT nHeight = 200 ; 
    
    Graphics grfx { m_hDC } ;
    SolidBrush brush { Gdiplus::Color { 0, 0, 0 } } ;
    Rect rc { (m_rcClient.right / 2) + BLOCK_INTERVAL * 6, nY, nWidth, nHeight } ; 
    Pen pen { Gdiplus::Color { 255, 255, 255 }, 2.8f } ; 
    grfx.FillRectangle(&brush, rc) ; // 제거 작업

    CString strTotal { " *LEADERBOARD*\n\n" } ; 
    CString strLabel ; 
    CString strNickName ; 
    INT nScore = 0 ; 
    INT nRc = 0 ; 
    sqlite3 *db ; 
    sqlite3_stmt *pStmt ; 
    const char *sql = nullptr ; 

    
    sqlite3_open("Tetris.db", &db) ; 
    sql = "SELECT * from TETRIS_SCORE order by Score desc" ; 
    sqlite3_prepare_v2(db, sql, -1, &pStmt, NULL) ; 
    for(INT i = 1 ; i <= 3 ; i++)
    {
        nRc = sqlite3_step(pStmt) ; 
        if(nRc == SQLITE_DONE)
        {
            for(INT j = i ; j <= 3 ; j++)
            {
                strLabel.Format(_T("%d       0\n"), j) ; 
                strTotal += strLabel ; 
            }
            break ;
        }
        else
        {
            strNickName = sqlite3_column_text(pStmt, 1) ; 
            nScore = sqlite3_column_int(pStmt, 2) ; 
            strLabel.Format(_T("%d  %s  %d          \n"), i, static_cast<LPCWSTR>(strNickName), nScore) ; 
            strTotal += strLabel ; 
        }
    }
    sqlite3_finalize(pStmt) ; 
    sqlite3_close(db) ; 

    StringFormat stringFormat ;
    stringFormat.SetAlignment(StringAlignmentNear) ; 

    FontFamily fontFamily { L"Arial" } ; 
    Font font { &fontFamily, 22, Gdiplus::FontStyleBold } ; 
    RectF rectF { (Gdiplus::REAL)(m_rcClient.right / 2) + BLOCK_INTERVAL * 6, (REAL)nY, (REAL)nWidth, (REAL)nHeight } ; 
    brush.SetColor( Gdiplus::Color { 255, 255, 255 } ) ; 
    grfx.DrawString(strTotal, -1, &font, rectF, &stringFormat, &brush) ; 
}
