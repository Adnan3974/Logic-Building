#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.0, 10.000);
}
