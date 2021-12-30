#pragma once
#include <memory>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
#include "Block.h"

class CPaint
{   
    enum
    {
        WIDTH = 10,
        HEIGHT = 20,
        
        DEFAULT_ARRAY_SIZE = 9,
        HERO_ARRAY_SIZE = 16,
         
        LICKY = 30,
        RICKY = 31, 
        CLEVELAND = 32, 
        PHODEISLAND = 33,
        TEEWEE = 34, 
        SMASHBOY = 35,
        HERO = 36
    } ; 
    private :
        static HWND m_hWnd ; 
        static INT m_nScore ; 
    public :
        CPaint() ;
        ~CPaint() ; 
    public :
        void PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void EraseBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nArrSize = DEFAULT_ARRAY_SIZE) ; 
        void PaintBoard(INT arrTotalBoard[][21]) ; 
        void EraseBoard() ; 
        void PrintNextBlock(INT nId) ; 
    public :
        static void Assign(HWND hWnd) ; 
        static void DrawScores(INT nScore) ; 
} ;

