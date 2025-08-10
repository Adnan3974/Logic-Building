#include <iostream>
using namespace std;

string IntToRoman(int &);
int main()
{
    cout << "Enter integer: ";
    int n;
    cin >> n;
    cout << n << " To Roman: " << IntToRoman(n);
    return 0;
}

string IntToRoman(int &n)
{
    if (n <= 0)
        return "Invalid  Integer";

    string roman = "";

    while (n)
    {
        int count = 0;
        if (n >= 1000)
        {
            while (n >= 1000)
            {
                n -= 1000;
                count++;
            }

            for (int i = 0; i < count; ++i)
            {
                roman += "M";
            }
        }

        else if (n >= 900)
        {
            n -= 900;
            roman += "CM";
        }

        else if (n >= 500)
        {
            n -= 500;
            roman += "D";
        }

        else if (n >= 400)
        {
            roman += "CD";
            n -= 400;
        }

        else if (n >= 100)
        {
            count = 0;
            while (n >= 100)
            {
                n -= 100;
                count++;
            }
            for (int i = 0; i < count; ++i)
            {
                roman += "C";
            }
        }

        else if (n >= 90)
        {
            n -= 90;
            roman += "XC";
        }

        else if (n >= 50)
        {
            n -= 50;
            roman += "L";
        }

        else if (n >= 40)
        {
            n -= 40;
            roman += "XL";
        }

        else if (n >= 10)
        {
            count = 0;
            while (n >= 10)
            {
                n -= 10;
                count++;
            }
            for (int i = 0; i < count; ++i)
            {
                roman += "X";
            }
        }

        switch (n)
        {
        case 1:
            n -= 1;
            roman += "I";
            break;
        case 2:
            n -= 2;
            roman += "II";
            break;
        case 3:
            n -= 3;
            roman += "III";
            break;
        case 4:
            n -= 4;
            roman += "IV";
            break;
        case 5:
            n -= 5;
            roman += "V";
            break;
        case 6:
            n -= 6;
            roman += "VI";
            break;
        case 7:
            n -= 7;
            roman += "VII";
            break;
        case 8:
            n -= 8;
            roman += "VIII";
            break;
        case 9:
            n -= 9;
            roman += "IX";
            break;
        }
    }
    return roman;
}

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol
I
V
X
L
C
D
M
Value
1
5
10
50
100
500
1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written
as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for
four is not IIII. Instead, the number four is written as IV. Because the one is before the five we
subtract it making four. The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/