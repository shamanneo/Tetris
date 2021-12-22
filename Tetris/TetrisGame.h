#pragma once
#include <memory>
#include <string.h>
#include "Block.h"

class CTetrisGame 
{
    enum
    {
        WIDTH = 10,
        HEIGHT = 20,

        OFF = 0, 
        BOUND = 1,
        CURRENT = 2,

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
        std::unique_ptr<CBlock> m_spCurBk ; 
    public :
        CTetrisGame() ;
        ~CTetrisGame() ; 
    public :
        void Create() ; 
        void Reach() ; 
        bool IsFull(INT nLine) ; 
        void Update(INT nLine) ; 

    public :
        void Draw() ; 
    public :
        void Left() ; 
        void Right() ; 
        void Rotate() ; 
        bool Down() ; 
    public :
        bool isMoveLeft() ; 
        bool isMoveRight() ; 
        bool CanRotate() ; 
        bool isMoveDown() ; 
} ;

