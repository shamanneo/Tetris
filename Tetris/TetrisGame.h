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
        HERO = 34, 
        TEEWEE = 35, 
        SMASHBOY = 36
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
    public :
        void Draw(HDC hDC) ; 
        void Erase(HDC hDC) ; 
    public :
        void Left(HDC hDC) ; 
        void Right(HDC hDC) ; 
        void Rotate(HDC hDC) ; 
        bool Down(HDC hDC) ; 
    public :
        bool isMoveLeft() ; 
        bool isMoveRight() ; 
        bool CanRotate(HDC hDC) ; 
        bool isMoveDown() ; 
} ;

