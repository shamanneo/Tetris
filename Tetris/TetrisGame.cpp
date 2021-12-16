#include "pch.h"
#include "TetrisGame.h"
#include "Teewee.h" 
#include "SmashBoy.h" 
#include <time.h>

CTetrisGame::CTetrisGame()
{
    for(INT nY = 0 ; nY <= 20 ; nY++)
    {
        m_arrBoard[0][nY] = BOUND ; 
        m_arrBoard[11][nY] = BOUND ; 
        if(nY < 12)
        {
            m_arrBoard[nY][20] = BOUND ; 
        }
    }
    Create() ; 
}

CTetrisGame::~CTetrisGame()
{

}

void CTetrisGame::Create()
{
    //srand(unsigned int(NULL)) ; 
    int nName = TEEWEE + (rand() % 2) ; 
    switch(nName)
    {
        case LICKY :
        {
            // create LICKY.
            break ;
        }
        case RICKY :
        {
            // create RICKY.
            break ;
        }
        case CLEVELAND :
        {
            // create CLEVELAND.
            break ;
        }
        case PHODEISLAND :
        {
            // create PHODEISLAND.
            break ;
        }
        case HERO :
        {
            // create HERO.
            break ;
        }
        case TEEWEE :
        {
            m_spCurBk = std::make_unique<CTeewee>() ; 
            break ;
        }
        case SMASHBOY :
        {
            m_spCurBk = std::make_unique<CSmashBoy>() ; 
            break ;
        }
    }
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    { 
        if(m_spCurBk->GetPos(nIndex, nX, nY)) 
        {
            m_arrBoard[nX][nY] = CURRENT ; 
        }
    }
}

void CTetrisGame::Reach()
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            m_arrBoard[nX][nY] = m_spCurBk->GetId() ; 
        }
    }
    m_spCurBk.release() ; 
    m_spCurBk = nullptr ; 
    Create() ; 
}

void CTetrisGame::Draw(HDC hDC)
{
    m_spCurBk->Draw(hDC) ;
}

void CTetrisGame::Erase(HDC hDC)
{
    m_spCurBk->Erase(hDC) ;
}

// ================================================

void CTetrisGame::Left(HDC hDC)
{
    if(isMoveLeft())
    {
        Erase(hDC) ; 
        m_spCurBk->Left() ; 
    }
}

void CTetrisGame::Right(HDC hDC) 
{   
    if(isMoveRight())
    {
        Erase(hDC) ; 
        m_spCurBk->Right() ; 
    }
}

void CTetrisGame::Rotate(HDC hDC)
{
    if(CanRotate(hDC))
    {
        Erase(hDC) ; 
        m_spCurBk->Rotate() ; 
    }
}

bool CTetrisGame::Down(HDC hDC)
{
    if(isMoveDown())
    {
        Erase(hDC) ; 
        m_spCurBk->Down() ; 
        m_spCurBk->Draw(hDC) ; 
        return false ; 
    }
    else
    {
        m_spCurBk->Draw(hDC) ; 
        Reach() ; 
        return true ;
    }
}

// ================================================

bool CTetrisGame::isMoveLeft() 
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if((m_arrBoard[nX - 1][nY] != CURRENT) && (m_arrBoard[nX - 1][nY] != OFF)) 
            {
                return false ; 
            }
        }
    }
    return true ; 
}

bool CTetrisGame::isMoveRight() 
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if((m_arrBoard[nX + 1][nY] != CURRENT) && (m_arrBoard[nX + 1][nY] != OFF)) 
            {
                return false ; 
            }
        }
    }
    return true ; 
}

bool CTetrisGame::CanRotate(HDC hDC)
{
    INT nX = 0 ; 
    INT nY = 0 ; 
    INT nLCount = 0 ; 
    INT nRCount = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex ,nX, nY))
        {   
            if((m_arrBoard[nX - 1][nY] != CURRENT) && (m_arrBoard[nX - 1][nY] != OFF)) 
            {
                nLCount++ ; 
                if(nLCount > 2) 
                {
                    m_spCurBk->Erase(hDC) ; 
                    m_spCurBk->Right() ;
                    return true ; 
                }
            }
            else if((m_arrBoard[nX + 1][nY] != CURRENT) && (m_arrBoard[nX + 1][nY] != OFF)) 
            {
                nRCount++ ;
                if(nRCount > 2) 
                {
                    m_spCurBk->Erase(hDC) ; 
                    m_spCurBk->Left() ; 
                    return true ; 
                }
            }
        }
    }
    return true ; 
}

bool CTetrisGame::isMoveDown()
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if((m_arrBoard[nX][nY + 1] != CURRENT) && (m_arrBoard[nX][nY + 1] != OFF)) 
            {
                return false ; 
            }
        }
    }
    return true ; 
}