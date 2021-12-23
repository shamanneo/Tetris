#include "pch.h"
#include "TetrisGame.h"
#include "Licky.h"
#include "Ricky.h"
#include "Cleveland.h"
#include "Phodeisland.h"
#include "Teewee.h" 
#include "Smashboy.h" 
#include "Hero.h" 
#include <time.h>
#include "Paint.h" 

CTetrisGame::CTetrisGame()
{
    m_nArrSize = DEFAULT_ARRAY_SIZE ; 
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
    INT nId = LICKY + (rand() % 7) ; 
    switch(nId)
    {
        case LICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CLicky>(m_nArrSize) ; 
            break ;
        }
        case RICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CRicky>(m_nArrSize) ; 
            break ;
        }
        case CLEVELAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CCleveland>(m_nArrSize) ; 
            break ;
        }
        case PHODEISLAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CPhodeisland>(m_nArrSize) ; 
            break ;
        }
        case TEEWEE :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ;
            m_spCurBk = std::make_unique<CTeewee>(m_nArrSize) ; 
            break ;
        }
        case SMASHBOY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CSmashboy>(m_nArrSize) ; 
            break ;
        }
        case HERO :
        {
            m_nArrSize = HERO_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CHero>(m_nArrSize) ; 
            break ;
        }
    }
}

void CTetrisGame::Reach()
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            m_arrBoard[nX][nY] = m_spCurBk->GetId() ; 
            if(IsFull(nY))
            {
                InUpdate(nY) ; 
                OutUpdate() ; 
            }
        }
    }
    m_spCurBk.release() ; 
    m_spCurBk = nullptr ; 
    Create() ; 
}

bool CTetrisGame::IsFull(INT nLine) 
{
    for(INT nX = 1 ; nX <= WIDTH ; nX++)
    {
        if(m_arrBoard[nX][nLine] == OFF)
        {
            return false ; 
        }
    }
    return true ; 
}

void CTetrisGame::InUpdate(INT nLine)
{   
    for(INT nX = 1 ; nX <= WIDTH ; nX++)
    {
        m_arrBoard[nX][nLine] = OFF ; // Clear line. 
    }
    for(INT nX = 1 ; nX <= WIDTH ; nX++)
    {
        for(INT nY = nLine - 1 ; nY >= 0  ; nY--)
        {
            m_arrBoard[nX][nY + 1] = m_arrBoard[nX][nY] ; 
        }
    }
}

void CTetrisGame::OutUpdate()
{
    CPaint paint ; 
    paint.EraseBoard() ; 
    paint.PaintBoard(m_arrBoard) ; 
}

// ================================================
 
void CTetrisGame::Draw()
{
    m_spCurBk->Draw() ;
}

// ================================================

void CTetrisGame::Left()
{
    if(isMoveLeft())
    {
        m_spCurBk->Left() ; 
    }
}

void CTetrisGame::Right() 
{   
    if(isMoveRight())
    {
        m_spCurBk->Right() ; 
    }
}

void CTetrisGame::Rotate()
{
    m_spCurBk->Rotate() ; 
}

bool CTetrisGame::Down()
{
    if(isMoveDown())
    {
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
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX - 1][nY] != OFF)
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
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX + 1][nY] != OFF)
            {
                return false ; 
            }
        }
    }
    return true ; 
}

bool CTetrisGame::isMoveDown()
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX][nY + 1] != OFF)
            {
                return false ; 
            }
        }
    }
    return true ; 
}