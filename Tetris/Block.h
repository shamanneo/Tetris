#pragma once
#include "Pos.h"

class CBlock
{
    public :
        virtual bool GetPos(INT nIndex, INT &nX, INT &nY) const ; 
        virtual INT GetId() const ; 
    public :
        virtual void Draw(HDC hDC) ; 
        virtual void Erase(HDC hDC) ; 
        virtual void Left() ; 
        virtual void Right() ; 
        virtual void Down() ;
} ;

