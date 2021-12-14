#pragma once
#include "Block.h" 
#include "TetrisGame.h"

class CCommand
{
    private :
        std::unique_ptr<CTetrisGame> m_spTetrisGm ; 
    protected :
        void OnLeft(HDC hDC) ; 
        void OnRight(HDC hDC) ; 
        void OnUp(HDC hDC) ; 
        void OnDown(HDC hDC) ; 
    public :
        CCommand() ; 
        ~CCommand() ; 
    public :
        void InputKey(int nKey, HDC hDC) ;
        void Draw(HDC hDC) ; 
        void Erase(HDC hDC) ; 
        void Down() ; 
} ;

