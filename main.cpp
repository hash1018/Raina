
#include "Ui/MainWindow.h"
#include <QApplication>

#ifdef Q_OS_WIN

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

/*
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__ )
*/

#ifdef _DEBUG
#define DBG_NEW new ( _CLIENT_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#endif

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(8360);
    int* temp = new int;

   
    

    w.show();
    return a.exec();
}
