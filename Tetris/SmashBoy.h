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
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw(INT nGhost = 255) override ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT]) override ;  
} ;

