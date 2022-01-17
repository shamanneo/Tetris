#include "pch.h" 
#include <iostream>
#include <crtdbg.h>
#include "SQLlite/sqlite3.h" 
#include "MainApp.h"
#include "Tetris.h"

using namespace Gdiplus ; 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    /*lpCmdLine*/,
                     _In_ int       nCmdShow)
{
    sqlite3 *db ; 
    sqlite3_stmt *pStmt ;
    const char *sql ; 
    const char *data = "CallBack funtion called" ; 
    char *zErrMsg = nullptr ; 
    int rc ; 

    rc = sqlite3_open("Tetris.db", &db) ; 
    if(rc)
    {
        fprintf(stderr, "Can't open database : %s\n", sqlite3_errmsg(db)) ; 
        return 0 ; 
    }
    else 
    {
        fprintf(stderr, "Opened database successfully\n") ; 
    }

    sql =   "CREATE TABLE TETRIS_SCORE(ID KEY, NAME TEXT, SCORE INT)" ; 
    //rc = sqlite3_exec(db, sql, CallBack, 0, &zErrMsg) ; 
    
    sql =   "INSERT INTO TETRIS_SCORE(ID, NAME, SCORE)"
            " VALUES (1, 'SHA', 200000) ; "  
            "INSERT INTO TETRIS_SCORE(ID, NAME, SCORE)"
            " VALUES (2, 'FRE', 100) ; " 
            "INSERT INTO TETRIS_SCORE(ID, NAME, SCORE)" 
            " VALUES (3, 'CHU', 50) ; " ; 

    //rc = sqlite3_exec(db, sql, CallBack, 0, &zErrMsg) ; 
    sql = "SELECT * from TETRIS_SCORE" ;

       /* Execute SQL statement */
    const unsigned char *s ;
    rc = sqlite3_prepare_v2(db, sql, -1, &pStmt, NULL) ; 
    while (true)
    {
        rc = sqlite3_step(pStmt) ;  
        if(rc == SQLITE_DONE)
        {
            break ; 
        }
        s = sqlite3_column_text(pStmt, 1) ; 
    }
   
    sqlite3_finalize(pStmt) ; 
    sqlite3_close(db) ; 

    GdiplusStartupInput gdiplusStartupInput ; 
    ULONG_PTR gdiplusToken ; 
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL) ; 

    CMainApp &MainApp = CMainApp::GetInstance() ; 
    int nResult = MainApp.Run(hInstance, nCmdShow) ; 
   
    CMainApp::Release() ;
    GdiplusShutdown(gdiplusToken) ; 

    _CrtDumpMemoryLeaks() ; 
    return nResult ; 
}
