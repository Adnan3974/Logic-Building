#include <iostream>
#include <vector>
using namespace std;
/*
2. Lottery Winners
A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit
“lucky” combinations. Write a program that initializes an array or a vector with
these numbers and then lets the player enter this week’s winning 5-digit number.
The program should perform a linear search through the list of the player’s numbers
and report whether or not one of the tickets is a winner this week. Here are the
numbers:
13579
62483
26791
77777
26792
79422
33445
85647
55555
93121
*/

int main()
{
    // Linear Search
    vector<int> vec1 = {13579, 62483, 26791, 77777, 26792, 79422, 33445, 85647, 55555, 93121};
    char flag = 'Y';
    // Sorting the vector in ascending order for bubble sort
    for (int i = 0; i < vec1.size() - 1; ++i)
    {
        for (int j = i + 1; j < vec1.size(); ++j)
        {
            if (vec1[j] < vec1[i])
            { // Ascending order
                int temp = vec1[i];
                vec1[i] = vec1[j];
                vec1[j] = temp;
            }
        }
    }

    while (flag == 'y' || flag == 'Y')
    {
        cout << "Enter lucky number: ";
        int n;
        cin >> n;
        bool found = false;
        for (int i = 0; i < vec1.size(); ++i)
        {
            if (n == vec1[i])
            {
                found = true;
            }
        }
        if (found)
        {
            cout << "Winner\n";
        }
        else
        {
            cout << "Ohh Wrong Guess" << endl;
        }
        found = false; // Reset found for binary search

        int middle;
        int start = 0, position = -1;
        int end = vec1.size() - 1;

        while (!found && start <= end)
        {
            middle = (start + end) / 2;

            if (n == vec1[middle])
            {
                found = true;
                position = middle;
                break;
            }

            else if (vec1[middle] < n)
                start = middle + 1; // Element is in upper half
            else
                end = middle - 1; // Element is in lower half
        }
        if (found)
        {
            cout << "Element found on " << position;
        }
        else
        {
            cout << "!Found";
        }
        cout << "\nDo you want to continue Y/N" << endl;
        cin >> flag;
    }
    return 0;
}
