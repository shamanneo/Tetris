#include "pch.h"
#include "BlockT.h"

CBlockT::CBlockT()
    :m_nId(32)
{
    m_posArray = new CPos[9] ; 
    m_posArray[0].Set(0, 0) ; 
    m_posArray[1].Set(5, 0) ; 
    m_posArray[2].Set(0, 0) ; 
    m_posArray[3].Set(4, 1) ; 
    m_posArray[4].Set(5, 1) ; 
    m_posArray[5].Set(6, 1) ; 
    m_posArray[6].Set(0, 0) ; 
    m_posArray[7].Set(0, 0) ; 
    m_posArray[8].Set(0, 0) ; 
}

CBlockT::~CBlockT()
{
    delete[] m_posArray ; 
}

bool CBlockT::GetPos(INT nIndex, INT &nX, INT &nY) const
{
    nX = m_posArray[nIndex].m_nX ;
    nY = m_posArray[nIndex].m_nY ;
    if((nX == 0) && (nY == 0))
    {
        return false ; 
    }
    return true ; 
}

INT CBlockT::GetId() const 
{
    return m_nId ; 
}

void CBlockT::Draw(HDC hDC) 
{   
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush blackBru { Gdiplus::Color { 255, 0, 0 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * (m_posArray[i].m_nX - 1) + 32, 30 * (m_posArray[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
}

void CBlockT::Erase(HDC hDC)
{
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush whiteBru { Gdiplus::Color { 255, 255, 255 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            grap.FillRectangle(&whiteBru, 30 * (m_posArray[i].m_nX - 1) + 32, 30 * (m_posArray[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
}

void CBlockT::Left() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_posArray[nIndex].IsEmpty())
        {
            m_posArray[nIndex].m_nX-- ;         
        }
    }
}

void CBlockT::Right()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_posArray[nIndex].IsEmpty())
        {
            m_posArray[nIndex].m_nX++ ;         
        }
    }
}

void CBlockT::Down()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_posArray[nIndex].IsEmpty())
        {
            m_posArray[nIndex].m_nY++ ; 
        }
    }
}



