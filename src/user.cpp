#include "../include/user.h"

User::User(int id, const std::string &name) : id(id), name(name) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }

bool User::borrowBook(int bookId) {
    // prevent duplicate borrow
    for (int b : borrowed) {
        if (b == bookId) return false;
    }
    borrowed.push_back(bookId);
    return true;
}

bool User::returnBook(int bookId) {
    for (auto it = borrowed.begin(); it != borrowed.end(); ++it) {
        if (*it == bookId) {
            borrowed.erase(it);
            return true;
        }
    }
    return false;
}

const std::vector<int>& User::borrowedBooks() const { return borrowed; }
