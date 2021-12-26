#pragma once
#include <memory>
#include "Block.h"

class CTetrisGame 
{
    enum
    {
        WIDTH = 10,
        HEIGHT = 20,

        OFF = 0, 
        BOUND = 1,

        DEFAULT_ARRAY_SIZE = 9,
        HERO_ARRAY_SIZE = 16,

        LICKY = 30,
        RICKY = 31, 
        CLEVELAND = 32, 
        PHODEISLAND = 33,
        TEEWEE = 34, 
        SMASHBOY = 35,
        HERO = 36
    } ; 
    private :
        INT m_arrBoard[WIDTH + 2][HEIGHT + 1] ; 
        INT m_nArrSize ; 
        std::unique_ptr<CBlock> m_spCurBk ; 
        std::unique_ptr<CBlock> m_spFurBk ; 
    public :
        CTetrisGame() ;
        ~CTetrisGame() ; 
    public :
        void Create() ; 
        void Reach() ; 
        bool IsFull(INT nLine) ; 
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

