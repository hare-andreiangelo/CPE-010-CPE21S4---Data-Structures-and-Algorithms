#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr {
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    // Constructor
    queueArr(size_t capacity = 10);

    bool Empty();
    size_t Size();
    void Clear();

    T front();
    T back();

    void Enqueue(T value);
    void Dequeue();

    // Copy constructor
    queueArr(const queueArr& other);

    // Copy assignment operator
    queueArr& operator=(const queueArr& other);

    // Destructor
    ~queueArr();
};


// Constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    if (capacity == 0) {
        capacity = 10;
    }

    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}


// Empty
template <typename T>
bool queueArr<T>::Empty() {
    return (q_size == 0);
}


// Size
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}


// Clear
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}


// Front
template <typename T>
T queueArr<T>::front() {
    // What will happen if the queue is already empty?
    if (Empty()) {
        std::cout << "The Queue is Empty.\n";
        return T();
    }

    return q_array[q_front];
}


// Back
template <typename T>
T queueArr<T>::back() {
    if (Empty()) {
        std::cout << "The Queue is Empty.\n";
        return T();
    }

    return q_array[q_back];
}


// Enqueue
template <typename T>
void queueArr<T>::Enqueue(T value) {

    // Check if the queue is full
    if (q_size == q_capacity) {
        std::cout << "The Queue is Full.\n";
        return;
    }

    // Compute q_back for circular queue
    q_back = (q_back + 1) % q_capacity;

    // Assign value to the updated q_back
    q_array[q_back] = value;

    // Increment q_size
    q_size++;

    return;
}


// Dequeue
template <typename T>
void queueArr<T>::Dequeue() {

    // Check if the queue is empty
    if (Empty()) {
        std::cout << "The Queue is Empty.\n";
        return;
    }

    // Move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // Decrement q_size
    q_size--;

    // Reset index when queue becomes empty
    if (Empty()) {
        Clear();
        return;
    }
}


// Copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr<T>& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}


// Copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {

    // Prevent self-assignment
    if (this == &other) {
        return *this;
    }

    delete[] q_array;

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }

    return *this;
}


// Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
}


#endif // QUEUEARR_H