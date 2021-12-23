#pragma once
#include "Block.h"
#include <memory>

class CPhodeisland : public CBlock
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
        CPhodeisland(INT nArrSize) ;
        ~CPhodeisland() ; 
    public :
        virtual INT GetId() const override ; 
    public :
        virtual void Draw() override ; 
        virtual void Rotate() override ; 
} ;