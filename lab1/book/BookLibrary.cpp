#include "BookLibrary.h"

BookLibrary::BookLibrary() {
    books = vector<Book>();
}

void BookLibrary::addBook(const Book& book) {
    books.push_back(book);
}

std::vector<Book> BookLibrary::booksByAuthor(const std::string& author) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getAuthors().find(author) != std::string::npos) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> BookLibrary::booksByPublisher(const std::string& publisher) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getPublisher() == publisher) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> BookLibrary::booksAfterYear(int year) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getYear() > year) {
            result.push_back(book);
        }
    }
    return result;
}