#include "pch.h"
#include "BlockT.h"

CBlockT::CBlockT()
    :m_nId(32)
{
    m_spPosArr = std::make_unique<CSpace[]>(9) ; 
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

CBlockT::~CBlockT()
{

}

bool CBlockT::GetPos(INT nIndex, INT &nX, INT &nY) const
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(m_spPosArr[nIndex].m_bPres)
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
        if(!m_spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * (m_spPosArr[i].m_nX - 1) + 32, 30 * (m_spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
}

void CBlockT::Erase(HDC hDC)
{
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush whiteBru { Gdiplus::Color { 255, 255, 255 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&whiteBru, 30 * (m_spPosArr[i].m_nX - 1) + 32, 30 * (m_spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
}

void CBlockT::Left() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_spPosArr[nIndex].IsEmpty())
        {
            m_spPosArr[nIndex].m_nX-- ;         
        }
    }
}

void CBlockT::Right()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_spPosArr[nIndex].IsEmpty())
        {
            m_spPosArr[nIndex].m_nX++ ;         
        }
    }
}

void CBlockT::Rotate() 
{
    std::unique_ptr<CSpace[]> spTempPosArr = std::make_unique<CSpace[]>(9) ; 

    m_spPosArr = std::move(spTempPosArr) ; 
}

void CBlockT::Down()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        if(!m_spPosArr[nIndex].IsEmpty())
        {
            m_spPosArr[nIndex].m_nY++ ; 
        }
    }
}



