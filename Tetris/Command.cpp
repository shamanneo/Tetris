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

// ===========================

void CCommand::InputKey(int nKey, HDC hDC)
{
    switch (nKey)
    {
        case LEFT :
        {
            Left(hDC) ; 
            break ; 
        }
        case RIGHT :
        {
            Right(hDC) ; 
            break ; 
        }
        case UP :
        {
            Rotate(hDC) ;
            break ; 
        }
        case DOWN :
        {
            Down(hDC) ; 
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

// ===========================

void CCommand::Left(HDC hDC) 
{
    m_spTetrisGm->Left(hDC) ; 
}

void CCommand::Right(HDC hDC) 
{
    m_spTetrisGm->Right(hDC) ; 
}

void CCommand::Rotate(HDC hDC) 
{
    m_spTetrisGm->Rotate(hDC) ; 
}

void CCommand::Down(HDC hDC)
{
    m_spTetrisGm->Erase(hDC) ; 
    m_spTetrisGm->Down(hDC) ; 
}

