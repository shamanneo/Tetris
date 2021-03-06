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
        INT m_nInitX ; 
    public :
        CPaint(HWND hWnd) ;
        CPaint(HWND hWnd, HDC hDC) ;
        ~CPaint() ; 
    public :
        Gdiplus::Image *LoadPNG(HMODULE hModule, LPCWSTR lp) ;
    public :
        void PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB, INT nGhost, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void PaintBoard(INT arrTotalBoard[][BLOCK_HEIGHT_COUNT]) ; 
        void DrawBoard() ; 
        void EraseBoard() ; 
        void PrintMain() ; 
        void PrintGameOver() ; 
        void EraseAnimation(INT arrTotalBoard[][BLOCK_HEIGHT_COUNT], INT nLine) ; 
        void FillRect(Gdiplus::Brush &brush, INT nX, INT nY) ; // call Gdiplus::FillRectangle f
    public :
        void DrawInfo(INT nScore = 0, INT nLevel = 0, INT nLine = 0) ; 
        void DrawLeaderBoard() ; 
        void DrawBlackRect(INT nY, INT nWidth, INT nHeight) ; 
        void DrawRectString(CString &str, INT nX, INT nY, INT nWidth, INT nHeight) ; 
        void PrintNextBlock() ; 
} ;

