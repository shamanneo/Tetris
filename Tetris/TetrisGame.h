#pragma once
#include <memory>
#include "Constants.h"
#include "Block.h"

class CTetrisGame 
{
    private :
        INT m_arrBoard[BLOCK_WIDTH_COUNT][BLOCK_HEIGHT_COUNT] ; 
        INT m_nArrSize ;
        INT m_nScore ; 
        INT m_nVelocity ;
        INT m_nWaitTime ;
        bool m_CanSetTimer ; 
        BlockId m_eNextId ; 
        std::unique_ptr<CBlock> m_spCurBk ; 
        std::unique_ptr<CBlock> m_spFurBk ; 
    public :
        CTetrisGame() ;
        ~CTetrisGame() ; 
    public :
        void Create() ;
        void Stay() ; 
        void Reach() ; 
        bool IsFull(INT nLine) ; 
        void InUpdate(INT nLine) ; 
        void OutUpdate() ; 
        void SetLevel() ; 
        bool IsGameOver() ; 
        void GameOver() ; 
    public :
        void Draw() ; 
        void Erase() ; 
        void DrawGhost() ;
    public :
        void Left() ; 
        void Right() ; 
        void Rotate(INT nDirect) ; 
        void Down() ; 
        bool SlowDown() ; 
        void FastDown() ; 
    public :
        bool IsMoveLeft() ; 
        bool IsMoveRight() ; 
        bool IsMoveDown(CBlock *pBk) ; 
} ;

