#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <QVector>
#include <memory>
#include "Book.h"

static long ID = 0;

class User {
private:
    std::string name;
    long id;
public:
    QVector<std::shared_ptr<Book>> issuedBooks;

    User() {};
    User(const std::string& _name) : name(_name), id(++ID) {};
    std::string getName() const;
    long getID() const;
    void removeBook(std::shared_ptr<Book> book);
};

#endif //USER_H
