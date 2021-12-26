#include "pch.h"
#include "Phodeisland.h"
#include <math.h>
#include "Paint.h"

CPhodeisland::CPhodeisland(INT nArrSize)
    : CBlock(nArrSize), m_nId(33)
{
    m_spPosArr = std::make_unique<CSpace[]>(ARRAYSIZE) ; 
    m_spPosArr[0].Set(4, 0, OFF, LEFTPOS) ; 
    m_spPosArr[1].Set(5, 0, ON, MIDPOS) ; 
    m_spPosArr[2].Set(6, 0, ON, RIGHTPOS) ; 
    m_spPosArr[3].Set(4, 1, ON, LEFTPOS) ; 
    m_spPosArr[4].Set(5, 1, ON, MIDPOS) ; 
    m_spPosArr[5].Set(6, 1, OFF, RIGHTPOS) ; 
    m_spPosArr[6].Set(4, 2, OFF, LEFTPOS) ; 
    m_spPosArr[7].Set(5, 2, OFF, MIDPOS) ; 
    m_spPosArr[8].Set(6, 2, OFF, RIGHTPOS) ; 
}

CPhodeisland::~CPhodeisland()
{

}

INT CPhodeisland::GetId() const 
{
    return m_nId ; 
}

void CPhodeisland::Draw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 0, 128, 0) ; 
}

void CPhodeisland::FutureDraw() 
{   
    CPaint paint ;
    paint.PaintBlock(m_spPosArr, 102, 255, 51) ; 
}





