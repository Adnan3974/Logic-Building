#include <iostream>
using namespace std;

enum class WeekDay
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    WeekDay today = WeekDay::Monday;
    switch (today)
    {
    case WeekDay::Monday:
        cout << "WeekDay" << endl;
        break;
    case WeekDay::Tuesday:
        cout << "WeekDay" << endl;
        break;
    case WeekDay::Wednesday:
        cout << "WeekDay" << endl;
        break;
    case WeekDay::Thursday:
        cout << "WeekDay" << endl;
        break;
    case WeekDay::Friday:
        cout << "WeekDay" << endl;
        break;
    case WeekDay::Saturday:
        cout << "WeekEnd" << endl;
        break;
    case WeekDay::Sunday:
        cout << "WeekEnd" << endl;
        break;
    }

    return 0;
}