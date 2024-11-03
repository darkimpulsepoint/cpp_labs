#pragma once

#include "ListService.h"
#include "ObjectInfo.h"

#include <sstream>
#include <unordered_set>

#include "FileReader.h"

template <typename T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& data);
    };

    Node* head;

    LinkedList();
    ~LinkedList();
    void push_back(const T& data);
    Node* get_head() const;
    void sort();
};


class ListService {
public:
    template <typename T>
    static void compress(LinkedList<T>& list);

    static LinkedList<ObjectInfo> createListFromFile(const std::string& filename);
};


template <typename T>
LinkedList<T>::Node::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::get_head() const {
    return head;
}

template <typename T>
void LinkedList<T>::sort() {
    if (!head || !head->next) return;

    for (Node* i = head; i; i = i->next) {
        for (Node* j = head; j->next; j = j->next) {
            if (j->data.getCode() > j->next->data.getCode()) {
                std::swap(j->data, j->next->data);
            }
        }
    }
}

template <typename T>
void ListService::compress(LinkedList<T>& list) {
    if (!list.get_head()) return;

    std::unordered_set<std::string> uniqueNames;
    typename LinkedList<T>::Node* current = list.get_head();
    typename LinkedList<T>::Node* prev = nullptr;

    while (current) {
        if (uniqueNames.find(current->data.getName()) != uniqueNames.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            uniqueNames.insert(current->data.getName());
            prev = current;
            current = current->next;
        }
    }
}

LinkedList<ObjectInfo> ListService::createListFromFile(const std::string& filename) {
    LinkedList<ObjectInfo> list;
    std::istringstream iss(FileReader::read (filename));
    std::string name;
    int code;

    while (iss >> name >> code) {
        list.push_back(ObjectInfo(name, code));
    }

    return list;
}