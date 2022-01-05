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
    public :
        virtual void Draw() ; 
        virtual void FutureDraw() ; 
        void Erase() ; 
        void Left() ; 
        void Right() ; 
        void Up() ; 
        void Down() ; 
        virtual void Rotate(INT arrBoard[][BLOCK_HEIGHT_COUNT + 1]) ; 
        bool CanRotate(INT arrBoard[][BLOCK_HEIGHT_COUNT + 1], INT nArrSize = DEFAULT_ARRAY_SIZE) ;
    public :
        void GetTempArray(bool *bArr, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void ClockWise() ; 
        void CounterClockWise() ; 

} ;

