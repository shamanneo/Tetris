#include "pch.h"
#include "Cleveland.h"
#include <math.h>
#include "Paint.h"

CCleveland::CCleveland(INT nArrSize)
    : CBlock(nArrSize), m_nId(32)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, ON, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, ON, MIDPOS) ; 
    m_spPosArr[2].Set(6, 0, OFF, RIGHTPOS) ; 
    m_spPosArr[3].Set(4, 1, OFF, LEFTPOS) ; 
    m_spPosArr[4].Set(5, 1, ON, MIDPOS) ; 
    m_spPosArr[5].Set(6, 1, ON, RIGHTPOS) ; 
    m_spPosArr[6].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[7].Set(5, 2, OFF, MIDPOS) ; 
    m_spPosArr[8].Set(6, 2, OFF, RIGHTPOS) ; 
}

CCleveland::~CCleveland()
{

}
INT CCleveland::GetId() const 
{
    return m_nId ; 
}

void CCleveland::Draw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 255, 0, 0) ; 
}

void CCleveland::Rotate() 
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




