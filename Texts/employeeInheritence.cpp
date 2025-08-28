#include <iostream>
using namespace std;

class Hourly
{
    string name;
    string address;
    string phoneNumber;
    string socialSecurityNumber;
    double hoursWorked;
    double hourlyPayRate;

public:
    Hourly(string n = "", string a = "", string ph = "", string ssn = "", double hourly = 0, double h)
    {
        name = n;
        address = a;
        phoneNumber = ph;
        socialSecurityNumber = ssn;
        hourlyPayRate = hourly;
        hoursWorked = h;
    }

    void addHours(double hrs)
    {
        if (hrs > 0)
        {
            hoursWorked += hrs;
        }
    }

    double pay()
    {
        double payment = hoursWorked * hourlyPayRate;
        hoursWorked = 0; // reset hours after payment
        return payment;
    }

    string toString()
    {
        cout << "Name: " << name << "\n"
             << "Address: " << address << "\n"
             << "Phone: " << phoneNumber << "\n"
             << "SSN: " << socialSecurityNumber << "\n"
             << "Hours worked: " << hoursWorked << "\n"
             << "Hourly payment rate: " << hourlyPayRate;
    }

    string getName()
    {
        return name;
    }

    void setName(string n)
    {
        name = n;
    }
};

class Commission : public Hourly
{
    double totalSales;
    double commissionRate;

public:
    Commission(const string n, const string add, const string ph, const string ssn, double hw, double hp, double total, double rate) : Hourly(n, add, ph, ssn)
    {
        totalSales = total;
        commissionRate = rate;
    };
};

int main()
{

    return 0;
}