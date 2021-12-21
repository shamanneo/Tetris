#include "pch.h"
#include "Phodeisland.h"
#include <math.h>

CPhodeisland::CPhodeisland()
    :m_nId(33)
{
    m_spPosArr = std::make_unique<CSpace[]>(BLOCKSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF) ; 
    m_spPosArr[1].Set(5, 0, ON) ; 
    m_spPosArr[2].Set(6, 0, ON) ; 
    m_spPosArr[3].Set(4, 1, ON) ; 
    m_spPosArr[4].Set(5, 1, ON) ; 
    m_spPosArr[5].Set(6, 1, OFF) ; 
    m_spPosArr[6].Set(4, 2, OFF) ; 
    m_spPosArr[7].Set(5, 2, OFF) ; 
    m_spPosArr[8].Set(6, 2, OFF) ; 
}

CPhodeisland::~CPhodeisland()
{

}

bool CPhodeisland::GetPos(INT nIndex, INT &nX, INT &nY) const
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(!m_spPosArr[nIndex].m_bPres)
    {
        return false ; 
    }
    return true ; 
}

INT CPhodeisland::GetId() const 
{
    return m_nId ; 
}

void CPhodeisland::Draw() 
{   
    /*
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush blackBru { Gdiplus::Color { 0, 128, 0 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_spPosArr[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * (m_spPosArr[i].m_nX - 1) + 32, 30 * (m_spPosArr[i].m_nY - 0) + 32, 28, 28) ; 
        }
    }
    */
}

void CPhodeisland::Erase()
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

void CPhodeisland::Left() 
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CPhodeisland::Right()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX++ ;         
    }
}

void CPhodeisland::Rotate() 
{
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

void CPhodeisland::Down()
{
    for(INT nIndex = 0 ; nIndex < 9 ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}





