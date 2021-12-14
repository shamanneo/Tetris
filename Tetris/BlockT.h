#pragma once
#include "Block.h"

class CBlockT : public CBlock
{
    private :   
        CPos *m_posArray ; 
        bool m_bIsReached ; 
    public :
        CBlockT() ;
        ~CBlockT() ; 
    public :
        virtual void Draw(HDC hDC) override ; 
        virtual void Erase(HDC hDC) override ; 
        virtual void Left() override ;
        virtual void Right() override ; 
        virtual void Down() override ; 
} ;

