#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CSmashboy : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CSmashboy(INT nArrSize) ;
        ~CSmashboy() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT + 1]) ; 
        virtual void FutureDraw() override ; 
} ;

