#include <iostream>
using namespace std;

double powerCalc(double x, int n);

int main()
{
    double x;
    int n;
    
    cin >> x >> n;
    
    if(n < 0) x = (1 / x);
    
    cout << powerCalc(x, n);
}

double powerCalc(double x, int n)
{
    if(n == 0) return 1.0;
    if(n == 1) return x;

    double power = powerCalc(x, (n / 2));
    power *= power;

    if(n % 2 != 0) power *= x;

    return power;
}