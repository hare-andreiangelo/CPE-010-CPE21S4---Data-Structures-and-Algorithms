#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
class BinaryTree{
    private:
        T key;

        // pointer for left and right child
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;
    public:
        //constructor
        BinaryTree(T rootObj);
        //insert a child on the left side
        void insertChildLeft(T newNode);
        //insert a child on the right side
        void insertChildRight(T newnode);

        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();
        T getRootVal();
        void setRootVal(T newNode);

};


// constructor
template<typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;

}
//insert child: 
template<typename T>
void BinaryTree<T>::insertChildLeft(T newNode){
    if(leftChild == nullptr){
        leftChild = new BinaryTree<T>(newNode);
    }else{
        BinaryTree<T> * newChild = new BinaryTree<T>(newNode);

        //move the current left child below the new node
        newChild->leftChild = leftChild;
        leftChild = newChild;
    }
}

template<typename T>
void BinaryTree<T>::insertChildRight(T newNode){
    if(rightChild == nullptr){
        rightChild = new BinaryTree<T>(newNode);
    }else{
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
        newChild->rightChild = rightChild;
        rightChild = newChild;
    }
}

template<typename T>
BinaryTree<T> *BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template<typename T>
BinaryTree<T> *BinaryTree<T>::getRightChild(){
    return rightChild;
}

template <typename T>
T BinaryTree<T>::getRootVal(){
    return key;
}


template <typename T>
void BinaryTree<T>::setRootVal(T newNode){
    key = newNode;
}


#endif