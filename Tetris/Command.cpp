#include "pch.h"
#include "Command.h"
#include "BlockT.h"

CCommand::CCommand()
{
    m_spTetrisGm = std::make_unique<CTetrisGame>() ; 
}

CCommand::~CCommand()
{

}

void CCommand::InputKey(int nKey, HDC hDC)
{
    switch (nKey)
    {
        case LEFT :
        {
            OnLeft(hDC) ; 
            break ; 
        }
        case RIGHT :
        {
            OnRight(hDC) ; 
            break ; 
        }
        case UP :
        {
            OnUp(hDC) ;
            break ; 
        }
        case DOWN :
        {
            OnDown(hDC) ; 
            break ; 
        }
    }
    m_spTetrisGm->Draw(hDC) ;         
}

void CCommand::Draw(HDC hDC) 
{
    m_spTetrisGm->Draw(hDC) ; 
}

void CCommand::Erase(HDC hDC)
{
    m_spTetrisGm->Erase(hDC) ; 
}

void CCommand::Down() 
{
    m_spTetrisGm->Down() ; 
}

void CCommand::OnLeft(HDC hDC) 
{
    m_spTetrisGm->Left() ; 
}

void CCommand::OnRight(HDC hDC) 
{
    m_spTetrisGm->Right() ; 
}

void CCommand::OnUp(HDC hDC) 
{

}

void CCommand::OnDown(HDC hDC)
{
    m_spTetrisGm->Down() ; 
}

