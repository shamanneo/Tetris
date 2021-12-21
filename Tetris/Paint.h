#pragma once

class CPaint
{   
    private :
        static HWND *m_phWnd ; 
    public :
        CPaint() ;
        ~CPaint() ; 
    public :
        static void Assign(HWND hWnd) ; 
} ;

