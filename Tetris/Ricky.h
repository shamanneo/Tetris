#pragma once
#include "Block.h"
#include "Constants.h"
#include <memory>

class CRicky : public CBlock
{
    public :   
        const BlockId m_eId ; 
    public :
        CRicky(INT nArrSize, INT nUp) ;
        ~CRicky() ; 
    public :
        virtual BlockId GetId() const override ; 
    public :
        virtual void Draw() override ; 
} ;



