#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main()
{
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    // Link the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Testing the DllTraverse Function" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    // Insert at head
    std::cout << "Testing the DllInsertHead Function" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout << std::endl;

    // Insert at end
    std::cout << "Testing the DllInsertEnd Function" << std::endl;
    dllInsertEnd('O', head);
    dllTraverse(head);

    std::cout << std::endl;

    // General insert
    std::cout << "Testing the DllGeneralInsert Function" << std::endl;
    dllGeneralInsert('E', head);
    dllTraverse(head);

    std::cout << std::endl;

    // Delete node
    std::cout << "Testing the DllDeleteNode Function" << std::endl;
    dllDeleteNode('C', &head);
    dllTraverse(head);

    std::cout << std::endl;

    std::cout << "Testing the DllDeleteNode Function" << std::endl;
    dllDeleteNode('P', &head);
    dllTraverse(head);

    std::cout << std::endl;

    // Delete entire list
    std::cout << "Testing the DllDeleteList Function" << std::endl;
    dllDeleteList(&head);
    dllTraverse(head);

    return 0;
}