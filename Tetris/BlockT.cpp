#include "pch.h"
#include "BlockT.h"

const int CBlockT::m_nSize = 4 ; 

CBlockT::CBlockT()
    : m_bIsReached(false) 
{
    m_posArray = new CPos[9] ; 
    m_posArray[0].Set(0, 0) ; 
    m_posArray[1].Set(4, 0) ; 
    m_posArray[2].Set(0, 0) ; 
    m_posArray[3].Set(3, 1) ; 
    m_posArray[4].Set(4, 1) ; 
    m_posArray[5].Set(5, 1) ; 
    m_posArray[6].Set(0, 0) ; 
    m_posArray[7].Set(0, 0) ; 
    m_posArray[8].Set(0, 0) ; 
}

CBlockT::~CBlockT()
{
    delete[] m_posArray ; 
}

void CBlockT::Draw(HDC hDC) 
{   
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::SolidBrush blackBru { Gdiplus::Color { 255, 0, 0 } } ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            grap.FillRectangle(&blackBru, 30 * m_posArray[i].m_nX + 32, 30 * m_posArray[i].m_nY + 32, 28, 28) ; 
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
            grap.FillRectangle(&whiteBru, 30 * m_posArray[i].m_nX + 32, 30 * m_posArray[i].m_nY + 32, 28, 28) ; 
        }
    }
}

void CBlockT::RightRotate()
{
    CPos posTempArr[9] ; 
    posTempArr[0] = m_posArray[2] ; 
    posTempArr[1] = m_posArray[5] ; 
    posTempArr[2] = m_posArray[8] ; 
    posTempArr[3] = m_posArray[1] ; 
    posTempArr[4] = m_posArray[4] ; 
    posTempArr[5] = m_posArray[7] ; 
    posTempArr[6] = m_posArray[0] ; 
    posTempArr[7] = m_posArray[3] ; 
    posTempArr[8] = m_posArray[6] ; 

    m_posArray = posTempArr ; 
}

void CBlockT::Down()
{
    if(m_bIsReached)
    {
        return ; 
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            int nY = ++m_posArray[i].m_nY ; 
            if(nY == 19)
            {
                m_bIsReached = true ;
            }
        }
    }
}

void CBlockT::Left() 
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            m_posArray[i].m_nX-- ;         
        }
    }
}

void CBlockT::Right()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(!m_posArray[i].IsEmpty())
        {
            m_posArray[i].m_nX++ ;         
        }
    }
}




