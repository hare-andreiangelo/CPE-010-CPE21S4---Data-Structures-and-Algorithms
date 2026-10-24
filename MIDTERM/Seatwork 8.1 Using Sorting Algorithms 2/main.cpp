#include <iostream>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0, 9);

    std::cout << "\nQuick Sort: ";

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}