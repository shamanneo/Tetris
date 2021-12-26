#include "pch.h"
#include "Ricky.h"
#include <math.h>
#include "Paint.h"

CRicky::CRicky(INT nArrSize)
    : CBlock(nArrSize), m_nId(31)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, OFF, MIDPOS) ; 
    m_spPosArr[2].Set(6, 0, ON, RIGHTPOS) ; 
    m_spPosArr[3].Set(4, 1, ON, LEFTPOS) ; 
    m_spPosArr[4].Set(5, 1, ON, MIDPOS) ; 
    m_spPosArr[5].Set(6, 1, ON, RIGHTPOS) ; 
    m_spPosArr[6].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[7].Set(5, 2, OFF, MIDPOS) ; 
    m_spPosArr[8].Set(6, 2, OFF, RIGHTPOS) ; 
}

CRicky::~CRicky()
{

}

INT CRicky::GetId() const 
{
    return m_nId ; 
}

void CRicky::Draw() 
{   
    CPaint paint ; 
    paint.PaintBlock(m_spPosArr, 255, 127, 0) ; 
}

void CRicky::FutureDraw() 
{   
    CPaint paint ; 
    paint.PaintBlock(m_spPosArr, 255, 204, 153) ; 
}






