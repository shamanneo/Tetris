#pragma once
#include "Block.h"
#include <memory>

class CHero : public CBlock
{
    enum
    {
        ARRAYSIZE = 16
    } ; 
    public :   
        const INT m_nId ; 
    public :
        CHero(INT nArrSize) ;
        ~CHero() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void FutureDraw() override ; 
        virtual void Rotate(INT m_arrBoard[][HEIGHT + 1]) override ; 
};

