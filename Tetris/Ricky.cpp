#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Ricky.h"

CRicky::CRicky(INT nArrSize)
    : CBlock(nArrSize), m_eId(BlockId::ID_RICKY)
{
    m_spPosArr = std::make_unique<CSpace[]>(DEFAULT_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(5, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(6, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[2].Set(7, 0, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[3].Set(5, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[4].Set(6, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[5].Set(7, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[6].Set(5, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[7].Set(6, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[8].Set(7, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
}

CRicky::~CRicky()
{

}

BlockId CRicky::GetId() const 
{
    return m_eId ; 
}

void CRicky::Draw(INT nGhost) 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.PaintBlock(m_spPosArr, 255, 127, 0, nGhost) ; 
}








