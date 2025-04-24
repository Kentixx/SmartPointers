#include "UserModel.h"

int UserModel::rowCount(const QModelIndex &parent) const override {
    return users.size();
}

int UserModel::columnCount(const QModelIndex &parent) const override {
    return 1;
}

void UserModel::setUsers(const QVector<QString> &users) {
    beginResetModel();
    this->users = users;
    endResetModel();
}

QVariant UserModel::data(const QModelIndex &index, int role) const override {
    if (role == Qt::DisplayRole) {
        return users.at(index.row());
    }
    return QVariant();
}
