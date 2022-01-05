#include "pch.h"
#include "Paint.h" 
#include "Command.h"

CCommand::CCommand()
{
    m_spTetrisGm = std::make_unique<CTetrisGame>() ; 
}

CCommand::~CCommand()
{

}

void CCommand::InputKey(INT nKey)
{
    switch (nKey)
    {
        case VK_RETURN :
        {
            break ; 
        }
        case VK_LEFT :
        {
            Left() ; 
            break ; 
        }
        case VK_RIGHT :
        {
            Right() ; 
            break ; 
        }
        case VK_UP :
        {
            Rotate() ;
            break ; 
        }
        case VK_DOWN :
        {
            Down() ; 
            break ; 
        }
        case VK_SPACE :
        {
            FastDown() ;
            break ; 
        }
        default :
        {
            break ; 
        } 
    }
    m_spTetrisGm->Draw() ;         
}

void CCommand::Draw() 
{
    m_spTetrisGm->Draw() ; 
}

void CCommand::Erase() 
{
    m_spTetrisGm->Erase() ; 
}

void CCommand::Begin() 
{
    m_spTetrisGm->Create() ; 
}

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
    m_spTetrisGm->Down() ; 
}

void CCommand::FastDown()
{
    while(!m_spTetrisGm->Down())
    {

    }
    CMainApp::GetInstance().SetScore(30) ; 
}

void CCommand::PaintBoard() 
{
    m_spTetrisGm->OutUpdate() ; 
}
