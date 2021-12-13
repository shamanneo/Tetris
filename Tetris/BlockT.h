#pragma once
#include "Pos.h"

class CBlockT
{
    private :   
        static const int m_nSize ; 
        CPos *m_posArray ; 
        bool m_bIsReached ; 
    public :
        CBlockT() ;
        ~CBlockT() ; 
    public :
        void Draw(HDC hDC) ; 
        void Erase(HDC hDC) ;
        void RightRotate() ; 
        void Down() ; 
        void Left() ; 
        void Right() ;
        bool IsReached() ; 
} ;

