#include "pch.h"
#include "Teewee.h"
#include <math.h>
#include "Paint.h"

CTeewee::CTeewee(INT nArrSize)
    : CBlock(nArrSize), m_nId(34)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, ON, MIDPOS) ; 
    m_spPosArr[2].Set(6, 0, OFF, RIGHTPOS) ; 
    m_spPosArr[3].Set(4, 1, ON, LEFTPOS) ; 
    m_spPosArr[4].Set(5, 1, ON, MIDPOS) ; 
    m_spPosArr[5].Set(6, 1, ON, RIGHTPOS) ; 
    m_spPosArr[6].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[7].Set(5, 2, OFF, MIDPOS) ; 
    m_spPosArr[8].Set(6, 2, OFF, RIGHTPOS) ; 
}

CTeewee::~CTeewee()
{

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

void CTeewee::Rotate(INT m_arrBoard[][HEIGHT + 1]) 
{
    Erase() ; 
    bool bArr[ARRAYSIZE] { } ; 
    for(INT nIndex = 0 ; nIndex < ARRAYSIZE ; nIndex++)
    {
        if(m_spPosArr[nIndex].m_bPres == true)
        {
            bArr[nIndex] = m_spPosArr[nIndex].m_bPres ; 
        }
        m_spPosArr[nIndex].m_bPres = OFF ; 
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

    for(INT nIndex = 0 ; nIndex < ARRAYSIZE ; nIndex++)
    {
        if((m_spPosArr[nIndex].m_bPres == true) && IsOutOfBoundary(nIndex))
        {
            if(m_spPosArr[nIndex].m_nPos == LEFTPOS)
            {
                Right() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == RIGHTPOS)
            {
                Left() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == MIDPOS)
            {
                Up() ; 
            }
        }
    }
}




