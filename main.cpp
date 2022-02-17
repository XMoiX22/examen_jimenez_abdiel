#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //le damos un estilo a la ventana principal
    MainWindow w;
    w.show();

    return a.exec();
}
