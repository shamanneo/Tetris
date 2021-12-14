#include "pch.h"
#include "TetrisGame.h"
#include "BlockT.h" 
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
    srand(unsigned int(NULL)) ; 
    int nName = LICKY + (rand() % 7) ; 
    switch(TEEWEE)
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
            m_spCurBk = std::make_unique<CBlockT>() ; 
            break ;
        }
        case SMASHBOY :
        {
            // create SMASHBOY.
            break ;
        }
    }

    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        INT nX = 0 ;
        INT nY = 0 ; 
        if(m_spCurBk->GetPos(nIndex, nX, nY)) 
        {
            m_arrBoard[nX][nY] = CURRENT ; 
        }
    }
}

void CTetrisGame::Reach()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        INT nX = 0 ;
        INT nY = 0 ; 
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

}

void CTetrisGame::Down(HDC hDC)
{
    if(isMoveDown())
    {
        Erase(hDC) ; 
        m_spCurBk->Down() ; 
        m_spCurBk->Draw(hDC) ; 
    }
    else
    {
        m_spCurBk->Draw(hDC) ; 
        Reach() ; 
    }
    return ; 
}

// ================================================

bool CTetrisGame::isMoveLeft() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        INT nX = 0 ;
        INT nY = 0 ; 
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

bool CTetrisGame::isMoveRight() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        INT nX = 0 ;
        INT nY = 0 ; 
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

bool CTetrisGame::CanRotate()
{
    return true ; 
}

bool CTetrisGame::isMoveDown()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        INT nX = 0 ;
        INT nY = 0 ; 
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