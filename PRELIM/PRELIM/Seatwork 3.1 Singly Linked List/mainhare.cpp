#include <iostream>
#include "singly_ll.h"

using namespace std;

int main()
{

    Singlylist<char>* head = nullptr;
    Singlylist<char>* second = nullptr;
    Singlylist<char>* third = nullptr;
    Singlylist<char>* fourth = nullptr;

    head = new Singlylist<char>;
    second = new Singlylist<char>;
    third = new Singlylist<char>;
    fourth = new Singlylist<char>;


    head->data = 'J';
    second->data = 'I';
    third->data = 'M';
    fourth->data = 'Q';
    

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    cout<<"Testing the ListTraversal Function \n";
    ListTraversal(head);

    cout<<"Testing the ListTraversal Function \n";
    sllInsertHead('Q', &head);
    ListTraversal(head);

    cout<<"Testing the ListTraversal Function \n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    cout<<"Testing the ListTraversal Function \n";
    sllInsertEnd('U', &head);
    ListTraversal(head);

    cout<<"Testing the ListTraversal Function \n";
    sllDeleteNode('X', &head);
    ListTraversal(head);
    sllDeleteNode('Q', &head);
    ListTraversal(head);
    sllDeleteNode('U', &head);
    ListTraversal(head);
    return 0;    
}
