#pragma once
#include <memory>
#include "Constants.h"
#include "Block.h"

class CTetrisGame 
{
    private :
        INT m_arrBoard[BLOCK_WIDTH_COUNT + 2][BLOCK_HEIGHT_COUNT + 1] ; 
        INT m_nArrSize ;
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

