#include "pch.h"
#include "Smashboy.h"
#include <math.h>
#include "Paint.h"

CSmashboy::CSmashboy(INT nArrSize)
    : CBlock(nArrSize), m_nId(35)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, ON, MIDPOS) ; 
    m_spPosArr[2].Set(6, 0, ON, RIGHTPOS) ; 
    m_spPosArr[3].Set(4, 1, OFF, LEFTPOS) ; 
    m_spPosArr[4].Set(5, 1, ON, MIDPOS) ; 
    m_spPosArr[5].Set(6, 1, ON, RIGHTPOS) ; 
    m_spPosArr[6].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[7].Set(5, 2, OFF, MIDPOS) ; 
    m_spPosArr[8].Set(6, 2, OFF, RIGHTPOS) ; 
}

CSmashboy::~CSmashboy()
{

}

INT CSmashboy::GetId() const 
{
    return m_nId ; 
}

void CSmashboy::Draw() 
{   
    CPaint paint ; 
    paint.PaintBlock(m_spPosArr, 255, 212, 0) ; 
}

void CSmashboy::Rotate() 
{
    return ; 
}




