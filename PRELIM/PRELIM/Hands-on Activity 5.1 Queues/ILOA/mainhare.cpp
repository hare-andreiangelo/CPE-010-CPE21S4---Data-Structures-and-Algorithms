#include <iostream>
#include <queue>
#include <string>

int main() {

    std::queue<std::string> students;

    // Array of student names
    std::string names[] = {
        "Danielle",
        "Minji",
        "Hyein",
        "Haerin",
        "Hanni"
    };

    std::cout << "--------------------\n";

    for (int i = 0; i < 5; i++) {
        students.push(names[i]);

        std::cout << "Pushed: " << names[i] << std::endl;
    }

    std::cout << "\n--------------------\n";

    std::cout << "Front student: "
              << students.front() << std::endl;

    std::cout << "\n--------------------\n";

    std::cout << "Number of students: "
              << students.size() << std::endl;

    std::cout << "\n--------------------\n";

    while (!students.empty()) {

        std::cout << "Popped: "
                  << students.front() << std::endl;

        students.pop();
    }

    std::cout << "\n----- CHECKING QUEUE -----\n";

    if (students.empty()) {
        std::cout << "Queue is empty." << std::endl;
    }

    return 0;
}