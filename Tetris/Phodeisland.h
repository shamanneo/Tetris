#pragma once
#include "Block.h"
#include <memory>

class CPhodeisland : public CBlock
{
    enum
    {
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
        virtual void FutureDraw() override ; 
} ;