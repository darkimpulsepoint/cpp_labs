#pragma once
#include <string>

#pragma once

#include <stdexcept>
#include <list>

template<typename T>
class Stack {
private:
  struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
  };

  Node* topNode;

public:
  Stack();
  ~Stack();

  void push(T value);
  void pop();
  T top();
  bool isEmpty();
};

template<typename T>
Stack<T>::Stack() : topNode(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
  while (!isEmpty()) {
    pop();
  }
}

template<typename T>
void Stack<T>::push(T value) {
  Node* newNode = new Node(value);
  newNode->next = topNode;
  topNode = newNode;
}

template<typename T>
void Stack<T>::pop() {
  if (isEmpty()) {
    throw std::underflow_error("stack is empty");
  }
  Node* temp = topNode;
  topNode = topNode->next;
  delete temp;
}

template<typename T>
T Stack<T>::top() {
  if (isEmpty()) {
    throw std::underflow_error("stack is empty");
  }
  return topNode->data;
}

template<typename T>
bool Stack<T>::isEmpty() {
  std::list<int> stack;
  return topNode == nullptr;
}


class BracketsService {
public:
  static bool areBracketsValid(const std::string& str);
};

bool BracketsService::areBracketsValid(const std::string& str) {
  Stack<char> stack;

  for (char ch : str) {
    if (ch == '(' || ch == '[' || ch == '{') {
      stack.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (stack.isEmpty()) {
        return false;
      }
      char top = stack.top();
      stack.pop();
      if ((ch == ')' && top != '(') ||
          (ch == ']' && top != '[') ||
          (ch == '}' && top != '{')) {
        return false;
          }
    }
  }

  return stack.isEmpty();
}
