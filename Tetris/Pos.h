#pragma once

class CPos
{
    public :
        int m_nX ; 
        int m_nY ; 
    public :
        inline void Set(int nX, int nY) ; 
        inline bool IsEmpty() const ; 
        CPos &operator = (const CPos &other) ;
} ;

inline void CPos::Set(int nX, int nY)
{
    m_nX = nX ; 
    m_nY = nY ; 
}

inline bool CPos::IsEmpty() const 
{
    return ((m_nX == 0) && (m_nY == 0)) ;
}
