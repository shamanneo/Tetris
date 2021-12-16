#include "pch.h"
#include "Command.h"
#include "Teewee.h"

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
            //OnRotate(hDC) ;
            break ; 
        }
        case DOWN :
        {
            OnDown(hDC) ; 
            break ; 
        }
        case SPACE :
        {
            while(!m_spTetrisGm->Down(hDC))
            {

            }
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

void CCommand::Down(HDC hDC) 
{
    m_spTetrisGm->Down(hDC) ; 
}

// ===========================

void CCommand::OnLeft(HDC hDC) 
{
    m_spTetrisGm->Left(hDC) ; 
}

void CCommand::OnRight(HDC hDC) 
{
    m_spTetrisGm->Right(hDC) ; 
}

void CCommand::OnRotate(HDC hDC) 
{
    m_spTetrisGm->Rotate(hDC) ; 
}

void CCommand::OnDown(HDC hDC)
{
    m_spTetrisGm->Down(hDC) ; 
}

