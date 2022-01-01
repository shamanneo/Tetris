#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CLicky : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CLicky(INT nArrSize) ;
        ~CLicky() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void FutureDraw() override ; 
} ;

