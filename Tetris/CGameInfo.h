#pragma once

class CGameInfo
{
    private :
        INT m_nScore ; 
        INT m_nLevel ; 
        INT m_nLine ; 
    public :
        CGameInfo() ; 
        ~CGameInfo() ; 
    public :
        const INT GetScore() const ; 
        const INT GetLevel() const ; 
        const INT GetLine() const ; 
    public :
        void StackScore(INT nScore)  ; 
        void StackLevel(INT nLevel)  ; 
        void StackLine(INT nLine)  ; 
    public :
        void Reset() ;
        void Draw(HWND hWnd) ; 

} ; 

const inline INT CGameInfo::GetScore() const 
{
    return m_nScore ; 
}

const inline INT CGameInfo::GetLevel() const 
{
    return m_nLevel ; 
}

const inline INT CGameInfo::GetLine() const 
{
    return m_nLine ; 
}

inline void CGameInfo::StackScore(INT nScore) 
{
    m_nScore += nScore ; 
}

inline void CGameInfo::StackLevel(INT nLevel) 
{
    m_nLevel += nLevel ; 
}

inline void CGameInfo::StackLine(INT nLine) 
{
    m_nLine += nLine ; 
}