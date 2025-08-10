#include <iostream>
#include "NumberConversion.h"
using namespace std;
// Constraint: n <= 9999

string Number::convertedNumber(int n)
{
    if (n == 0)
        return "zero";

    string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // first empty for indexing
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}; // first empty for indexing

    string result;

    if (n >= 1000)
    {
        int thousands = n / 1000;
        result += units[thousands] + " thousand";
        n %= 1000;
        if (n > 0)
            result += " ";
    }

    if (n >= 100)
    {
        int hundreds = n / 100;
        result += units[hundreds] + " hundred";
        n %= 100;
        if (n > 0)
            result += " ";
    }

    if (n >= 20)
    {
        int ten = n / 10;
        result += tens[ten];
        n %= 10;
        if (n > 0)
            result += " " + units[n];
    }
    else if (n >= 10)
    {
        result += teens[n - 10];
    }
    else if (n > 0)
    {
        result += units[n];
    }

    return result;
}

int main()
{
    while (true)
    {
        cout << "Enter Number (0-9999): ";
        int n;
        cin >> n;
        while (n < 0 || n > 9999)
        {
            cout << "Invalid Number! Re-Enter (0-9999): ";
            cin >> n;
        }

        Number num;
        cout << num.convertedNumber(n) << endl;

        cout << "Do you wanna continue (Y/N) ?";
        char ch;
        cin >> ws;
        cin.get(ch);
        ch = toupper(ch);
        while (ch != 'Y' && ch != 'N')
        {
            cout << "Invalid input! Re-Enter: ";
            cin.get(ch);
        }
        if (ch == 'N')
            break;
    }
}