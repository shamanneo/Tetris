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
        void InputKey(INT nKey) ;
        void Draw() ; 
    public :
        void Left() ; 
        void Right() ; 
        void Rotate() ; 
        void Down() ; 
        void FastDown() ;
        void PaintBoard() ; 
} ;

