#include <iostream>
using namespace std;

void displayRules()
{
cout << " Welcome to the game of Rock, Paper, "
<< "and Scissors." << endl;
cout << " This is a game for two players. For each "
<< "game, each" << endl;
cout << " player selects one of the objects, Rock, "
<< "Paper or Scissors." << endl;
cout << " The rules for winning the game are: " << endl;
cout << "1. If both players select the same object, it "
<< "is a tie." << endl;
cout << "2. Rock breaks Scissors: So player who selects "
<< "Rock wins." << endl;
cout << "3. Paper covers Rock: So player who selects "
<< "Paper wins." << endl;
cout << "4. Scissors cut Paper: So player who selects "
<< "Scissors wins." << endl << endl;
cout << "Enter R or r to select Rock, P or p to select "
<< "Paper, and S or s to select Scissors." << endl;
}

int main()
{
    int no_of_plays = 0;
    int player1_choice, player2_choice;
    int winCount1 = 0, winCount2 = 0;
    while (true)
    {
        displayRules();
        cout<<"Do you want to play? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
        no_of_plays++;
        for (int i = 1; i < 3; ++i)
        {
            cout << "Player-" << i << "! Enter your choice\n"
                 << "1. Scissors\n"
                 << "2. Paper\n"
                 << "3. Rock\n";
            if (i == 1)
            {
                cin >> player1_choice;
                while (player1_choice < 1 || player1_choice > 2)
                {
                    cout << "Invalid input! Re-Enter: ";
                    cin >> player1_choice;
                }
            }
            else if (i == 2)
            {
                cin >> player2_choice;
                while (player1_choice < 1 || player1_choice > 2)
                {
                    cout << "Invalid input! Re-Enter: ";
                    cin >> player2_choice;
                }
            }
        }
        if (player1_choice == 1 && player2_choice == 2)
        {
            winCount1++;
            cout << "Player 1's choice: Scissors\n";
            cout << "Player 2's choice: Paper\n";
            cout << "Player 1 wins this play!\n";
        }

        else if (player1_choice == 1 && player2_choice == 3)
        {
            winCount2++;
            cout << "Player 1's choice: Scissors\n";
            cout << "Player 2's choice: Rock\n";
            cout << "Player 2 wins this play!\n";
        }

        else if (player2_choice == 1 && player1_choice == 2)
        {
            winCount2++;
            cout << "Player 2's choice: Scissors\n";
            cout << "Player 1's choice: Paper\n";
            cout << "Player 2 wins this play!\n";
        }
        else if (player2_choice == 1 && player1_choice == 3)
        {
            winCount1++;
            cout << "Player 2's choice: Scissors\n";
            cout << "Player 1's choice: Rock\n";
            cout << "Player 1 wins this play!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
    }

    cout << "Thanks for playing!\n";
    cout << "Total plays: " << no_of_plays << endl;
    cout << "Player 1 wins: " << winCount1 << endl;
    cout << "Player 2 wins: " << winCount2 << endl;
    if (winCount1 > winCount2)
        cout << "Player 1 is the winner!\n";
    else if (winCount2 > winCount1)
        cout << "Player 2 is the winner!\n";
    else if (winCount1 == winCount2)
        cout << "It's is a Tie!\n";
    return 0;
}
