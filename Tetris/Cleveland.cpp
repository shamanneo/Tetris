#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Constants.h"
#include "Cleveland.h"

CCleveland::CCleveland(INT nArrSize)
    : CBlock(nArrSize), m_eId(BlockId::ID_CLEVELAND)
{
    m_spPosArr = std::make_unique<CSpace[]>(DEFAULT_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(5, 0, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(6, 0, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[2].Set(7, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[3].Set(5, 1, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[4].Set(6, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[5].Set(7, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[6].Set(5, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[7].Set(6, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[8].Set(7, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
}

CCleveland::~CCleveland()
{

}
BlockId CCleveland::GetId() const 
{
    return m_eId ; 
}

void CCleveland::Draw(INT nGhost) 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd().m_hWnd } ; 
    paint.PaintBlock(m_spPosArr, 255, 0, 0, nGhost) ; 
}








