#pragma once
#include <memory>
#include "Space.h"
#include "Constants.h"

class CBlock
{
    private :
        INT m_nArrSize ; 
    public :
        std::unique_ptr<CSpace[]> m_spPosArr ; 
    public :
        CBlock(INT nArrSize) ; 
        virtual ~CBlock() ; 
        CBlock &operator = (const CBlock &rOth) ;
    public :
        bool GetPos(INT nIndex, INT &nX, INT &nY) const ; 
        virtual BlockId GetId() const ; 
        bool IsOutOfBoundary(INT nIndex) const ; 
        bool CanRotate(INT arrBoard[][BLOCK_HEIGHT_COUNT + 1]) ;
    public :
        virtual void Draw() ; 
        virtual void FutureDraw() ; 
        void Erase() ; 
        void Left() ; 
        void Right() ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT + 1]) ; 
        void SideRotate() ; 
        void Up() ; 
        void Down() ;
    public :
        void GetTempArray(bool *bArr) ; 
        void ClockWise() ; 
        void CounterClockWise() ; 

} ;

