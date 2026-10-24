#include <iostream>
#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* next;
        DoubleList<T>* prev;
};

// Creating a node function
template <typename T>
DoubleList<T> *createNode(T newData){

    //dynamic memory allocation for a new node
    DoubleList<T>* newNode= new DoubleList<T>;

    newNode->data = newData;

    //
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template<typename T>
void dllTraverse(DoubleList<T>* currentNode)
{
    if (currentNode == nullptr)
    {
        std::cout << "The List is empty." << std::endl;
        return;
    }

    DoubleList<T>* tail = nullptr;

    std::cout << "Forward: ";

    while (currentNode != nullptr)
    {
        std::cout << currentNode->data;

        if (currentNode->next != nullptr)
        {
            std::cout << "->";
        }

        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    std::cout << "Reverse: ";

    while (tail != nullptr)
    {
        std::cout << tail->data;

        if (tail->prev != nullptr)
        {
            std::cout << "->";
        }

        tail = tail->prev;
    }

    std::cout << std::endl;
}

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead)
{
    DoubleList<T>* newNode = createNode(newData);

    newNode->next = *currentHead;

    if (*currentHead != nullptr)
    {
        (*currentHead)->prev = newNode;
    }

    *currentHead = newNode;
}

template<typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead)
{
    DoubleList<T>* newNode = createNode(newData);

    while (currentHead->next != nullptr)
    {
        currentHead = currentHead->next;
    }

    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous value cannot be null" <<std::endl;
        return;
    }
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T> 
void dllDeleteNode(T findData, DoubleList<T>** head){
    if (*head == nullptr) return;

    DoubleList<T>* currentNode = *head;
    DoubleList<T>* prevNode = nullptr;

    while (currentNode != nullptr && currentNode-> data != findData) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) return;

    if (prevNode == nullptr) {
        *head = currentNode->next;
    }
    else {
        prevNode->next = currentNode->next;
    }

    delete currentNode;
}

template <typename T>
void dllDeleteList(DoubleList<T>** head)
{
    DoubleList<T>* current = *head;

    while (current != nullptr)
    {
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
    
}

#endif