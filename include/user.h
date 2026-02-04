#pragma once

#include <string>
#include <vector>

class User {
public:
    User() = default;
    User(int id, const std::string &name);

    int getId() const;
    std::string getName() const;

    bool borrowBook(int bookId);
    bool returnBook(int bookId);

    const std::vector<int>& borrowedBooks() const;

private:
    int id{0};
    std::string name;
    std::vector<int> borrowed;
};
