#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CPhodeisland : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CPhodeisland(INT nArrSize) ;
        ~CPhodeisland() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void FutureDraw() override ; 
} ;