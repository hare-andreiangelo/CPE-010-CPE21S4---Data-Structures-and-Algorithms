#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main()
{
    // Create arrays with unsorted random values
    int unsortedArr[maxSize];
    int bubbleArr[maxSize];
    int selectionArr[maxSize];
    int insertionArr[maxSize];

    // Use time(0) as seed for random values
    srand(time(0));

    // Populate the arrays with random values
    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = rand() %100;

        bubbleArr[i] = unsortedArr[i];
        selectionArr[i] = unsortedArr[i];
        insertionArr[i] = unsortedArr[i];
    }

    std::cout << "\nOriginal Array:\n";
    displayArr(unsortedArr);

    std::cout << "\nBubble Sort testing:\n";
    bubbleSort(bubbleArr, maxSize);
    displayArr(bubbleArr);

    std::cout << "\nSelection Sort testing:\n";
    selectionSort(selectionArr, maxSize);
    displayArr(selectionArr);

    std::cout << "\nInsertion Sort testing:\n";
    insertionSort(insertionArr, maxSize);
    displayArr(insertionArr);

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}