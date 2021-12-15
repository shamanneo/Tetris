#pragma once 

class CSpace
{
    public :
        INT m_nX ; 
        INT m_nY ; 
        bool m_bPres ;  
    public :
        inline void Set(INT nX, INT nY, bool bPres) ; 
        inline bool IsEmpty() const ; 
        inline void SetOnOff(bool bpres) ; 
} ;

inline void CSpace::Set(INT nX, INT nY, bool bPres)
{
    m_nX = nX ; 
    m_nY = nY ; 
    m_bPres = bPres ; 
}

inline bool CSpace::IsEmpty() const 
{
    return !m_bPres ; 
}

inline void CSpace::SetOnOff(bool bpres)
{
    m_bPres = bpres ; 
}

