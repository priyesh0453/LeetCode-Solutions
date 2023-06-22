#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double celsius;
    cin >> celsius;
    
    cout << "{" << fixed << setprecision(5) << (celsius + 273.15) << ", " << ((celsius * 1.80) + 32.00) << "}";

    return 0;
}