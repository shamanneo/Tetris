#include "pch.h"
#include "ThreadList.h"

CThreadList::CThreadList() 
{

}

CThreadList::~CThreadList() 
{

}

CAtlList<HANDLE> &CThreadList::GetThreadList()
{
    return m_Threads ; 
}

void CThreadList::Add(HANDLE hThread)
{
    m_Threads.AddTail(hThread) ; 
}

void CThreadList::RemoveAll() 
{
    HANDLE h ; 
    POSITION pos = m_Threads.GetHeadPosition() ; 
    while(pos != NULL)
    {
        h = m_Threads.GetNext(pos) ;
        CloseHandle(h) ; 
    }
    m_Threads.RemoveAll() ;
}

void CThreadList::WaitForAll() 
{
    HANDLE *pThreads = new HANDLE[m_Threads.GetCount()] ;
    INT nIndex = 0 ; 
    HANDLE h ; 
    POSITION pos = m_Threads.GetHeadPosition() ; 
    while(pos != NULL)
    {
        h = m_Threads.GetNext(pos) ;
        pThreads[nIndex] = h ; 
        nIndex++ ;
    }
    WaitForMultipleObjects(m_Threads.GetCount(), pThreads, TRUE, INFINITE) ; 
    delete[] pThreads ; 
}