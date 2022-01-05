#pragma once
#include <memory>
#include "Constants.h"
#include "Block.h"

class CTetrisGame 
{
    private :
        INT m_arrBoard[BLOCK_WIDTH_COUNT + 4][BLOCK_HEIGHT_COUNT + 1] ; 
        INT m_nArrSize ;
        INT m_nScore ; 
        INT m_nVelocity ;
        INT m_nWaitTime ;
        BlockId m_eNextId ; 
        std::unique_ptr<CBlock> m_spCurBk ; 
        std::unique_ptr<CBlock> m_spFurBk ; 
    public :
        CTetrisGame() ;
        ~CTetrisGame() ; 
    public :
        void Create() ; 
        void Reach() ; 
        bool IsFull(INT nLine) ; 
        bool IsGameOver() ; 
        void InUpdate(INT nLine) ; 
        void OutUpdate() ; 
        void FutureUpdate() ; 
        void SetLevel() ; 
    public :
        void Draw() ; 
    public :
        void Left() ; 
        void Right() ; 
        void Rotate() ; 
        bool Down() ; 
    public :
        bool IsMoveLeft() ; 
        bool IsMoveRight() ; 
        bool IsMoveDown(CBlock *pBk) ; 
} ;

