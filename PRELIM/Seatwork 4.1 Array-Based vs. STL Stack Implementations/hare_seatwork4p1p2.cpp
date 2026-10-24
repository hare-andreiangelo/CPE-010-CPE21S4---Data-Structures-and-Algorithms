#include <iostream>

// Global declaration
#define maxSize 10

int stackArr[maxSize];
int top = -1;
int i, newData;

// Function prototypes

// Observer operators
bool isEmpty();
bool isFull();
void Top();
void displayAll();

// Transformer operators
void push();
void pop();

int main() {
    int choice;

    while (true) {
        std::cout << "=========================";
        std::cout << "      STACK MENU\n";
        std::cout << "=========================";
        std::cout << "1. Push";
        std::cout << "2. Pop";
        std::cout << "3. Is Empty";
        std::cout << "4. Is Full";
        std::cout << "5. Top";
        std::cout << "6. Display All";
        std::cout << "7. Exit";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                std::cout << "Is the stack empty? "
                          << (isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 4:
                std::cout << "Is the stack full? "
                          << (isFull() ? "Yes" : "No") << std::endl;
                break;
            case 5:
                Top();
                break;
            case 6:
                displayAll();
                break;
            case 7:
                std::cout << "Exiting program..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}

// Observer operators
bool isEmpty() {
    return (top == -1);
}
bool isFull() {
    return (top == maxSize - 1);
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    std::cout << "Top element: " << stackArr[top] << std::endl;
}

void displayAll() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    std::cout << "Stack contents (Top to Bottom): ";

    for (i = top; i >= 0; i--) {
        std::cout << stackArr[i] << " ";
    }

    std::cout << std::endl;
}

// Transformer operators

void push() {
    if (isFull()) {
        std::cout << "Stack Overflow! Cannot push another element."
                  << std::endl;
        return;
    }

    std::cout << "Enter a value to push: ";
    std::cin >> newData;

    stackArr[++top] = newData;

    std::cout << newData << " pushed successfully." << std::endl;
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow! Stack is empty."
                  << std::endl;
        return;
    }

    std::cout << "Popped element: " << stackArr[top] << std::endl;
    top--;
}