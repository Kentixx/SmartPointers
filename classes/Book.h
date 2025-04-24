#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <memory>

class Book {
public:
    bool isIssued;
    Book(const std::string& title, const std::string& author, const int& year)
      : title(title), author(author), year(year), isIssued(false) {};
    ~Book() {};

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;

private:
    std::string title;
    std::string author;
    int year;

};

void printBookInfo(const std::unique_ptr<Book>& book);
void createAndPrintBook(const std::string& title, const std::string& author, const int& year);

#endif //BOOK_H
