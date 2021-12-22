#include "pch.h"
#include "TetrisGame.h"
#include "Licky.h"
#include "Ricky.h"
#include "Cleveland.h"
#include "Phodeisland.h"
#include "Teewee.h" 
#include "Smashboy.h" 
#include <time.h>
#include "Paint.h" 

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
    int nName = TEEWEE + (rand() % 2) ; 
    switch(nName)
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
}

void CTetrisGame::Reach()
{
    INT nX = 0 ;
    INT nY = 0 ; 
    // INT nLine = 100 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
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
    if(CanRotate())
    {
        m_spCurBk->Rotate() ; 
    }
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
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
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
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
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

bool CTetrisGame::CanRotate() // Need Updating...
{
    INT nX = 0 ; 
    INT nY = 0 ; 
    INT nLCount = 0 ; 
    INT nRCount = 0 ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex ,nX, nY))
        {   
            if(m_arrBoard[nX - 1][nY] != OFF)
            {
                nLCount++ ; 
                if(nLCount > 2) 
                {
                    m_spCurBk->Erase() ; 
                    m_spCurBk->Right() ;
                    return true ; 
                }
            }
            else if(m_arrBoard[nX + 1][nY] != OFF)
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
    for(INT nIndex = 0 ; nIndex < WIDTH - 1 ; nIndex++)
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