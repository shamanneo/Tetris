#pragma once
#include "Block.h"
#include <memory>

class CTeewee : public CBlock
{
    enum
    {
        ARRAYSIZE = 9
    } ; 
    public :   
        const INT m_nId ; 
    public :
        CTeewee(INT nArrSize) ;
        ~CTeewee() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate(INT m_arrBoard[][HEIGHT + 1]) override ; 
        
        
} ;

