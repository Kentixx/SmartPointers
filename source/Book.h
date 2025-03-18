#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <memory>

class Book {
public:
    Book(const std::string& title, const std::string& author, const int& year)
      : title(title), author(author), year(year) {};
    ~Book();

    std::string getTitle();
    std::string getAuthor();
    int getYear();

private:
    std::string title;
    std::string author;
    int year;
};

void printBookInfo(const std::unique_ptr<Book>& book);
void createAndPrintBook(const std::string& title, const std::string& author, const int& year);

#endif //BOOK_H
