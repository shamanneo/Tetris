#pragma once
#include "Block.h"

class CBlockT : public CBlock
{
    public :   
        CPos *m_posArray ; 
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
        virtual void Down() override ; 
} ;

