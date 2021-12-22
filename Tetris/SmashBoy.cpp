#include "pch.h"
#include "Smashboy.h"
#include <math.h>
#include "Paint.h"

CSmashboy::CSmashboy()
    :m_nId(35)
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
    CPaint paint ; 
    paint.PaintBlock(m_spPosArr, 255, 212, 0) ; 
}

void CSmashboy::Erase()
{
    CPaint paint ; 
    paint.EraseBlock(m_spPosArr) ; 
}

void CSmashboy::Left() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CSmashboy::Right()
{
    Erase() ; 
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
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}



