#include <iostream>
using namespace std;

/*
3. Game Player Role
Enum: WARRIOR, ARCHER, MAGE
Task: Assign attributes (HP, attack) based on role.
🔎 Demonstrates game development use case
*/
enum game
{
    WARRIOR,
    ARCHER,
    MAGE
};

void Assign(game operation)
{
    switch (operation)
    {
    case WARRIOR:
        cout << "Health power: 100\n"
             << "Attack: 80\n";
        break;
    case ARCHER:
        cout << "Health power: 80\n"
             << "Attack: 60\n";
        break;
    case MAGE:
        cout << "Health power: 50\n"
             << "Attack: 80\n";
        break;
    default:
        cout << "Invaid Operation!";
        return;
    }
}

int main()
{
    game role;
    cout << "0. WARRIOR,\n"
         << "1. ARCHER,\n"
         << "2. MAGE\n";
    int choice;
    cin >> choice;

    while (choice < 0 || choice > 2)
    {
        cout << "Invalid choice! Try again:\n";
        cin >> choice;
    }

    role = static_cast<game>(choice);
    Assign(role);
    return 0;
}