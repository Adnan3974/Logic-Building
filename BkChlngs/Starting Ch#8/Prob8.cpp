#include <iostream>
using namespace std;

int Bubble(int arr[], int size, int n)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] > arr[i])
            { // Descending order
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int start = 0, count = 0, end = size - 1;
    bool found = false;
    while (!found && start <= end)
    {
        int middle = (start + end) / 2;
        if (arr[middle] == n)
        {
            found = true;
            count++;
        }
        else if (arr[middle] > n)
        {
            end = middle - 1;
            count++;
        }
        else
        {
            start = middle + 1;
            count++;
        }
    }
    return count;
}

int Linear(int arr[], int size, int n)
{
    cout << "No of Searches for Bubble search " << Bubble(arr, size, n) << endl;
    int Count = 0;
    bool found = false;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == n)
        {
            found = true;
            Count++;
        }
        Count++;
    }
    return Count;
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 54, 65, 76, 78, 23, 1, 3, 4, 7, 87, 89, 76, 34, 12, 3, 76};
    cout << "Enter No to search: ";
    int n;
    cin >> n;
    cout << "No of Linear searches: " << Linear(arr, 20, n);
    return 0;
}