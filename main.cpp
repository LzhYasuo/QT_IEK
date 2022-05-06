#include "Src/Gui/SmallWindow.h"
#include "Src/Gui/TypeWindow.h"
#include "Src/Gui/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
