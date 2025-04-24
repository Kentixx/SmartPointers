#include "BookDialog.h"

BookDialog::BookDialog(std::shared_ptr<Book> book, QWidget *parent) {
    setWindowTitle("Информация о книге");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Название: " + QString::fromStdString(book->getTitle()), this);
    QLabel *authorLabel = new QLabel("Автор: " + QString::fromStdString(book->getAuthor()), this);
    QLabel *yearLabel = new QLabel("Год издания: " + book->getYear(), this);
    layout->addWidget(titleLabel);
    layout->addWidget(authorLabel);
    layout->addWidget(yearLabel);
    setLayout(layout);
}