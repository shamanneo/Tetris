#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Hero.h" 

CHero::CHero(INT nArrSize)
    : CBlock(nArrSize), m_eId(BlockId::ID_HERO)
{
    m_spPosArr = std::make_unique<CSpace[]>(HERO_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(5, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(6, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[2].Set(7, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[3].Set(8, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[4].Set(5, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[5].Set(6, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[6].Set(7, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[7].Set(8, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[8].Set(5, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[9].Set(6, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[10].Set(7,2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[11].Set(8, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[12].Set(5, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[13].Set(6, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[14].Set(7, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[15].Set(8, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
}

CHero::~CHero()
{

}

BlockId CHero::GetId() const 
{
    return m_eId ; 
}

void CHero::Draw(INT nGhost) 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.PaintBlock(m_spPosArr, 0, 163, 210, nGhost, HERO_ARRAY_SIZE) ; 
}

void CHero::Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT], INT /*nDirect*/) 
{
    ClockWise() ; 
    if(!CanRotate(arrBoard, HERO_ARRAY_SIZE))
    {
        CounterClockWise() ; 
    }
}

void CHero::ClockWise() 
{
    bool bArr[HERO_ARRAY_SIZE] { } ; 
    GetTempArray(bArr, HERO_ARRAY_SIZE) ;
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
}

void CHero::CounterClockWise() 
{
    bool bArr[HERO_ARRAY_SIZE] { } ; 
    GetTempArray(bArr, HERO_ARRAY_SIZE) ;
    m_spPosArr[12].m_bPres = bArr[0] ; 
    m_spPosArr[8].m_bPres = bArr[1] ; 
    m_spPosArr[4].m_bPres = bArr[2] ; 
    m_spPosArr[0].m_bPres = bArr[3] ; 
    m_spPosArr[13].m_bPres = bArr[4] ; 
    m_spPosArr[9].m_bPres = bArr[5] ; 
    m_spPosArr[5].m_bPres = bArr[6] ; 
    m_spPosArr[1].m_bPres = bArr[7] ; 
    m_spPosArr[14].m_bPres = bArr[8] ; 
    m_spPosArr[10].m_bPres = bArr[9] ; 
    m_spPosArr[6].m_bPres = bArr[10] ; 
    m_spPosArr[2].m_bPres = bArr[11] ; 
    m_spPosArr[15].m_bPres = bArr[12] ; 
    m_spPosArr[11].m_bPres = bArr[13] ; 
    m_spPosArr[7].m_bPres = bArr[14] ; 
    m_spPosArr[3].m_bPres = bArr[15] ; 
}






