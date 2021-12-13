#include "pch.h"
#include "Pos.h"

CPos &CPos::operator = (const CPos &other)
{
    this->m_nX = other.m_nX ; 
    this->m_nY = other.m_nY ; 
    return *this ; 
}