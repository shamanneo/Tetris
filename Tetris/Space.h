#pragma once 

class CSpace
{
    public :
        INT m_nX ; 
        INT m_nY ; 
        bool m_bPres ;  
        INT m_nPos ; 
    public :
        inline void Set(INT nX, INT nY, bool bPres, INT nPos) ; 
        inline bool IsEmpty() const ; 
} ;

inline void CSpace::Set(INT nX, INT nY, bool bPres, INT nPos)
{
    m_nX = nX ; 
    m_nY = nY ; 
    m_bPres = bPres ; 
    m_nPos = nPos ; 
}

inline bool CSpace::IsEmpty() const 
{
    return !m_bPres ; 
}



