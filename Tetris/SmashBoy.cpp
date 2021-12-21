#include "pch.h"
#include "Smashboy.h"
#include <math.h>

CSmashboy::CSmashboy()
    :m_nId(36)
{
    m_spPosArr = std::make_unique<CSpace[]>(BLOCKSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF) ; 
    m_spPosArr[1].Set(5, 0, ON) ; 
    m_spPosArr[2].Set(6, 0, ON) ; 
    m_spPosArr[3].Set(4, 1, OFF) ; 
    m_spPosArr[4].Set(5, 1, ON) ; 
    m_spPosArr[5].Set(6, 1, ON) ; 
    m_spPosArr[6].Set(4, 2, OFF) ; 
    m_spPosArr[7].Set(5, 2, OFF) ; 
    m_spPosArr[8].Set(6, 2, OFF) ; 
}

CSmashboy::~CSmashboy()
{

}

bool CSmashboy::GetPos(INT nIndex, INT &nX, INT &nY) const
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(!m_spPosArr[nIndex].m_bPres)
    {
        return false ; 
    }
    return true ; 
}

INT CSmashboy::GetId() const 
{
    return m_nId ; 
}

void CSmashboy::Draw() 
{   
    /*
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush blackBru { Gdiplus::Color { 255, 212, 0 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * (m_spPosArr[i].m_nX - 1) + 32, 30 * (m_spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
    */
}

void CSmashboy::Erase()
{
    /*
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush whiteBru { Gdiplus::Color { 255, 255, 255 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&whiteBru, 30 * (m_spPosArr[i].m_nX - 1) + 32, 30 * (m_spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
    */
}

void CSmashboy::Left() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CSmashboy::Right()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX++ ;         
    }
}

void CSmashboy::Rotate() 
{
    
}

void CSmashboy::Down()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}



