#include <iostream>
using namespace std;

int fib(int n);

int main()
{
    int n;
    cin >> n;
    
    cout << fib(n);

    return 0;
}

int fib(int n) 
{
    int dp[(n + 1)], i = 2;

    dp[0] = 0, dp[1] = 1;

    for(; i <= n; i++)
    {
        dp[i] = dp[(i - 1)] + dp[(i - 2)];
    } 

    return dp[n];
}