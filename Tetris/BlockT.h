#pragma once
#include "Block.h"
#include <memory>

class CBlockT : public CBlock
{
    enum
    {
        ON = 0, 
        OFF = 1 
    } ; 
    public :   
        std::unique_ptr<CSpace[]> m_spPosArr ; 
        const INT m_nId ; 
    public :
        CBlockT() ;
        ~CBlockT() ; 
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

