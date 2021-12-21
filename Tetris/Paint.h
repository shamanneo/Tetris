#pragma once
#include <memory>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
#include "Block.h"

class CPaint
{   
    private :
        static HWND m_hWnd ; 
    public :
        CPaint() ;
        ~CPaint() ; 
    public :
        void PaintBlock(std::unique_ptr<CSpace[]> &spPosArr, INT nR, INT nG, INT nB) ; 
        void EraseBlock(std::unique_ptr<CSpace[]> &spPosArr) ; 
    public :
        static void Assign(HWND hWnd) ; 
} ;

