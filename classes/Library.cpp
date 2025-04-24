#include "Library.h"

void Library::addBook(std::shared_ptr<Book> book) {
    books_list.emplace_back(book);
}

void Library::removeBook(std::shared_ptr<Book> book) {
    auto pos = std::find(books_list.begin(), books_list.end(), book);
    if (pos != books_list.end()) {
        books_list.erase(pos);
    }
}

void Library::printBooks() {
    for (const auto& book : books_list) {
        std::cout << book->getTitle() << ", ";
        std::cout << book->getAuthor() << ", ";
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
    for (const auto& book : books) {
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

void Library::createUser(const std::string& username) {
    std::shared_ptr<User> user = std::make_shared<User>(username);
    users_list.emplace_back(user);
}

void Library::createUser(std::shared_ptr<User> user) {
    users_list.emplace_back(user);
}

void Library::deleteUser(const std::string& username) {
    auto pos = std::remove_if(users_list.begin(), users_list.end(),
        [&username](const std::shared_ptr<User>& user) {
            return user->getName() == username;
        });
    if (pos != users_list.end()) {
        users_list.erase(pos, users_list.end());
    }
}

bool Library::issueBook(const std::string& title, int ID) {
    for (const auto& book : books_list) {
        if (book->getTitle() == title && !book->isIssued) {
            book->isIssued = true;
            for (const auto& user : users_list) {
                if (user->getID() == ID) {
                    user->issuedBooks.emplace_back(book);
                    return true;
                }
            }
        }
    }
    return false;
}

void Library::printUsers() const {
    std::cout << "-------------------" << std::endl;
    for (const auto& user : users_list) {
        std::cout << "User: " << user->getName() << std::endl;
        std::cout << "ID: " << user->getID() << std::endl;
        if (!user->issuedBooks.empty()) {
            std::cout << "Issued Books: " << std::endl;
            for (const auto& book : user->issuedBooks) {
                std::cout << book->getTitle() << ", "<< book->getAuthor() << std::endl;
            }
        }
        std::cout << "-------------------" << std::endl;
    }
}

void demonstrateLibraryFunctions(Library& library) {
    auto book1 = std::make_shared<Book>("1984", "George Orwell", 1949);
    auto book2 = std::make_shared<Book>("Animal Farm", "George Orwell", 1945);
    auto book3 = std::make_shared<Book>("Brave New World", "Aldous Huxley", 1932);
    auto book4 = std::make_shared<Book>("Fahrenheit 451", "Ray Bradbury", 1953);
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    auto user1 = std::allocate_shared<User>(std::allocator<User>(), "Dan");
    auto user2 = std::allocate_shared<User>(std::allocator<User>(), "Nastya");
    auto user3 = std::allocate_shared<User>(std::allocator<User>(), "Ivan");

    library.createUser(user1);
    library.createUser(user2);
    library.createUser(user3);

    std::cout << "Available books in the library:" << std::endl;
    library.printBooks();
    std::cout << std::endl;

    std::cout << "Users in the library:" << std::endl;
    library.printUsers();
    std::cout << std::endl;

    library.issueBook("1984", 1);
    library.issueBook("Animal Farm", 1);
    library.issueBook("Fahrenheit 451", 3);
    library.issueBook("Brave New World", 2);

    std::cout << "Books after issuing:" << std::endl;
    library.printBooks();
    std::cout << std::endl;

    std::cout << "Users after issuing books:" << std::endl;
    library.printUsers();
}

