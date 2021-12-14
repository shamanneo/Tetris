#pragma once
#include<string.h>

class CTetrisGame 
{
    enum
    {
        WIDTH = 10,
        HEIGHT = 20,

        ON = 0,
        OFF = 1, 
        CURRENT = 3
    } ; 
    private :
        INT m_arrBoard[HEIGHT][WIDTH] ; 
    public :
        CTetrisGame() ;
        ~CTetrisGame() ; 
    public :
        void Create() ; 
        void Draw(HDC hDC) ; 
        void Erase(HDC hDC) ; 
    public :
        void Left() ; 
        void Right() ; 
        void Down() ; 
    public :
        bool isMoveLeft() ; 
        bool isMoveRight() ; 
        bool isMoveDown() ; 
} ;

