#include <iostream>
using namespace std;

int mode(int *arr, int size)
{
    int maxCount = 0;
    int maxValue = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (*(arr + i) == *(arr + j))
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxValue = *(arr + i);
        }
    }
    return (maxCount > 1) ? maxValue : -1;
}

int main()
{
    int arr[10];
    cout << "Enter 10 elements in the array: \n";
    for (int i = 0; i < 10; ++i)
    {
        cin >> arr[i];
    }
    cout << "Mode : " << mode(arr, 10) << endl;
}