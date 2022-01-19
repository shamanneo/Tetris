#include "pch.h"
#include "Paint.h"
#include "CGameInfo.h"

CGameInfo::CGameInfo() 
{
    m_nScore = 0 ; 
    m_nLevel = 1 ; 
    m_nLine = 0 ; 
}

CGameInfo::~CGameInfo() 
{

}

void CGameInfo::Reset()
{
    m_nScore = 0 ; 
    m_nLevel = 1 ; 
    m_nLine = 0 ; 
}

void CGameInfo::Draw(HWND hWnd) 
{
    CPaint paint { hWnd } ; 
    paint.DrawInfo(m_nScore, m_nLevel, m_nLine) ; 
}