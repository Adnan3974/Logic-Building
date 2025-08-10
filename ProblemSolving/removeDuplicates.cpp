#include <iostream>
using namespace std;
// Removing duplicates from an array

int *removeDuplicates(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int current = arr[i];
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] == current)
                arr[j] = -9999999;
        }
    }
    return arr;
}

int main()
{
    int size = 10;
    int array[size] = {3, 4, 7, 5, 3, 4, 8, 9, 1, 5};

    cout << "Before: ";

    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";

    removeDuplicates(array, size);

    cout << "\nAfter: ";

    for (int i = 0; i < size; ++i)
    {
        if (array[i] == -9999999)
            continue;
        cout << array[i] << " ";
    }
    return 0;
}