#include "../include/library.h"
#include "../include/user.h"

void Library::addBook(const Book &book) {
    books.push_back(std::make_shared<Book>(book));
}

bool Library::removeBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getId() == id) {
            books.erase(it);
            return true;
        }
    }
    return false;
}

std::shared_ptr<Book> Library::findBookById(int id) const {
    for (auto &b : books) {
        if (b->getId() == id) return b;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Book>> Library::searchByTitle(const std::string &title) const {
    std::vector<std::shared_ptr<Book>> res;
    for (auto &b : books) {
        if (b->getTitle().find(title) != std::string::npos) res.push_back(b);
    }
    return res;
}

std::vector<std::shared_ptr<Book>> Library::searchByAuthor(const std::string &author) const {
    std::vector<std::shared_ptr<Book>> res;
    for (auto &b : books) {
        if (b->getAuthor().find(author) != std::string::npos) res.push_back(b);
    }
    return res;
}

bool Library::borrowBook(int userId, int bookId) {
    auto usrIt = std::find_if(users.begin(), users.end(), [&](const std::shared_ptr<User> &u){ return u->getId() == userId; });
    if (usrIt == users.end()) return false;
    auto bookPtr = findBookById(bookId);
    if (!bookPtr) return false;
    if (!bookPtr->borrowCopy()) return false;
    if (!(*usrIt)->borrowBook(bookId)) {
        // rollback
        bookPtr->returnCopy();
        return false;
    }
    return true;
}

bool Library::returnBook(int userId, int bookId) {
    auto usrIt = std::find_if(users.begin(), users.end(), [&](const std::shared_ptr<User> &u){ return u->getId() == userId; });
    if (usrIt == users.end()) return false;
    auto bookPtr = findBookById(bookId);
    if (!bookPtr) return false;
    if (!(*usrIt)->returnBook(bookId)) return false;
    bookPtr->returnCopy();
    return true;
}

void Library::addUser(const User &user) {
    users.push_back(std::make_shared<User>(user));
}

bool Library::removeUser(int userId) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == userId) {
            users.erase(it);
            return true;
        }
    }
    return false;
}

std::shared_ptr<User> Library::findUserById(int userId) const {
    for (auto &u : users) {
        if (u->getId() == userId) return u;
    }
    return nullptr;
}
