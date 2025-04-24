#include "BookModel.h"

int BookModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return books.size();
}

int columnCount(const QModelIndex &parent) {
    return 3;
}

void BookModel::setBooks(const QVector<std::shared_ptr<Book>> &books) {
    beginResetModel();
    this->books = books;
    endResetModel();
}

QVariant BookModel::data(const QModelIndex &index, int role) const override {
    if (role == Qt::DisplayRole) {
        const auto &book = books.at(index.row());
        switch (index.column()) {
            case 0: return QVariant(QString::fromStdString(book->getTitle()));
            case 1: return QVariant(QString::fromStdString(book->getAuthor()));
            case 2: return QVariant(book->getYear());
        }
    }
    return QVariant();
}

