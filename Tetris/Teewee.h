#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CTeewee : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CTeewee(INT nArrSize) ;
        ~CTeewee() ; 
    public :
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void FutureDraw() override ; 
} ;

