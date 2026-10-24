#include <iostream>
#include "printer.h"

int main() {

    Printer printer;

    std::cout << "===== SHARED PRINTER SIMULATION =====\n\n";

    std::cout << "----- JOBS -----\n";

    printer.enqueue(Job(1, "Danielle", 5));
    std::cout << "Job 1 added.\n";

    printer.enqueue(Job(2, "Minji", 10));
    std::cout << "Job 2 added.\n";

    printer.enqueue(Job(3, "Haerin", 3));
    std::cout << "Job 3 added.\n";

    printer.enqueue(Job(4, "Hanni", 8));
    std::cout << "Job 4 added.\n";


    std::cout << "\n";
    printer.displayQueue();

    std::cout << "----- PROCESSED JOBS -----\n\n";

    printer.dequeue();
    printer.dequeue();
    printer.dequeue();
    printer.dequeue();

    std::cout << "----- AFTER PROCESSING -----\n";

    printer.displayQueue();


    return 0;
}