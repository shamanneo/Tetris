#pragma once
#include "Block.h"
#include <memory>

class CLicky : public CBlock
{
    enum
    {
        ARRAYSIZE = 9
    } ; 
    public :   
        const INT m_nId ; 
    public :
        CLicky(INT nArrSize) ;
        ~CLicky() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
} ;

