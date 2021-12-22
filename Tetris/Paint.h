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
    public :
        CPaint() ;
        ~CPaint() ; 
    public :
        void PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB) ; 
        void EraseBlock(std::unique_ptr<CSpace[]> &spPosArr) ; 
        void PaintBoard(INT arrTotalBoard[][21]) ; 
        void EraseBoard() ; 
    public :
        static void Assign(HWND hWnd) ; 
} ;

