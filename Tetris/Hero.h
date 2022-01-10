#pragma once
#include <memory>
#include "Block.h"
#include "Constants.h"

class CHero : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CHero(INT nArrSize) ;
        ~CHero() ; 
    public :
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT]) override ; 
    public :    
        void ClockWise() ; 
        void CounterClockWise() ; 
} ;

