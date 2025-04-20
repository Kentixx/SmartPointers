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

std::weak_ptr<Book> Library::findBookByTitle(const std::string& request) {
    for (const auto& book : books_list) {
        if (request == book->getTitle() || request == book->getAuthor()) {
            return std::weak_ptr<Book>(book);
        }
    }
    return std::weak_ptr<Book>();
}

std::vector<std::weak_ptr<Book>> Library::findBooksByAuthor(const std::string& request) {
    std::vector<std::weak_ptr<Book>> foundBooks;
    for (const auto& book : books_list) {
        if (book->getAuthor() == request) {
            foundBooks.emplace_back(std::weak_ptr<Book>(book));
        }
    }
    return foundBooks;
}

void createBooksAndPrint(std::vector<std::shared_ptr<Book>> books) {
    Library library;
    for (auto book : books) {
        library.addBook(book);
    }
    library.printBooks();
}

void findBookByTitleAndPrint(Library& library, const std::string& book_title) {
    std::weak_ptr<Book> weakBook = library.findBookByTitle(book_title);
    if (auto sharedBook = weakBook.lock()) { // Проверяем, доступен ли объект
        std::cout << sharedBook->getTitle() << ", "
        << sharedBook->getAuthor() << ", "
        << sharedBook->getYear() << std::endl;
    } else {
        std::cout << "No book found with such title" << std::endl;
    }
}

void findBooksByAuthorAndPrint(Library& library, const std::string& book_author) {
    auto weakBooks = library.findBooksByAuthor(book_author);
    bool found = false;
    for (const auto& weakBook : weakBooks) {
        if (auto sharedBook = weakBook.lock()) {
            std::cout << sharedBook->getTitle() << ", "
            << sharedBook->getAuthor() << ", "
            << sharedBook->getYear() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found written by that author" << std::endl;
    }
}
