#include <iostream>
using namespace std;

void DisplayMainMenu();
void BasicOperationsMenu();

int Add(int, int);
int Subtract(int, int);
int Multiply(int, int);
double Divide(int, int);

void AdvancedOperationsMenu();

int Power(int, int);
int Square(int);
double Average(int, int);

void ConversionsMenu();

void DecToBin(int);
void BinToDec(int);
double Temperature(double);

int main()
{
	DisplayMainMenu();
	return 0;
}

void DisplayMainMenu()
{

	cout << "\n=== Calculator ===\n"
		 << "1. Basic Operations\n"
		 << "2. Advanced Operations\n"
		 << "3. Number Conversions\n"
		 << "4. Exit\n";
	cout << "Enter choice: ";
	int choice;
	cin >> choice;

	while (choice < 1 || choice > 4)
	{
		cout << "Invalid choice!\nRe-Enter: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		BasicOperationsMenu();
		break;
	case 2:
		AdvancedOperationsMenu();
		break;
	case 3:
		ConversionsMenu();
		break;
	case 4:
		return;
	}
}

void BasicOperationsMenu()
{

	cout << "=== Basic Operations ===\n"
		 << "1. Addition\n"
		 << "2. Subtraction\n"
		 << "3. Multiplication\n"
		 << "4. Division\n"
		 << "5. Back to Main Menu\n";

	int choice;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice < 1 || choice > 5)
	{
		cout << "Invalid choice! Re-Enter: ";
		cin >> choice;
	}

	cout << "Enter No. 1: ";
	int n1, n2;
	cin >> n1;
	cout << "Enter No. 2: ";
	cin >> n2;

	switch (choice)
	{
	case 1:
		cout << "Adding: " << Add(n1, n2) << endl;
		DisplayMainMenu();
		break;
	case 2:
		cout << "Subtracting: " << Subtract(n1, n2) << endl;
		DisplayMainMenu();
		break;
	case 3:
		cout << "Multiply: " << Multiply(n1, n2) << endl;
		DisplayMainMenu();
		break;
	case 4:
		cout << "Divide: " << Divide(n1, n2) << endl;
		DisplayMainMenu();
		break;
	case 5:
		DisplayMainMenu();
		break;
	default:
		cout << "Invalid choice\n";
	}
}

// === Basic Functions ===
int Add(int n1, int n2)
{
	return n1 + n2;
}

int Subtract(int n1, int n2)
{
	return n1 - n2;
}

int Multiply(int n1, int n2)
{
	return n1 * n2;
}

double Divide(int n1, int n2)
{
	return n1 / n2;
}

void AdvancedOperationsMenu()
{

	cout << "=== Advanced Operations ===\n"
		 << "1. Power\n"
		 << "2. Square of a Number\n"
		 << "3. Average\n"
		 << "4. Back to Main Menu\n";

	cout << "Enter choice: ";
	int choice;
	cin >> choice;

	while (choice < 1 || choice > 4)
	{
		cout << "Invalid choice! Re-Enter: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
	{
		cout << "Enter No. 1: ";
		int n1, n2;
		cin >> n1;
		cout << "Enter No. 2: ";
		cin >> n2;
		cout << "Power of " << n1 << " upto " << n2 << " is: " << Power(n1, n2);
		DisplayMainMenu();
	}
	break;

	case 2:
	{
		cout << "Enter No";
		int n;
		cout << "Square of " << n << " is " << Square(n);
		DisplayMainMenu();
	}
	break;

	case 3:
	{
		cout << "Enter No. 1: ";
		int n1, n2;
		cin >> n1;
		cout << "Enter No. 2: ";
		cin >> n2;
		cout << "Average of " << n1 << " and " << n2 << " is: " << Average(n1, n2);
		DisplayMainMenu();
	}
	break;

	case 4:
		DisplayMainMenu();
		break;
	default:
		cout << "Invalid choice";
	}
}

int Power(int n1, int n2)
{
	int result = 1;
	for (int i = 1; i <= n2; i++)
	{
		result *= n1;
	}

	return result;
}

int Square(int n)
{
	return n * n;
}

double Average(int n1, int n2)
{
	return (n1 + n2) / 2;
}

void ConversionsMenu()
{

	cout << "=== Number Conversions ===\n"
		 << "1. Decimal to Binary\n"
		 << "2. Binary to Decimal\n"
		 << "3. Temperature (C to F)\n"
		 << "4. Back to Main Menu\n";

	int choice;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice < 1 || choice > 4)
	{
		cout << "Invalid! Re-Enter: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
	{
		cout << "Enter Dec: ";
		int n;
		cin >> n;
		cout << n << "From Dec to Bin: ";
		DecToBin(n);
		DisplayMainMenu();
	}
	break;

	case 2:
	{
		cout << "Enter Bin: ";
		int n;
		cin >> n;
		cout << n << "From Bin to Dec: ";
		BinToDec(n);
		DisplayMainMenu();
	}
	break;

	case 3:
	{
		cout << "Enter Temperature (C*): ";
		int n;
		cin >> n;
		cout << n << "From C* to F*: " << Temperature(n) << endl;
		DisplayMainMenu();
	}
	break;

	case 4:
		DisplayMainMenu();
		break;

	default:
		cout << "Invalid choice";
	}
}

void DecToBin(int n)
{
	if (n == 0)
		return;
	DecToBin(n / 2);
	cout << (n % 2);
}

void BinToDec(int n)
{
	// Logic left
	cout << "Sorry! Request coudn't be proceed\n";
}

double Temperature(double c)
{
	return (9 / 5 * c + 32);
}
