#include "UserModel.h"

int UserModel::rowCount(const QModelIndex &parent) const {
    return users.size();
}

int UserModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

void UserModel::setUsers(const QVector<std::shared_ptr<User>> &users) {
    beginResetModel();
    this->users = users;
    endResetModel();
}

QVariant UserModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QVariant(QString::fromStdString(users.at(index.row())->getName()));
    }
    return QVariant();
}
