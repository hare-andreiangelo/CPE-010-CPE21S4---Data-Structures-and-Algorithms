#include <iostream>

void merge(int arr[], int left, int middle, int right)
{
    int temp[10];

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++)
    {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
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

    mergeSort(arr, 0, 9);

    std::cout << "\nMerge Sort: ";

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}