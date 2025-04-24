#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>
#include <memory>
#include <QLabel>
#include <QVBoxLayout>
#include "Book.h"

class BookDialog : public QDialog {
    Q_OBJECT

public:
    explicit BookDialog(std::shared_ptr<Book> book, QWidget *parent = nullptr);
};

#endif // BOOKDIALOG_H
