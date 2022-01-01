#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Phodeisland.h"

CPhodeisland::CPhodeisland(INT nArrSize)
    : CBlock(nArrSize), m_eId(ID_PHODEISLAND)
{
    m_spPosArr = std::make_unique<CSpace[]>(DEFAULT_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(4, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(5, 0, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[2].Set(6, 0, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[3].Set(4, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[4].Set(5, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[5].Set(6, 1, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[6].Set(4, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[7].Set(5, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[8].Set(6, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
}

CPhodeisland::~CPhodeisland()
{

}

INT CPhodeisland::GetId() const 
{
    return m_eId ; 
}

void CPhodeisland::Draw() 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ; 
    paint.PaintBlock(m_spPosArr, 0, 128, 0) ; 
}

void CPhodeisland::FutureDraw() 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ; 
    paint.PaintBlock(m_spPosArr, 102, 255, 51) ; 
}





