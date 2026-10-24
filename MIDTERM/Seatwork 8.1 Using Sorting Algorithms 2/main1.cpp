#include <iostream>

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[10];

    std::cout << "Enter 10 integer values:\n";

    for (int i = 0; i < 10; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "\nOriginal array: ";

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    shellSort(arr, 10);

    std::cout << "\nShell Sort: ";

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}