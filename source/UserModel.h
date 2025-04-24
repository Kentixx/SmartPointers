#ifndef USERMODEL_H
#define USERMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QString>

class UserModel : public QAbstractTableModel {
    Q_OBJECT

public:
    UserModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void setUsers(const QVector<QString> &users);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QVector<QString> users;
};

#endif //USERMODEL_H
