#include "book.h"
#include <gtest/gtest.h>
#include <string>


Book::Book(const std::string& title, const std::string& authors, const std::string& publisher, int year, int pages,
    double price, const BindingType bindingType) {
    this->setTitle(title);
    this->addAuthor(authors);
    this->setPublisher(publisher);
    this->setYear(year);
    this->setBindingType(bindingType);
    this->setCost(price);
}

void Book::setTitle(const std::string name) {
    if (name.empty()) throw invalid_argument("Title must not be empty");
    title = name;
}

void Book::addAuthor(const std::string author) {
    if (author.empty()) throw invalid_argument("Author must not be empty");

    if (authors.empty()) {
        authors = author;
    } else {
        authors += ", " + author;
    }
}

void Book::removeAuthor(const std::string author) {
    size_t pos = authors.find(author);
    if (pos != std::string::npos) {
        if (pos == 0) {
            authors.erase(pos, author.length() + (authors.length() > author.length() ? 2 : 0));
        } else {
            authors.erase(pos - 2, author.length() + 2);
        }
    }
}

void Book::setPublisher(const std::string pub) {
    if (pub.empty()) {throw invalid_argument("publisher is empty");}
    this->publisher = pub;
}

void Book::setYear(int year) {
    this->year = year;
}

void Book::setPages(unsigned int pages) {
    if (pages < 1) throw std::invalid_argument("pages must be positive");
    this->pages = pages;
}

void Book::setCost(double cost) {
    if (cost < 0) throw std::invalid_argument("cost can't be negative");
    this->cost = cost;
}

void Book::setBindingType(const BindingType type) {
    this->type = type;
}

std::string Book::toString() const {
    std::string str = "Book{ title='" + title + "', authors='" + authors
                      + "', publisher='" + publisher + "', year=" + to_string(year)
                      + ", pages=" + to_string(pages) + ", cost=" + to_string(cost) + "}";
    return str;
}

std::string Book::getName() const {
    return title;
}

std::string Book::getAuthors() const {
    return authors;
}

std::string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

unsigned int Book::getPages() const {
    return pages;
}

double Book::getCost() const {
    return cost;
}