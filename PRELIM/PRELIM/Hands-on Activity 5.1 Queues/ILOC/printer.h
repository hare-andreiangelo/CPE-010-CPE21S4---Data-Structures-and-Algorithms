#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>


// Job class
class Job {
public:
    int jobID;
    std::string userName;
    int pages;

    // Constructor
    Job(int newID, std::string newUser, int newPages) {
        jobID = newID;
        userName = newUser;
        pages = newPages;
    }
};


// Node for the queue
class jobNode {
public:
    Job data;
    jobNode* next;

    // Constructor
    jobNode(Job newJob) : data(newJob), next(nullptr) {
    }
};


// Printer class
class Printer {
private:
    jobNode* front;
    jobNode* back;

public:

    // Constructor
    Printer() {
        front = nullptr;
        back = nullptr;
    }


    // Enqueue
    void enqueue(Job newJob) {

        jobNode* newNode = new jobNode(newJob);

        if (front == nullptr && back == nullptr) {

            front = newNode;
            back = newNode;

            return;
        }

        back->next = newNode;

        back = newNode;
    }


    // Dequeue
    void dequeue() {

        if (front == nullptr && back == nullptr) {

            std::cout << "The printer queue is empty. Nothing to dequeue.\n";
            return;
        }

        jobNode* temp = front;

        std::cout << "Processing Job ID: "
                  << temp->data.jobID << "\n";

        std::cout << "User: "
                  << temp->data.userName << "\n";

        std::cout << "Pages: "
                  << temp->data.pages << "\n";

        std::cout << "Job completed.\n\n";

        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        }

        delete temp;
    }


    // Display all jobs
    void displayQueue() {

        if (front == nullptr) {

            std::cout << "The printer queue is empty.\n";
            return;
        }

        jobNode* current = front;

        std::cout << "----- CURRENT PRINT QUEUE -----\n";

        while (current != nullptr) {

            std::cout << "Job ID: "
                      << current->data.jobID << "\n";

            std::cout << "User: "
                      << current->data.userName << "\n";

            std::cout << "Pages: "
                      << current->data.pages << "\n";

            std::cout << "-------------------------\n";

            current = current->next;
        }

        std::cout << std::endl;
    }
};

#endif