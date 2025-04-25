#include "User.h"

std::string User::getName() const {
    return name;
};

long User::getID() const {
    return id;
};

void User::removeBook(std::shared_ptr<Book> book) {
    issuedBooks.erase(std::remove(issuedBooks.begin(), issuedBooks.end(), book), issuedBooks.end());
}