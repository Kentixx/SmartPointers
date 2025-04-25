/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *LibraryLabel;
    QLabel *UserLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *findBookByTitle;
    QPushButton *deleteBook;
    QPushButton *addBook;
    QPushButton *deleteUser;
    QPushButton *createUser;
    QPushButton *findBookByAuthor;
    QTableView *BookTable;
    QTableView *UserTable;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 600);
        LibraryLabel = new QLabel(MainWindow);
        LibraryLabel->setObjectName("LibraryLabel");
        LibraryLabel->setGeometry(QRect(20, 20, 321, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        LibraryLabel->setFont(font);
        LibraryLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        UserLabel = new QLabel(MainWindow);
        UserLabel->setObjectName("UserLabel");
        UserLabel->setGeometry(QRect(350, 20, 331, 41));
        UserLabel->setFont(font);
        UserLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayoutWidget = new QWidget(MainWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(140, 410, 411, 131));
        QFont font1;
        font1.setPointSize(11);
        gridLayoutWidget->setFont(font1);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        findBookByTitle = new QPushButton(gridLayoutWidget);
        findBookByTitle->setObjectName("findBookByTitle");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter 24pt")});
        font2.setPointSize(11);
        findBookByTitle->setFont(font2);

        gridLayout->addWidget(findBookByTitle, 2, 0, 1, 1);

        deleteBook = new QPushButton(gridLayoutWidget);
        deleteBook->setObjectName("deleteBook");
        deleteBook->setFont(font2);

        gridLayout->addWidget(deleteBook, 1, 0, 1, 1);

        addBook = new QPushButton(gridLayoutWidget);
        addBook->setObjectName("addBook");
        addBook->setFont(font2);

        gridLayout->addWidget(addBook, 0, 0, 1, 1);

        deleteUser = new QPushButton(gridLayoutWidget);
        deleteUser->setObjectName("deleteUser");
        deleteUser->setFont(font2);

        gridLayout->addWidget(deleteUser, 1, 1, 1, 1);

        createUser = new QPushButton(gridLayoutWidget);
        createUser->setObjectName("createUser");
        createUser->setFont(font2);

        gridLayout->addWidget(createUser, 0, 1, 1, 1);

        findBookByAuthor = new QPushButton(gridLayoutWidget);
        findBookByAuthor->setObjectName("findBookByAuthor");
        findBookByAuthor->setFont(font2);

        gridLayout->addWidget(findBookByAuthor, 3, 0, 1, 1);

        BookTable = new QTableView(MainWindow);
        BookTable->setObjectName("BookTable");
        BookTable->setGeometry(QRect(20, 70, 321, 321));
        UserTable = new QTableView(MainWindow);
        UserTable->setObjectName("UserTable");
        UserTable->setGeometry(QRect(350, 70, 331, 321));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "mainwindow", nullptr));
        LibraryLabel->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", nullptr));
        UserLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        findBookByTitle->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\272\320\275\320\270\320\263\321\203 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));
        deleteBook->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        addBook->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        deleteUser->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        createUser->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        findBookByAuthor->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\272\320\275\320\270\320\263\321\203 \320\277\320\276 \320\260\320\262\321\202\320\276\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
