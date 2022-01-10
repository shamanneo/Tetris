#pragma once

class CMainOption
{
    private :   
        bool m_bGhostCheck ; 
    public :
        CMainOption() ; 
        ~CMainOption() ; 
    public :    
        bool IsCheckedGhost() const ; 
    public :
        void SetCheckGhost(bool bChecked) ; 
} ;

