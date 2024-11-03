#pragma once
#include <vector>
#include <string>
#include "book.h"

class BookLibrary {
public:
    BookLibrary();

    void addBook(const Book& book);

    std::vector<Book> booksByAuthor(const std::string& author) const;

    std::vector<Book> booksByPublisher(const std::string& publisher) const;

    std::vector<Book> booksAfterYear(int year) const;

private:
    std::vector<Book> books;
};