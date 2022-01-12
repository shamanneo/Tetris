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
        virtual void Draw(INT nGhost) override ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT], INT nDirect) override ;  
} ;

