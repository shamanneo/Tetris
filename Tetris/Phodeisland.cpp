#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Phodeisland.h"

CPhodeisland::CPhodeisland(INT nArrSize, INT nUp)
    : CBlock(nArrSize), m_eId(BlockId::ID_PHODEISLAND)
{
    m_spPosArr = std::make_unique<CSpace[]>(DEFAULT_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(5, 2 - nUp, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(6, 2 - nUp, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[2].Set(7, 2 - nUp, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[3].Set(5, 3 - nUp, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[4].Set(6, 3 - nUp, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[5].Set(7, 3 - nUp, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[6].Set(5, 4 - nUp, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[7].Set(6, 4 - nUp, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[8].Set(7, 4 - nUp, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
}

CPhodeisland::~CPhodeisland()
{

}

BlockId CPhodeisland::GetId() const 
{
    return m_eId ; 
}

void CPhodeisland::Draw() 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ; 
    paint.PaintBlock(m_spPosArr, 0, 128, 0) ; 
}







