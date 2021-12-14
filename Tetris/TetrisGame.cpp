#include "pch.h"
#include "TetrisGame.h"

CTetrisGame::CTetrisGame()
{
    memset(m_arrBoard, OFF, sizeof(m_arrBoard)) ; 
}

CTetrisGame::~CTetrisGame()
{

}


void CTetrisGame::Create()
{

}

void CTetrisGame::Draw(HDC hDC)
{

}

void CTetrisGame::Erase(HDC hDC)
{

}

void CTetrisGame::Left()
{
    
}

void CTetrisGame::Right() 
{

}

void CTetrisGame::Down()
{

}

bool CTetrisGame::isMoveLeft() 
{
    return true ; 
}

bool CTetrisGame::isMoveRight() 
{
    return true ; 
}

bool CTetrisGame::isMoveDown()
{
    return true ; 
}