#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <memory>
#include "../classes/Book.h"

class BookModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit BookModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void setBooks(const QVector<std::shared_ptr<Book>> &books);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QVector<std::shared_ptr<Book>> books;
};

#endif //BOOKMODEL_H
