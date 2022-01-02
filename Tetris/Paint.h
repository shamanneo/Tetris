#pragma once
#include <memory>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
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
        void PaintBoard(INT arrTotalBoard[][21]) ; 
        void DrawBoard() ; 
        void EraseBoard() ; 
        void PrintMain() ; 
    public :
        void DrawScores(INT nScore) ; 
        void PrintNextBlock() ; 
} ;

