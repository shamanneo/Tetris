#pragma once
#include "Block.h"
#include <memory>

class CSmashboy : public CBlock
{
    enum
    {
        ARRAYSIZE = 9
    } ; 
    public :   
        const INT m_nId ; 
    public :
        CSmashboy(INT nArrSize) ;
        ~CSmashboy() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate(INT m_arrBoard[][HEIGHT + 1]) ; 
        virtual void FutureDraw() override ; 
} ;

