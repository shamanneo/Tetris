#include "pch.h"
#include "MainApp.h"
#include "Paint.h"
#include "Block.h"

CBlock::CBlock(INT nArrSize)
{
    m_nArrSize = nArrSize ; 
    m_spPosArr = std::make_unique<CSpace[]>(m_nArrSize) ; 
}

CBlock::~CBlock()
 {

}

CBlock &CBlock::operator = (const CBlock &rOth)
{
    this->m_nArrSize = rOth.m_nArrSize ; 
    
    CSpace *pTemp = rOth.m_spPosArr.get() ; 
    CSpace *pDes = this->m_spPosArr.get() ;

    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        pDes[nIndex] = pTemp[nIndex] ; 
    }
    return *this ; 
}

bool CBlock::GetPos(INT nIndex, INT &nX, INT &nY) const 
{
    nX = m_spPosArr[nIndex].m_nX ;
    nY = m_spPosArr[nIndex].m_nY ;
    if(!m_spPosArr[nIndex].m_bPres)
    {
        return false ; 
    }
    return true ; 
}

BlockId CBlock::GetId() const 
{
    return BlockId::ID_VOID ; 
}

bool CBlock::IsOutOfBoundary(INT nIndex) const 
{
    return (m_spPosArr[nIndex].m_nX == 0) || (m_spPosArr[nIndex].m_nX == 11) || (m_spPosArr[nIndex].m_nY == 20) ? true : false ; 
}

void CBlock::Draw() 
{
    return ; 
}

void CBlock::FutureDraw()
{
    return ;
}

void CBlock::Erase()
{
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.EraseBlock(m_spPosArr, m_nArrSize) ; 
}

void CBlock::Left() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX-- ;         
    }
}

void CBlock::Right() 
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nX++ ;         
    }
}

void CBlock::Rotate(INT /*arrBoard*/[][BLOCK_HEIGHT_COUNT + 1])
{
    Erase() ; 
    bool bArr[DEFAULT_ARRAY_SIZE] { } ; 
    for(INT nIndex = 0 ; nIndex < DEFAULT_ARRAY_SIZE ; nIndex++)
    {
        if(m_spPosArr[nIndex].m_bPres == true)
        {
            bArr[nIndex] = m_spPosArr[nIndex].m_bPres ; 
        }
        m_spPosArr[nIndex].m_bPres = BLOCK_ARRAY_SPACE_OFF ; 
    }

    m_spPosArr[0].m_bPres = bArr[6] ; 
    m_spPosArr[1].m_bPres = bArr[3] ; 
    m_spPosArr[2].m_bPres = bArr[0] ; 
    m_spPosArr[3].m_bPres = bArr[7] ; 
    m_spPosArr[4].m_bPres = bArr[4] ; 
    m_spPosArr[5].m_bPres = bArr[1] ; 
    m_spPosArr[6].m_bPres = bArr[8] ; 
    m_spPosArr[7].m_bPres = bArr[5] ; 
    m_spPosArr[8].m_bPres = bArr[2] ; 

    for(INT nIndex = 0 ; nIndex < DEFAULT_ARRAY_SIZE ; nIndex++)
    {
        if((m_spPosArr[nIndex].m_bPres == true) && IsOutOfBoundary(nIndex))
        {
            if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_LEFT_POS)
            {
                Right() ; 
            }
            else if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_RIGHT_POS)
            {
                Left() ;
            }
            else if(m_spPosArr[nIndex].m_nPos == BLOCK_ARRAY_MID_POS)
            {
                Up() ; 
            }
        }
    }
}

void CBlock::Up() // Only for rotating when the block is out of boundary.
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY-- ; 
    }
}

void CBlock::Down()
{
    Erase() ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        m_spPosArr[nIndex].m_nY++ ; 
    }
}
    