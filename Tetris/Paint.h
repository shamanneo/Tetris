#pragma once
#include <memory>
#include "MainApp.h"
#include "Block.h"
#include "Constants.h"

class CPaint
{   
    private :
        HWND m_hWnd ; 
        HDC m_hDC ;
        RECT m_rcClient ; 
        bool m_bAutoRelease ;
    public :
        CPaint(HWND hWnd) ;
        CPaint(HWND hWnd, HDC hDC) ;
        ~CPaint() ; 
    public :
        void PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void EraseBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void PaintBoard(INT arrTotalBoard[][BLOCK_HEIGHT_COUNT]) ; 
        void DrawBoard() ; 
        void EraseBoard() ; 
        void PrintMain() ; 
    public :
        void DrawInfo(INT nScore = 0, INT nLevel = 0, INT nLine = 0) ; 
        void PrintNextBlock() ; 
} ;

