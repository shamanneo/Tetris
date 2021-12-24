#pragma once
#include "Space.h"
#include <memory>

class CBlock
{
    public :
    enum
    { 
        ON = 1, 
        OFF = 0,

        DEFAULT_ARRAY_SIZE = 9,

        LEFTPOS = 9,
        MIDPOS = 10,  
        RIGHTPOS = 11,

        HEIGHT = 20,

        LICKY = 30,
        RICKY = 31, 
        CLEVELAND = 32, 
        PHODEISLAND = 33,
        TEEWEE = 34, 
        SMASHBOY = 35,
        HERO = 36
    } ; 
    private :
        INT m_nArrSize ; 
    public :
        std::unique_ptr<CSpace[]> m_spPosArr ; 
    public :
        CBlock(INT nArrSize) ; 
        virtual ~CBlock() ; 
    public :
        bool GetPos(INT nIndex, INT &nX, INT &nY) const ; 
        virtual INT GetId() const ; 
        bool IsOutOfBoundary(INT nIndex) const ; 
    public :
        virtual void Draw() ; 
        void Erase() ; 
        void Left() ; 
        void Right() ; 
        virtual void Rotate(INT m_arrBoard[][HEIGHT + 1]) ; 
        void Up() ; 
        void Down() ;
} ;

