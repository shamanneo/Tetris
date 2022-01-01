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
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void FutureDraw() override ; 
} ;

