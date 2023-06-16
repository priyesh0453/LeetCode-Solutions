#include <iostream>
using namespace std;

int countGoodNumbers(long long n);
long long powerCalc(long long x, long long y);

#define MOD 1000000007;

int main()
{
    long long n;
    cin >> n;
    
    cout << countGoodNumbers(n);

    return 0;
}

int countGoodNumbers(long long n) 
{
    long long noOfOddPlaces = (n / 2), noOfEvenPlaces = ((n / 2) + (n % 2));

    return (powerCalc(5, noOfEvenPlaces) * powerCalc(4, noOfOddPlaces)) % MOD;
}

long long powerCalc(long long x, long long y)
{
    if(y == 0) return 1;

    long long power = powerCalc(x, (y / 2));
    power *= power;
    power %= MOD;

    if(y % 2 != 0) power *= x;

    power %= MOD;

    return power;
}