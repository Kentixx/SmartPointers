#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    bookModel = new BookModel(this);
    userModel = new UserModel(this);
    bookInfoWindow = nullptr;
    userInfoWindow = nullptr;

    ui->UserTable->setModel(userModel);
    ui->BookTable->setModel(bookModel);
    ui->BookTable->horizontalHeader()->setStretchLastSection(true);
    ui->UserTable->horizontalHeader()->setStretchLastSection(true);

    ui->UserTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->UserTable, &QTableView::customContextMenuRequested, this, &MainWindow::onUserRightClicked);
    connect(ui->addBook, &QPushButton::clicked, this, &MainWindow::on_addBook_clicked);
    connect(ui->deleteBook, &QPushButton::clicked, this, &MainWindow::on_deleteBook_clicked);
    connect(ui->createUser, &QPushButton::clicked, this, &MainWindow::on_createUser_clicked);
    connect(ui->deleteUser, &QPushButton::clicked, this, &MainWindow::on_deleteUser_clicked);
    connect(ui->findBookByTitle, &QPushButton::clicked, this, &MainWindow::on_findBookByTitle_clicked);
    connect(ui->findBookByAuthor, &QPushButton::clicked, this, &MainWindow::on_findBookByAuthor_clicked);
    connect(ui->BookTable, &QTableView::doubleClicked, this, &MainWindow::onBookDoubleClicked);
    connect(ui->UserTable, &QTableView::doubleClicked, this, &MainWindow::onUserDoubleClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addBook_clicked() {
    bool ok;

    QString bookTitle = QInputDialog::getText(this, tr("Добавить книгу"), tr("Название:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookTitle.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Название книги не может быть пустым."));
        return;
    }

    QString bookAuthor = QInputDialog::getText(this, tr("Автор книги"), tr("Автор:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookAuthor.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Автор не может быть пустым."));
        return;
    }

    QString bookYear = QInputDialog::getText(this, tr("Год издания"), tr("Год издания:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookYear.isEmpty() || !bookYear.toInt()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Год издания должен быть числом."));
        return;
    }

    auto book = std::make_shared<Book>(bookTitle.toStdString(), bookAuthor.toStdString(), bookYear.toInt());
    books.append(book);
    appLibrary.addBook(book);
    bookModel->setBooks(books);
}

void MainWindow::on_deleteBook_clicked() {
    QModelIndexList selectedRows = ui->BookTable->selectionModel()->selectedRows();
    for (const QModelIndex &index : selectedRows) {
        if (index.isValid()) {
            auto book = books[index.row()];
            for (auto &user : users) {
                auto it = std::remove_if(user->issuedBooks.begin(), user->issuedBooks.end(),
                                          [&book](const std::shared_ptr<Book>& issuedBook) {
                                              return issuedBook->getTitle() == book->getTitle();
                                          });
                user->issuedBooks.erase(it, user->issuedBooks.end());
            }

            appLibrary.removeBook(book);
            books.removeAt(index.row());
            bookModel->setBooks(books);
        }
    }
}

void MainWindow::on_createUser_clicked() {
    bool ok;
    QString userName = QInputDialog::getText(this, tr("Создать пользователя"), tr("Имя пользователя:"), QLineEdit::Normal, "", &ok);
    if (!ok || userName.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Имя пользователя не может быть пустым."));
        return;
    }

    auto user = std::make_shared<User>(userName.toStdString());
    users.append(user);
    userModel->setUsers(users);
}

void MainWindow::on_deleteUser_clicked() {
    QModelIndexList selectedRows = ui->UserTable->selectionModel()->selectedRows();
    for (const QModelIndex &index : selectedRows) {
        if (index.isValid()) {
            auto user = users[index.row()];
            appLibrary.deleteUser(user);
            users.removeAt(index.row());
            userModel->setUsers(users);
        }
    }
}

void MainWindow::on_findBookByTitle_clicked() {
    bool ok;
    QString entered_title = QInputDialog::getText(this, tr("Найти книгу по названию"),
        tr("Введите название книги:"), QLineEdit::Normal, "", &ok);
    if (!ok || entered_title.isEmpty()) return;

    ui->BookTable->clearSelection();
    for (int i = 0; i < books.size(); ++i) {
        auto book_title = QString::fromStdString(books[i]->getTitle());
        if (book_title == entered_title) {
            ui->BookTable->selectRow(i);
            break;
        }
    }
}

void MainWindow::on_findBookByAuthor_clicked() {
    bool ok;
    QString entered_author = QInputDialog::getText(this, tr("Найти книги по автору"),
        tr("Введите автора:"), QLineEdit::Normal, "", &ok);
    if (!ok || entered_author.isEmpty()) return;

    ui->BookTable->clearSelection();

    QList<QModelIndex> foundIndexes;
    for (int i = 0; i < books.size(); ++i) {
        if (QString::fromStdString(books[i]->getAuthor()) == entered_author) {
            QModelIndex index = ui->BookTable->model()->index(i, 0);
            foundIndexes.append(index);
        }
    }

    for (const auto& index : foundIndexes) {
        ui->BookTable->selectRow(index.row());
    }
    if (foundIndexes.isEmpty()) {
        QMessageBox::information(this, tr("Результат поиска по автору"),
            tr("Книги от данного автора в библиотеке не найдены."));
    }
}

void MainWindow::onBookDoubleClicked(const QModelIndex& index) {
    if (index.isValid()) {
        const auto &book = books[index.row()];

        if (!bookInfoWindow) {
            bookInfoWindow = new InfoWindow(this);
        }

        QString details = tr("Автор: %1\nГод: %2")
            .arg(book->getAuthor()).arg(QString::number(book->getYear()));
        bookInfoWindow->setInfo(QString::fromStdString(book->getTitle()), details);
        bookInfoWindow->show();
    }
}

void MainWindow::onUserDoubleClicked(const QModelIndex& index) {
    if (index.isValid()) {
        const auto &user = users[index.row()];

        if (!userInfoWindow) {
            userInfoWindow = new InfoWindow(this);
        }

        QString details = tr("ID: %1\nИмя: %2").arg(QString::number(user->getID())).arg(user->getName());
        if (!user->issuedBooks.empty()) {
            details += tr("\nВзятые книги: \n");
            for (const auto &book : user->issuedBooks) {
                details += tr("• %1, %2, %3\n")
                    .arg(QString::fromStdString(book->getTitle()))
                    .arg(QString::fromStdString(book->getAuthor()))
                    .arg(QString::number(book->getYear()));
            }
        } else {
            details += tr("\nНет взятых книг.");
        }

        userInfoWindow->setInfo(QString::fromStdString(user->getName()), details);
        userInfoWindow->show();
    }
}

void MainWindow::on_issueBookToUser() {
    QModelIndex index = ui->UserTable->currentIndex();
    if (!index.isValid()) return;

    auto user = users[index.row()];

    bool ok;
    QString bookTitle = QInputDialog::getText(this, tr("Добавить книгу"),
                                               tr("Название книги:"), QLineEdit::Normal, "", &ok);
    if (!ok || bookTitle.isEmpty()) return;

    auto bookIt = std::find_if(books.begin(), books.end(), [&bookTitle](const std::shared_ptr<Book>& book) {
        return QString::fromStdString(book->getTitle()) == bookTitle;
    });

    if (bookIt != books.end()) {
        user->issuedBooks.append(*bookIt);
        appLibrary.issueBook(bookTitle.toStdString(), user->getID());
        QMessageBox::information(this, tr("Успех"), tr("Книга добавлена."));
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Книга не найдена."));
    }
}

void MainWindow::on_removeBookFromUser() {
    QModelIndex index = ui->UserTable->currentIndex();
    if (!index.isValid()) return;

    auto user = users[index.row()];

    QStringList bookTitles;
    for (const auto &book : user->issuedBooks) {
        bookTitles << QString::fromStdString(book->getTitle());
    }

    if (bookTitles.isEmpty()) {
        QMessageBox::information(this, tr("Нет книг"), tr("У пользователя нет взятых книг."));
        return;
    }

    bool ok;
    QString selectedBookTitle = QInputDialog::getItem(this, tr("Удалить книгу"),
                                                       tr("Выберите книгу для удаления:"),
                                                       bookTitles, 0, false, &ok);
    if (!ok || selectedBookTitle.isEmpty()) return;

    auto bookIt = std::find_if(user->issuedBooks.begin(), user->issuedBooks.end(),
                                [&selectedBookTitle](const std::shared_ptr<Book>& book) {
                                    return QString::fromStdString(book->getTitle()) == selectedBookTitle;
                                });

    if (bookIt != user->issuedBooks.end()) {
        user->removeBook(*bookIt);
        QMessageBox::information(this, tr("Успех"), tr("Книга удалена."));
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось удалить книгу."));
    }
}

void MainWindow::createContextMenu() {
    userContextMenu = new QMenu(this);
    QAction *addBookAction = new QAction("Добавить книгу", this);
    QAction *removeBookAction = new QAction("Удалить книгу", this);

    connect(addBookAction, &QAction::triggered, this, &MainWindow::on_issueBookToUser);
    connect(removeBookAction, &QAction::triggered, this, &MainWindow::on_removeBookFromUser);

    userContextMenu->clear();
    userContextMenu->addAction(addBookAction);
    userContextMenu->addAction(removeBookAction);
}

void MainWindow::onUserRightClicked(const QPoint &pos) {
    QModelIndex index = ui->UserTable->indexAt(pos);
    if (index.isValid()) {
        createContextMenu();
        userContextMenu->exec(QCursor::pos());
    }
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QModelIndex index = ui->UserTable->indexAt(event->pos());
    if (index.isValid()) {
        createContextMenu();
        userContextMenu->exec(event->globalPos());
    }
}


