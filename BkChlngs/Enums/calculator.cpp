#include <iostream>
using namespace std;

/*
2. Simple Calculator
Enum: ADD, SUBTRACT, MULTIPLY, DIVIDE
Task: Perform operations based on enum input.
🔎 Shows cleaner switch-case with enums
*/
enum calc
{
    ADD,
    SUB,
    MUL,
    DIV
};

double result(double n1, double n2, calc operation)
{
    switch (operation)
    {
    case ADD:
        return n1 + n2;
        break;
    case SUB:
        return n1 - n2;
        break;
    case MUL:
        return n1 * n2;
        break;
    case DIV:
        if (n2 != 0)
            return n1 / n2;
        else
            cout << "Can't divide by zero\n";
        return 0;
    default:
        cout << "Invaid Operation!";
        return 0;
    }
}

int main()
{
    calc operation;
    cout << "Enter two numbers: ";
    int n1, n2;
    cin >> n1 >> n2;
    cout << "Enter operation to perform:\n0. Add\n1. Sub\n2. Mul\n3. Div\n";
    int input;
    cin >> input;
    while (input < 0 || input > 3)
    {
        cout << "Invalid input!\n";
        cin >> input;
    }
    operation = static_cast<calc>(input);
    cout << "Result: " << result(n1, n2, operation);
    return 0;
}