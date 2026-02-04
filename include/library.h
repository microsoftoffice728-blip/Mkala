#pragma once

#include <vector>
#include <memory>
#include <string>
#include "../src/book.h"

class User; // forward declaration

class Library {
public:
    Library() = default;

    void addBook(const Book &book);
    bool removeBook(int id);
    std::shared_ptr<Book> findBookById(int id) const;
    std::vector<std::shared_ptr<Book>> searchByTitle(const std::string &title) const;
    std::vector<std::shared_ptr<Book>> searchByAuthor(const std::string &author) const;

    bool borrowBook(int userId, int bookId);
    bool returnBook(int userId, int bookId);

    void addUser(const User &user);
    bool removeUser(int userId);
    std::shared_ptr<User> findUserById(int userId) const;

private:
    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<User>> users;
};
