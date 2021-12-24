#include "pch.h"
#include "Block.h"
#include "Paint.h"

CBlock::CBlock(INT nArrSize)
{
    m_nArrSize = nArrSize ; 
    m_spPosArr = std::make_unique<CSpace[]>(m_nArrSize) ; 
}

CBlock::~CBlock()
{

}

bool CBlock::GetPos(INT nIndex, INT &nX, INT &nY) const 
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(!m_spPosArr[nIndex].m_bPres)
    {
        return false ; 
    }
    return true ; 
}

INT CBlock::GetId() const 
{
    return 0 ; 
}

bool CBlock::IsOutOfBoundary(INT nIndex) const 
{
    return (m_spPosArr[nIndex].m_nX == 0) || (m_spPosArr[nIndex].m_nX == 11) || (m_spPosArr[nIndex].m_nY == 20) ? true : false ; 
}

void CBlock::Draw() 
{
    return ; 
}

void CBlock::Erase()
{
    CPaint paint ; 
    paint.EraseBlock(m_spPosArr, m_nArrSize) ; 
}

void CBlock::Left() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CBlock::Right() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX++ ;         
    }
}

void CBlock::Rotate(INT m_arrBoard[][HEIGHT + 1])
{
    return ; 
}


void CBlock::Up() // Only for rotating when the block is out of boundary.
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY-- ; 
    }
}

void CBlock::Down()
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}
    