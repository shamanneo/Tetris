#pragma once
#include "Pos.h"
#include <memory>

class CBlock
{
    public :
        virtual void Draw(HDC hDC) ; 
        virtual void Erase(HDC hDC) ; 
        virtual void Left() ; 
        virtual void Right() ; 
        virtual void Down() ;
} ;

