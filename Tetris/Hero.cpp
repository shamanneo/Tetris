#include "pch.h"
#include <math.h>
#include "MainApp.h"
#include "Paint.h"
#include "Hero.h" 

CHero::CHero(INT nArrSize)
    : CBlock(nArrSize), m_eId(BlockId::ID_HERO)
{
    m_spPosArr = std::make_unique<CSpace[]>(HERO_ARRAY_SIZE) ; 
    m_spPosArr[0].Set(4, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[1].Set(5, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[2].Set(6, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[3].Set(7, 0, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[4].Set(4, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[5].Set(5, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[6].Set(6, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[7].Set(7, 1, BLOCK_ARRAY_SPACE_ON, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[8].Set(4, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[9].Set(5, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_LEFT_POS) ; 
    m_spPosArr[10].Set(6, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 
    m_spPosArr[11].Set(7, 2, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_RIGHT_POS) ; 

    m_spPosArr[12].Set(4, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[13].Set(5, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[14].Set(6, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
    m_spPosArr[15].Set(7, 3, BLOCK_ARRAY_SPACE_OFF, BLOCK_ARRAY_MID_POS) ; 
}

CHero::~CHero()
{

}

BlockId CHero::GetId() const 
{
    return m_eId ; 
}

void CHero::Draw() 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.PaintBlock(m_spPosArr, 0, 163, 210, HERO_ARRAY_SIZE) ; 
}

void CHero::FutureDraw() 
{   
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.PaintBlock(m_spPosArr, 153, 255, 255, HERO_ARRAY_SIZE) ; 
}

void CHero::Rotate(INT /*arrBoard*/[][BLOCK_HEIGHT_COUNT + 1]) 
{
    Erase() ; 
    bool bArr[HERO_ARRAY_SIZE] { } ; 
    for(INT i = 0 ; i < HERO_ARRAY_SIZE ; i++)
    {
        if(m_spPosArr[i].m_bPres == true)
        {
            bArr[i] = m_spPosArr[i].m_bPres ; 
        }
        m_spPosArr[i].m_bPres = BLOCK_ARRAY_SPACE_OFF ; 
    }

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

    for(INT nIndex = 0 ; nIndex < HERO_ARRAY_SIZE ; nIndex++)
    {
        if((m_spPosArr[nIndex].m_bPres == true) && IsOutOfBoundary(nIndex))
        {
            if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_LEFT_POS)
            {
                Right() ; 
                Right() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_RIGHT_POS)
            {
                Left() ; 
                Left() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_MID_POS)
            {
                Up() ; 
                Up() ; 
            }
        }
    }
}







