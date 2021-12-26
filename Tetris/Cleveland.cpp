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

void CCleveland::FutureDraw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 255, 102, 102) ; 
}






