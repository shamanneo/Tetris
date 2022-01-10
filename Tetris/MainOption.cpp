#include "pch.h"
#include "MainOption.h"

CMainOption::CMainOption()
{
    m_bGhostCheck = true ; 
} 

CMainOption::~CMainOption()
{

}

bool CMainOption::IsCheckedGhost() const
{
    return m_bGhostCheck ; 
}

void CMainOption::SetCheckGhost(bool bChecked)
{
    m_bGhostCheck = bChecked ; 
}