#include <QApplication>
#include <QPushButton>
#include "classes/Library.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    Library lib;
    demonstrateLibraryFunctions(lib);
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return QApplication::exec();
}