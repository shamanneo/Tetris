#pragma once
#include <memory>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
#include "Block.h"
#include "Constants.h"

class CPaint
{   
    enum
    {
        WIDTH = 10,
        HEIGHT = 20,
        
        DEFAULT_ARRAY_SIZE = 9,
        HERO_ARRAY_SIZE = 16,

        INTERVAL = 30,
         
        LICKY = 30,
        RICKY = 31, 
        CLEVELAND = 32, 
        PHODEISLAND = 33,
        TEEWEE = 34, 
        SMASHBOY = 35,
        HERO = 36
    } ; 
    private :
        HWND m_hWnd ; 
        HDC m_hDC ;
        static INT m_nScore ; 
        static INT m_nId ; 
        BlockId m_eId ;
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
        void PrintCastle() ; 
    public :
        void DrawScores(INT nScore) ; 
        void PrintNextBlock(INT nId = 0) ; 
} ;

