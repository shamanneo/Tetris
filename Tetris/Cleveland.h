#pragma once
#include "Block.h"
#include <memory>

class CCleveland : public CBlock
{
    enum
    {
        ON = 1, 
        OFF = 0,
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
        virtual void Rotate() override ; 
        
} ;

