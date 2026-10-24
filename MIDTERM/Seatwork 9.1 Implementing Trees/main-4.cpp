#include <iostream>
#include "binarytree.h"


int main(){

    BinaryTree<char>* root = new BinaryTree<char>('A');
    root->insertChildLeft('B');
    root->insertChildRight('C');


    root->getLeftChild()->insertChildLeft('D');
    root->getLeftChild()->insertChildRight('E');
    root->getRightChild()->insertChildRight('F');


    std::cout<<"The root: " << root->getRootVal()<<std::endl;
    std::cout<<"The left child of root a is: " <<root->getLeftChild()->getRootVal()<<std::endl;
    std::cout<<"The right child of root a is: " <<root->getRightChild()->getRootVal()<<std::endl;
    std::cout<<"The left child of node b is: " <<root->getLeftChild()->getLeftChild()->getRootVal()<<std::endl;
    std::cout<<"The left child of node b is: " <<root->getLeftChild()->getRightChild()->getRootVal()<<std::endl;
    std::cout<<"The left child of node c is: " <<root->getRightChild()->getRightChild()->getRootVal()<<std::endl;

    root -> getRightChild()->setRootVal('V');
    std::cout<<"The New RIGHT of child of root a is: " <<root->getRightChild()->getRootVal()<<std::endl;


    // test it here:
    root -> getLeftChild()->setRootVal('Y');
    std::cout<<"The New LEFT child of root a is: " <<root->getLeftChild()->getRootVal()<<std::endl;

return 0;
}

