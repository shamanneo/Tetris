#pragma once
#include "Block.h"
#include <memory>

class CPhodeisland : public CBlock
{
    enum
    {
        ON = 1, 
        OFF = 0,
        BLOCKSIZE = 9
    } ; 
    public :   
        std::unique_ptr<CSpace[]> m_spPosArr ; 
        const INT m_nId ; 
    public :
        CPhodeisland() ;
        ~CPhodeisland() ; 
    public :
        virtual bool GetPos(INT nIndex, INT &nX, INT &nY) const override ; 
        virtual INT GetId() const override ; 
    public :
        virtual void Draw(HDC hDC) override ; 
        virtual void Erase(HDC hDC) override ; 
        virtual void Left() override ;
        virtual void Right() override ; 
        virtual void Rotate() override ; 
        virtual void Down() override ; 
} ;