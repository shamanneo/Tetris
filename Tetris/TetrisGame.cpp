#include "pch.h"
#include "TetrisGame.h"
#include "Licky.h"
#include "Ricky.h"
#include "Cleveland.h"
#include "Phodeisland.h"
#include "Teewee.h" 
#include "Smashboy.h" 
#include <time.h>

CTetrisGame::CTetrisGame()
{
    for(INT nY = 0 ; nY <= HEIGHT ; nY++)
    {
        m_arrBoard[0][nY] = BOUND ; 
        m_arrBoard[11][nY] = BOUND ; 
        if(nY < 12)
        {
            m_arrBoard[nY][HEIGHT] = BOUND ; 
        }
    }
    Create() ; 
}

CTetrisGame::~CTetrisGame()
{

}

void CTetrisGame::Create()
{
    srand((unsigned int)time(NULL)) ; 
    int nName = LICKY + (rand() % 6) ; 
    switch(TEEWEE)
    {
        case LICKY :
        {
            m_spCurBk = std::make_unique<CLicky>() ; 
            break ;
        }
        case RICKY :
        {
            m_spCurBk = std::make_unique<CRicky>() ; 
            break ;
        }
        case CLEVELAND :
        {
            m_spCurBk = std::make_unique<CCleveland>() ; 
            break ;
        }
        case PHODEISLAND :
        {
            m_spCurBk = std::make_unique<CPhodeisland>() ; 
            break ;
        }
        case TEEWEE :
        {
            m_spCurBk = std::make_unique<CTeewee>() ; 
            break ;
        }
        case SMASHBOY :
        {
            m_spCurBk = std::make_unique<CSmashboy>() ; 
            break ;
        }
        /*
        case HERO :
        {
            // create HERO.
            break ;
        }
        */
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

void CTetrisGame::Draw()
{
    m_spCurBk->Draw() ;
}

void CTetrisGame::Erase()
{
    m_spCurBk->Erase() ;
}

// ================================================

void CTetrisGame::Left()
{
    if(isMoveLeft())
    {
        Erase() ; 
        m_spCurBk->Left() ; 
    }
}

void CTetrisGame::Right() 
{   
    if(isMoveRight())
    {
        Erase() ; 
        m_spCurBk->Right() ; 
    }
}

void CTetrisGame::Rotate()
{
    if(CanRotate())
    {
        Erase() ; 
        m_spCurBk->Rotate() ; 
    }
}

bool CTetrisGame::Down()
{
    if(isMoveDown())
    {
        Erase() ; 
        m_spCurBk->Down() ; 
        m_spCurBk->Draw() ; 
        return false ; 
    }
    else
    {
        m_spCurBk->Draw() ; 
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

bool CTetrisGame::CanRotate()
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
                    m_spCurBk->Erase() ; 
                    m_spCurBk->Right() ;
                    return true ; 
                }
            }
            else if((m_arrBoard[nX + 1][nY] != CURRENT) && (m_arrBoard[nX + 1][nY] != OFF)) 
            {
                nRCount++ ;
                if(nRCount > 2) 
                {
                    m_spCurBk->Erase() ; 
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