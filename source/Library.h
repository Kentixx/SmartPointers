#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <memory>
#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<std::shared_ptr<Book>> books_list;
public:
    Library() {};
    Library(std::vector<std::shared_ptr<Book>> _books_list) : books_list(_books_list) {};
    ~Library() {};
    void addBook(std::shared_ptr<Book> book);
    void removeBook(std::shared_ptr<Book> book);
    void printBooks();
};

void CreateBooksAndPrint(const int& amount);

#endif //LIBRARY_H
