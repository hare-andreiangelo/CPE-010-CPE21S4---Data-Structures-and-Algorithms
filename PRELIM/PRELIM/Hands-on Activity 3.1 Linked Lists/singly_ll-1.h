#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class Singlylist {
public:
    T data;
    Singlylist<T>* next;
};

template <typename T>
void ListTraversal(Singlylist<T>* node) {

    while (node != nullptr) {

        std::cout << node->data;

        if (node->next != nullptr) {
            std::cout << "->";
        }

        node = node->next;
    }

    std::cout << std::endl;
}

template <typename T>
void sllInsertHead(T newData, Singlylist<T>** currentHead) {

    Singlylist<T>* newNode = new Singlylist<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, Singlylist<T>* prevNode) {

    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }

    Singlylist<T>* newNode = new Singlylist<T>;
    newNode->data = newData;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T>
void sllInsertEnd(T newData, Singlylist<T>** head) {

    Singlylist<T>* newNode = new Singlylist<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Singlylist<T>* currentNode = *head;

    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, Singlylist<T>** head) {

    if (*head == nullptr) {
        return;
    }

    Singlylist<T>* currNode = *head;
    Singlylist<T>* prevNode = nullptr;

    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr) {
        return;
    }

    if (prevNode == nullptr) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(Singlylist<T>** head) {

    Singlylist<T>* current = *head;

    while (current != nullptr) {
        Singlylist<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif