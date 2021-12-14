#include "pch.h"
#include "TetrisGame.h"
#include "BlockT.h"

CTetrisGame::CTetrisGame()
{
    m_blockCurr = std::make_unique<CBlockT>() ; 
}

CTetrisGame::~CTetrisGame()
{

}

void CTetrisGame::InputKey(int nKey, HDC hDC)
{
    switch (nKey)
    {
        case LEFT :
        {
            m_blockCurr->Erase(hDC) ; 
            m_blockCurr->Left() ; 
            break ; 
        }
        case RIGHT :
        {
            m_blockCurr->Erase(hDC) ; 
            m_blockCurr->Right() ; 
            break ; 
        }
        case UP :
        {
            break ; 
        }
        case DOWN :
        {
            m_blockCurr->Erase(hDC) ; 
            m_blockCurr->Down() ; 
            break ; 
        }
    }
    m_blockCurr->Draw(hDC) ;         
}

void CTetrisGame::SetBlock() 
{
    // random..
    m_blockCurr = std::make_unique<CBlockT>() ;
}

void CTetrisGame::Draw(HDC hDC) 
{
    m_blockCurr->Draw(hDC) ; 
}

void CTetrisGame::Erase(HDC hDC)
{
    m_blockCurr->Erase(hDC) ; 
}

void CTetrisGame::Down() 
{
    m_blockCurr->Down() ; 
}

