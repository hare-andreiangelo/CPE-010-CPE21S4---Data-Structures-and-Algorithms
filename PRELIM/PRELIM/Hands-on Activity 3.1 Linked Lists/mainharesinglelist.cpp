#include <iostream>
#include "singly_ll.h"

int main()
{
    Singlylist<char>* head = nullptr;
    Singlylist<char>* second = nullptr;
    Singlylist<char>* third = nullptr;
    Singlylist<char>* fourth = nullptr;
    Singlylist<char>* fifth = nullptr;
    Singlylist<char>* last = nullptr;

    // Allocate memory
    head = new Singlylist<char>;
    second = new Singlylist<char>;
    third = new Singlylist<char>;
    fourth = new Singlylist<char>;
    fifth = new Singlylist<char>;
    last = new Singlylist<char>;

    // Create CPE010
    head->data = 'C';
    second->data = 'P';
    third->data = 'E';
    fourth->data = '0';
    fifth->data = '1';
    last->data = '0';

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = last;
    last->next = nullptr;

    // Traverse
    std::cout << "Testing the ListTraversal Function" << std::endl;
    ListTraversal(head);

    // Insert Head
    std::cout << "Testing the sllInsertHead Function" << std::endl;
    sllInsertHead('G', &head);
    ListTraversal(head);

    // General Insert (after P)
    std::cout << "Testing the sllGeneralInsert Function" << std::endl;
    sllGeneralInsert('E', head->next->next);
    ListTraversal(head);

    // Delete C
    std::cout << "Testing the sllDeleteNode Function (Delete C)" << std::endl;
    sllDeleteNode('C', &head);
    ListTraversal(head);

    // Delete P
    std::cout << "Testing the sllDeleteNode Function (Delete P)" << std::endl;
    sllDeleteNode('P', &head);
    ListTraversal(head);

    // Delete List
    std::cout << "Testing the sllDeleteList Function" << std::endl;
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}