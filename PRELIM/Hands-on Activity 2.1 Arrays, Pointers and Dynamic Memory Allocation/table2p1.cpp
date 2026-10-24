#include <iostream>
#include <string.h>

class Student{
private:
std::string studentName;
int studentAge;

public:
//constructor
Student(std::string newName ="John Doe", int newAge=18){
studentName = std::move(newName);
studentAge = newAge;
std::cout << "Constructor Called." << std::endl;
};

//deconstructor
~Student(){
std::cout << "Destructor Called." << std::endl;
}
//Copy Constructor
Student(const Student &copyStudent){
std::cout << "Copy Constructor Called" << std::endl;
studentName = copyStudent.studentName;
studentAge = copyStudent.studentAge;
}


// Copy Assignment Operator
Student& operator=(const Student& other) {
    
    std::cout << "Copy Assignment Operator Called" << std:: endl;
    
    if (this != &other) {
    studentName = other.studentName;
    studentAge = other.studentAge;

    }
    
    return *this;
}


//Display Attributes
void printDetails(){
std::cout << this->studentName << " " << this->studentAge << std::endl;
}
};

int main() {
Student student1("Hare", 24);
Student student2(student1);
Student student3;
student3 = student2;
return 0;
}