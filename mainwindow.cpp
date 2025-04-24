#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->BookTable->setColumnCount(3);
    ui->BookTable->setHorizontalHeaderLabels
    (QStringList() << "Название" << "Автор" << "Год издания");

    connect(ui->addBook, SIGNAL(clicked()), this, SLOT(on_addBook_clicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addBook_clicked() {
    bool ok;

    QString bookTitle = QInputDialog::getText
    (this, tr("Добавить книгу"),
    tr("Название:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookTitle.isEmpty()) return;

    QString bookAuthor = QInputDialog::getText(this, tr("Автор книги"),
    tr("Автор:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookAuthor.isEmpty()) return;

    QString bookYear = QInputDialog::getText(this, tr("Год издания"),
    tr("Год издания:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookYear.isEmpty()) return;

    auto book = std::make_shared<Book>
    (bookTitle.toStdString(), bookAuthor.toStdString(), bookYear.toInt());
    books.append(book);
    appLibrary.addBook(book);

    int row = ui->BookTable->rowCount();
    ui->BookTable->insertRow(row);

    ui->BookTable->setItem(row, 0, new QTableWidgetItem(bookTitle));
    ui->BookTable->setItem(row, 1, new QTableWidgetItem(bookAuthor));
    ui->BookTable->setItem(row, 2, new QTableWidgetItem(bookYear));
}

/* void MainWindow::on_deleteBook_clicked() {
    int row = ui->BookList->currentRow();
    if (row >= 0) {
        books.remove(row);
        delete ui->BookList->takeItem(row);  // Удаляем из QListView
    }
}

void MainWindow::on_createUser_clicked() {
    bool ok;
    QString userName = QInputDialog::getText(this, tr("Создать пользователя"),
                                              tr("Имя пользователя:"), QLineEdit::Normal,
                                              "", &ok);
    if (ok && !userName.isEmpty()) {
        users.append(userName);
        ui->UserTable->addItem(userName);  // Предполагается, что UserTable - это QListView
    }
}

void MainWindow::on_deleteUser_clicked() {
    int row = ui->UserTable->currentRow();
    if (row >= 0) {
        users.remove(row);
        delete ui->UserTable->takeItem(row);  // Удаляем из QListView
    }
}
*/
void MainWindow::showBookInfo(const int& index) {
    if (index >= 0 && index < books.size()) {
        BookDialog dialog(books[index], this);
        dialog.exec();
    }
}
