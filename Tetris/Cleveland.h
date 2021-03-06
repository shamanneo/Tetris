#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CCleveland : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CCleveland(INT nArrSize) ;
        ~CCleveland() ; 
    public :
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw(INT nGhost) override ; 
} ;

