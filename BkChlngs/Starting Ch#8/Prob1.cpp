#include <iostream>
#include <fstream>
using namespace std;
/*
1. Charge Account Validation
Write a program that lets the user enter a charge account number. The program should
determine if the number is valid by checking for it in the following list:
5658845
8080152
1005231
4520125
4562555
6545231
7895122
5552012
3852085
8777541
5050552
7576651
8451277
7825877
7881200
1302850
1250255
4581002
The list of numbers above should be initialized in a single-dimensional array. A simple
linear search should be used to locate the number entered by the user. If the user enters
a number that is in the array, the program should display a message saying that the
number is valid. If the user enters a number that is not in the array, the program should
display a message indicating that the number is invalid.
*/

int main()
{
    ofstream outFile("1.txt");
    if (!outFile)
    {
        cout << "Error occured in opening the  File";
        return 1;
    }

    int a;
    cout << "Enter  the list of No.s";
    for (int i = 0; i < 10; ++i)
    {
        cin >> a;
        outFile << a << endl;
    }
    outFile.close();
    cout << "Enter the particular number to search in the list: " << endl;
    string n;
    cin >> n;
    string line;
    bool found = false;
    ifstream inFile("1.txt");
    while (getline(inFile, line))
    {
        if (n == line)
        {
            found = true;
        }
    }
    if (found)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "!Found";
    }
    inFile.close();
    return 0;
}

/*
Output: The program will prompt the user to enter a list of numbers and then a specific number to search for. It will check if the number exists in the list and print "Found" or "!Found" accordingly.
Note: The program uses a file to store the list of numbers, which is read later to check for the existence of the entered number.
The user is expected to enter 10 numbers initially, which will be saved in a file named "1.txt". After that, the user can enter a number to search for in that file. If the number exists, it will print "Found"; otherwise, it will print "!Found".
The program uses a simple linear search to find the number in the file.
*/