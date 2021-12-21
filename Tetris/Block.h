#pragma once
#include "Space.h"

class CBlock
{
    public :
        virtual bool GetPos(INT nIndex, INT &nX, INT &nY) const ; 
        virtual INT GetId() const ; 
    public :
        virtual void Draw() ; 
        virtual void Erase() ; 
        virtual void Left() ; 
        virtual void Right() ; 
        virtual void Rotate() ; 
        virtual void Down() ;
} ;

