#pragma once
#include <memory>
#include "Block.h" 
#include "TetrisGame.h"

class CCommand
{
    private :
        std::unique_ptr<CTetrisGame> m_spTetrisGm ; 
    public :
        CCommand() ; 
        ~CCommand() ; 
    public :
        void InputKey(int nKey, HDC hDC) ;
        void Draw(HDC hDC) ; 
    public :
        void Left(HDC hDC) ; 
        void Right(HDC hDC) ; 
        void Rotate(HDC hDC) ; 
        void Down(HDC hDC) ; 
} ;

