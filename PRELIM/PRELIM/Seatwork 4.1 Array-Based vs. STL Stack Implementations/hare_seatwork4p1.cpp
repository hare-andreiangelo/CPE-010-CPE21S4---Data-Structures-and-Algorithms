#include <iostream>
#include <stack>

int main(){

    // push
    // pop
    //isEmpty
    //isFull
    //Top

    //create an object
    std::stack<char> stack1;

    std::cout<<"Is the stack empty? " <<stack1.empty() <<std::endl;
    stack1.push('D');
    std::cout<<"Current top of stack: " <<stack1.top() <<std::endl;
    stack1.push('R');
    std::cout<<"Current top of stack: " <<stack1.top()<<std::endl;
    stack1.push('E');
    std::cout<<"Current top of stack: " <<stack1.top()<<std::endl;
    stack1.push('I');
    std::cout<<"Current top of stack: " <<stack1.top()<<std::endl;
    std::cout<<"Is the stack empty? " <<stack1.empty()<<std::endl;
    std::cout<<"What's the size of the stack: " <<stack1.size()<<std::endl;

    std::stack<char> stack2;

    std::cout<<"Is the stack empty? " <<stack2.empty() <<std::endl;
    stack2.push('D');
    std::cout<<"Current top of stack: " <<stack2.top() <<std::endl;
    stack2.push('A');
    std::cout<<"Current top of stack: " <<stack2.top()<<std::endl;
    stack2.push('D');
    std::cout<<"Current top of stack: " <<stack2.top()<<std::endl;
    std::cout<<"Is the stack empty? " <<stack2.empty()<<std::endl;
    std::cout<<"What's the size of the stack: " <<stack2.size()<<std::endl;

    // swap
    std::cout << "\nBefore swap:" << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << std::endl;
    std::cout << "Stack2 top: " << stack2.top() << std::endl;

    stack1.swap(stack2);

    std::cout << "After swap:" << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << std::endl;
    std::cout << "Stack2 top: " << stack2.top() << std::endl;

    // emplace
    stack1.emplace('X');

    std::cout << "After emplace('X') into Stack1:" << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;

    return 0;
}