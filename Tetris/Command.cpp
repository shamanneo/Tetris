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

void CCommand::InputKey(int nKey)
{
    switch (nKey)
    {
        case LEFT :
        {
            Left() ; 
            break ; 
        }
        case RIGHT :
        {
            Right() ; 
            break ; 
        }
        case UP :
        {
            Rotate() ;
            break ; 
        }
        case DOWN :
        {
            Down() ; 
            break ; 
        }
        case SPACE :
        {
            while(!m_spTetrisGm->Down())
            {

            }
        }
    }
    m_spTetrisGm->Draw() ;         
}

void CCommand::Draw() 
{
    m_spTetrisGm->Draw() ; 
}

// ===========================

void CCommand::Left() 
{
    m_spTetrisGm->Left() ; 
}

void CCommand::Right() 
{
    m_spTetrisGm->Right() ; 
}

void CCommand::Rotate() 
{
    m_spTetrisGm->Rotate() ; 
}

void CCommand::Down()
{
    m_spTetrisGm->Erase() ; 
    m_spTetrisGm->Down() ; 
}

