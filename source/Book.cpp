#include "Book.h"

std::string Book::getTitle() const {
  	return title;
}

std::string Book::getAuthor() const {
  	return author;
}

int Book::getYear() const {
  	return year;
}

void printBookInfo(const std::unique_ptr<Book>& book) {
    if (book) {
        std::cout << book->getTitle() << ", ";
        std::cout << book->getAuthor() << ", ";
        std::cout << book->getYear() << std::endl;
    } else {
        std::cout << "Book is null!" << std::endl;
    }
}

void createAndPrintBook(const std::string& title, const std::string& author, const int& year) {
    std::unique_ptr<Book> book = std::make_unique<Book>(title, author, year);
    printBookInfo(book);
}