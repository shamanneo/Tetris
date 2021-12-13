#pragma once

#include "resource.h"

void DrawBoard(HDC hDC)
{
    Gdiplus::Graphics grap { hDC } ; 
    Gdiplus::Pen pen { Gdiplus::Color(0, 0, 0) } ; 

    grap.DrawRectangle(&pen, 30, 30, 300, 600) ; 
   
    for(int i = 0 ; i < 10 ; i++)
    {
        grap.DrawLine(&pen, 30 + 30 * i, 30, 30 + 30 * i, 630) ; 
    }
    for(int i = 0 ; i < 20 ; i++)
    {
        grap.DrawLine(&pen, 30, 30 + 30 * i, 330, 30 + 30 * i) ; 
    }
}