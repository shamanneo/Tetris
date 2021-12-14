#pragma once
#include "Block.h" 

class CTetrisGame
{
    private :
        std::unique_ptr<CBlock> m_blockCurr ;
    public :
        CTetrisGame() ; 
        ~CTetrisGame() ; 
    public :
        void InputKey(int nKey, HDC hDC) ;
        void SetBlock() ; 
        void Draw(HDC hDC) ; 
        void Erase(HDC hDC) ; 
        void Down() ; 
} ;

