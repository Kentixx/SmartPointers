#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

static long ID = 0;

class User {
private:
    std::string name;
    long id;
public:
    User() {};
    User(const std::string& _name) : name(_name), id(++ID) {};

    std::string getName() const;
    long getID() const;
};

#endif //USER_H
