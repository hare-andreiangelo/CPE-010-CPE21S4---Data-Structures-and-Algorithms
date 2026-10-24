#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};


// Creating the new node
template <typename T>
qNode<T>* new_node(T newDATA) {
    qNode<T>* newNode = new qNode<T>;

    newNode->data = newDATA;
    newNode->next = nullptr;

    return newNode;
}


// Enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    // Create a new node
    qNode<T>* newNode = new_node(newData);

    // Inserting into an empty queue
    // How do we know that the queue is empty?
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {

        // Assign the frontPtr to the newNode
        (*frontPtr) = newNode;

        // Assign the backPtr to the newNode
        (*backPtr) = newNode;

        return;
    }

    // Point the back next to the newNode
    (*backPtr)->next = newNode;

    // The newNode will be the new backPtr
    (*backPtr) = newNode;

    return;
}


// Dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {

    // Check if the queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "The queue is empty. Nothing to dequeue.\n";
        return;
    }

    // Create temporary pointer
    qNode<T>* tempPtr = (*frontPtr);

    // Check if queue has only 1 node left
    if ((*frontPtr) == (*backPtr)) {

        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;

        delete tempPtr;

        return;
    }

    // Update the front pointer
    (*frontPtr) = (*frontPtr)->next;

    // Delete the old front node
    delete tempPtr;
}


// Display all items in the queue
// Check the traversal in singly linked list
template <typename T>
void displayQueue(qNode<T>* frontPtr) {

    // Check if the queue is empty
    if (frontPtr == nullptr) {
        std::cout << "The queue is empty.\n";
        return;
    }

    // Temporary pointer to store the frontPtr
    qNode<T>* current = frontPtr;

    // Create a loop that will print current->data
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}


#endif // QUEUELL_H