#include "pch.h"
#include "Hero.h"
#include <math.h>
#include "Paint.h"

CHero::CHero(INT nArrSize)
    : CBlock(nArrSize), m_nId(36)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, OFF, LEFTPOS) ; 
    m_spPosArr[2].Set(6, 0, OFF, RIGHTPOS) ; 
    m_spPosArr[3].Set(7, 0, OFF, RIGHTPOS) ; 

    m_spPosArr[4].Set(4, 1, ON, LEFTPOS) ; 
    m_spPosArr[5].Set(5, 1, ON, LEFTPOS) ; 
    m_spPosArr[6].Set(6, 1, ON, RIGHTPOS) ; 
    m_spPosArr[7].Set(7, 1, ON, RIGHTPOS) ; 

    m_spPosArr[8].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[9].Set(5, 2, OFF, LEFTPOS) ; 
    m_spPosArr[10].Set(6, 2, OFF, RIGHTPOS) ; 
    m_spPosArr[11].Set(7, 2, OFF, RIGHTPOS) ; 

    m_spPosArr[12].Set(4, 3, OFF, MIDPOS) ; 
    m_spPosArr[13].Set(5, 3, OFF, MIDPOS) ; 
    m_spPosArr[14].Set(6, 3, OFF, MIDPOS) ; 
    m_spPosArr[15].Set(7, 3, OFF, MIDPOS) ; 
}

CHero::~CHero()
{

}

INT CHero::GetId() const 
{
    return m_nId ; 
}

void CHero::Draw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 0, 163, 210, ARRAYSIZE) ; 
}

void CHero::FutureDraw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 153, 255, 255, ARRAYSIZE) ; 
}

void CHero::Rotate(INT m_arrBoard[][HEIGHT + 1]) 
{
    Erase() ; 
    bool bArr[ARRAYSIZE] { } ; 
    for(INT i = 0 ; i < ARRAYSIZE ; i++)
    {
        if(m_spPosArr[i].m_bPres == true)
        {
            bArr[i] = m_spPosArr[i].m_bPres ; 
        }
        m_spPosArr[i].m_bPres = OFF ; 
    }

    m_spPosArr[0].m_bPres = bArr[12] ; 
    m_spPosArr[1].m_bPres = bArr[8] ; 
    m_spPosArr[2].m_bPres = bArr[4] ; 
    m_spPosArr[3].m_bPres = bArr[0] ; 

    m_spPosArr[4].m_bPres = bArr[13] ; 
    m_spPosArr[5].m_bPres = bArr[9] ; 
    m_spPosArr[6].m_bPres = bArr[5] ; 
    m_spPosArr[7].m_bPres = bArr[1] ; 

    m_spPosArr[8].m_bPres = bArr[14] ; 
    m_spPosArr[9].m_bPres = bArr[10] ; 
    m_spPosArr[10].m_bPres = bArr[6] ; 
    m_spPosArr[11].m_bPres = bArr[2] ; 

    m_spPosArr[12].m_bPres = bArr[15] ; 
    m_spPosArr[13].m_bPres = bArr[11] ; 
    m_spPosArr[14].m_bPres = bArr[7] ; 
    m_spPosArr[15].m_bPres = bArr[3] ; 

    for(INT nIndex = 0 ; nIndex < 16 ; nIndex++)
    {
        if((m_spPosArr[nIndex].m_bPres == true) && IsOutOfBoundary(nIndex))
        {
            if(m_spPosArr[nIndex].m_nPos == LEFTPOS)
            {
                Right() ; 
                Right() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == RIGHTPOS)
            {
                Left() ; 
                Left() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == MIDPOS)
            {
                Up() ; 
                Up() ; 
            }
        }
    }
}







