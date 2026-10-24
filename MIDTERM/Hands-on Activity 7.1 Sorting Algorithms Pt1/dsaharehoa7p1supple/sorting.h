#ifndef SORTING_H
#define SORTING_H

#include <iostream>

template<typename T>
void bubbleSort(T arr[], int maxSize)
{
    for (int i = 0; i < maxSize; i++)
    {
        for (int j = i + 1; j < maxSize; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

#endif