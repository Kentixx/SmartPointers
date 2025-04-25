#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QInputDialog>
#include <QMessageBox>
#include <QMenu>
#include <QContextMenuEvent>
#include <QCursor>
#include <QStringList>
#include <QList>

#include <memory>
#include "ui_mainwindow.h"
#include "source/BookModel.h"
#include "source/BookDialog.h"
#include "classes/Library.h"
#include "source/UserModel.h"
#include "InfoWindow.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBook_clicked();
    void on_deleteBook_clicked();
    void on_createUser_clicked();
    void on_deleteUser_clicked();
    void on_findBookByTitle_clicked();
    void on_findBookByAuthor_clicked();
    void onBookDoubleClicked(const QModelIndex &index);
    void onUserDoubleClicked(const QModelIndex &index);
    void onUserRightClicked(const QPoint &pos);
    void on_issueBookToUser();
    void on_removeBookFromUser();
    void createContextMenu();
    void contextMenuEvent(QContextMenuEvent *event);

private:
    Ui_MainWindow *ui;
    Library appLibrary;
    QVector<std::shared_ptr<Book>> books;
    QVector<std::shared_ptr<User>> users;
    BookModel *bookModel;
    UserModel *userModel;
    QMenu *userContextMenu;
    InfoWindow *bookInfoWindow;
    InfoWindow *userInfoWindow;
};

#endif // MAINWINDOW_H
