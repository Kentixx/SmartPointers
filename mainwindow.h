#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>
#include <QInputDialog>
#include <QMessageBox>

#include <memory>
#include "ui_mainwindow.h"
#include "source/BookModel.h"
#include "source/BookDialog.h"
#include "classes/Library.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBook_clicked();
    void showBookInfo(const int& index);
    /*void on_deleteBook_clicked();
    void on_createUser_clicked();
    void on_deleteUser_clicked();
    void on_findBookByTitle_clicked();
    void on_findBookByAuthor_clicked();
    void showUserInfo(const int& index);*/
private:
    Ui::MainWindow *ui;
    Library appLibrary;
    QVector<std::shared_ptr<Book>> books;
    QVector<std::shared_ptr<User>> users;
    BookModel *bookModel;
};

#endif // MAINWINDOW_H
