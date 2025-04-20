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

    std::weak_ptr<Book> findBookByTitle(const std::string& request);
    std::vector<std::weak_ptr<Book>> findBooksByAuthor(const std::string& request);
};

void createBooksAndPrint(const int& amount);
void findBookByTitleAndPrint(Library& library, const std::string& book_title);
void findBooksByAuthorAndPrint(Library& library, const std::string& book_author);

#endif //LIBRARY_H
