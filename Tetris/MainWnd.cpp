#include "pch.h"
#include "MainWnd.h"
#include "BlockT.h" 
#include "resource.h" 

int nKey ;
CBlockT *bp = nullptr ; 

void f(HDC hDC)
{
    switch(nKey)
    {
        case 1 : // left
        {
            bp->Erase(hDC) ; 
            bp->Left() ; 
            break ; 
        }
        case 2 : // right
        {
            bp->Erase(hDC) ; 
            bp->Right() ; 
            break ; 
        }
        case 3 :
        {
            //bp->Erase(hDC) ; 
            //bp->RightRotate() ; 
            break ; 
        }
        case 4 :
        {
            break ; 
        }
        default :
        {
            
        }
    }
    nKey = 0 ; 
}

CMainWnd::CMainWnd()
{
    CBlockT *block = new CBlockT ; 
    bp = block ; 
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PAINTSTRUCT ps ; 
    BeginPaint(&ps) ; 

    EndPaint(&ps) ; 
    return 0 ;
}

LRESULT CMainWnd::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    switch(wParam)
    {
        case VK_LEFT : // Move left.
        {
            nKey = 1 ; 
            break ;
        }
        case VK_RIGHT : // Move right.
        {
            nKey = 2 ; 
            break ;
        }
        case VK_UP : // Rotate clock-wise.
        {
            nKey = 3 ; 
            break ;
        }
        case VK_DOWN : // Fast Down.
        {
            nKey = 4 ; 
            break ;
        }
        default :
        {
            break ;
        }
    }
    return 0 ; 
}

LRESULT CMainWnd::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    HDC hDC = GetDC() ;
    switch(wParam)
    {
        case IDT_DRAW_TIMER :
        {
            f(hDC) ; 
            bp->Draw(hDC) ; 
            break ; 
        }
        case IDT_DOWN_TIMER :
        {
            bp->Erase(hDC) ; 
            bp->Down() ; 
            break ; 
        }
    }
    ReleaseDC(hDC) ;
    return 0 ; 
}

LRESULT CMainWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PostQuitMessage(0) ;
    return 0 ; 
}