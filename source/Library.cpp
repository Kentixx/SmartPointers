#include "Library.h"

void Library::addBook(std::shared_ptr<Book> book) {
    books_list.emplace_back(book);
}

void Library::removeBook(std::shared_ptr<Book> book) {
    if (std::find(books_list.begin, books_list.end, book) == NULL) {
        return;
    }
    auto pos = std::find(books_list.begin, books_list.end, book);
    books_list.erase(books_list.cbegin + pos);
}

void Library::printBooks() {
    for (auto book : books_list) {
        std::cout << book->getTitle() << std::endl;
        std::cout << book->getAuthor() << std::endl;
        std::cout << book->getYear() << std::endl;
    }
}

void CreateBooksAndPrint(std::vector<std::shared_ptr<Book>> books) {
    Library library;
    for (auto book : books) {
        library.addBook(book);
    }
    library.printBooks();
}
