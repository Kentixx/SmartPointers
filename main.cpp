#include <QApplication>
#include <QPushButton>
#include "source/Library.h"

int main(int argc, char *argv[]) {
    Library lib;
    demonstrateLibraryFunctions(lib);
    /*QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();*/
}