#include <iostream>
#include <iomanip>
using namespace std;

void initializeSeats(char[][6], int);
void printSeating(char[][6], int);
void reserveSeat(char[][6], int, int, int);

int main()
{
    char seats[13][6];
    initializeSeats(seats, 6);
    printSeating(seats, 6);

    cout << left << setw(20) << "Class" << setw(15) << "Price" << endl;
    cout << left << setw(20) << "Economy Class" << setw(15) << "40,000" << endl;
    cout << left << setw(20) << "Business Class" << setw(15) << "85,000" << endl;
    cout << left << setw(20) << "First Class" << setw(15) << "150,000" << endl;

    while (true)
    {
        cout << "1. Seat Reservation\n"
             << "2. View seating plan\n"
             << "3. Quit!\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter row (1-13): ";
            int row;
            cin >> row;

            while (row < 1 || row > 13)
            {
                cout << "Invalid input! Re-Enter: ";
                cin >> row;
            }

            cout << "Enter col(A-F): ";
            char ch;
            cin >> ch;
            ch = toupper(ch);
            while (ch < 'A' || ch > 'F')
            {
                cout << "Invalid input! Re-Enter: ";
                cin >> ch;
                ch = toupper(ch);
            }

            int col = ch - 'A' + 1;

            reserveSeat(seats, 6, row, col);
            cout << "Seat reserved successfully!\n";
            printSeating(seats, 6);

            break;
        }
        case 2:
            printSeating(seats, 6);
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

void printSeating(char seats[][6], int cols)
{
    cout << "         A B C D E F" << endl;
    for (int i = 0; i < 13; ++i)
    {
        cout << "Row " << (i < 9 ? " " : "") << i + 1 << "   ";
        for (int j = 0; j < cols; ++j)
        {
            cout << seats[i][j] << " ";
        }
        cout << "\n";
    }
}

void initializeSeats(char seats[][6], int cols)
{
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            seats[i][j] = 'X';
        }
    }
}

void reserveSeat(char seats[][6], int cols, int row, int col)
{
    if (seats[row - 1][col - 1] == '*')
    {
        cout << "Seat already reserved!\n";
        return;
    }
    seats[row - 1][col - 1] = '*';
}