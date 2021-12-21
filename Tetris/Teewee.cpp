#include "pch.h"
#include "Teewee.h"
#include <math.h>
#include "Paint.h"

CTeewee::CTeewee()
    :m_nId(32)
{
    m_spPosArr = std::make_unique<CSpace[]>(BLOCKSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF) ; 
    m_spPosArr[1].Set(5, 0, ON) ; 
    m_spPosArr[2].Set(6, 0, OFF) ; 
    m_spPosArr[3].Set(4, 1, ON) ; 
    m_spPosArr[4].Set(5, 1, ON) ; 
    m_spPosArr[5].Set(6, 1, ON) ; 
    m_spPosArr[6].Set(4, 2, OFF) ; 
    m_spPosArr[7].Set(5, 2, OFF) ; 
    m_spPosArr[8].Set(6, 2, OFF) ; 
}

CTeewee::~CTeewee()
{

}

bool CTeewee::GetPos(INT nIndex, INT &nX, INT &nY) const
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(!m_spPosArr[nIndex].m_bPres)
    {
        return false ; 
    }
    return true ; 
}

INT CTeewee::GetId() const 
{
    return m_nId ; 
}

void CTeewee::Draw() 
{   
    CPaint paint ; 
    paint.PaintBlock(m_spPosArr, 102, 0, 153) ; 
}

void CTeewee::Erase()
{
    CPaint paint ; 
    paint.EraseBlock(m_spPosArr) ; 
}

void CTeewee::Left() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CTeewee::Right()
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX++ ;         
    }
}

void CTeewee::Rotate() 
{
    Erase() ; 
    bool bArr[9] { } ; 
    for(INT i = 0 ; i < 9 ; i++)
    {
        if(m_spPosArr[i].m_bPres == true)
        {
            bArr[i] = m_spPosArr[i].m_bPres ; 
        }
        m_spPosArr[i].m_bPres = OFF ; 
    }
    m_spPosArr[0].m_bPres = bArr[6] ; 
    m_spPosArr[1].m_bPres = bArr[3] ; 
    m_spPosArr[2].m_bPres = bArr[0] ; 
    m_spPosArr[3].m_bPres = bArr[7] ; 
    m_spPosArr[4].m_bPres = bArr[4] ; 
    m_spPosArr[5].m_bPres = bArr[1] ; 
    m_spPosArr[6].m_bPres = bArr[8] ; 
    m_spPosArr[7].m_bPres = bArr[5] ; 
    m_spPosArr[8].m_bPres = bArr[2] ; 
}

void CTeewee::Down()
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}



