#include "pch.h"
#include "Paint.h"

HWND *CPaint::m_phWnd = nullptr ; 

CPaint::CPaint()
{

}

CPaint::~CPaint() 
{

}

void CPaint::Assign(HWND hWnd) 
{
    m_phWnd = &hWnd ; 
}