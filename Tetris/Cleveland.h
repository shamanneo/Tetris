#pragma once
#include "Block.h"
#include <memory>

class CCleveland : public CBlock
{
    enum
    {
        ARRAYSIZE = 9
    } ; 
    public :   
        const INT m_nId ; 
    public :
        CCleveland(INT nArrSize) ;
        ~CCleveland() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate(INT m_arrBoard[][HEIGHT + 1]) override ; 
        
} ;

