#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CPhodeisland : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CPhodeisland(INT nArrSize, INT nUp) ;
        ~CPhodeisland() ; 
    public :
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw() override ; 
} ;