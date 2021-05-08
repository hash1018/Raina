
#include "Ui/MainWindow.h"
#include <QApplication>

#ifdef Q_OS_WIN

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#ifdef _DEBUG
#define DBG_NEW new ( _CLIENT_BLOCK , __FILE__ , __LINE__ )
#endif

#endif

#include "Base/RainaCore.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    RainaCore::getInstance()->initialize();

    MainWindow w;
    

#ifdef Q_OS_WIN
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
#endif
   
    w.show();
    a.exec();

    RainaCore::getInstance()->deinitialize();



    return 0;
            
}
