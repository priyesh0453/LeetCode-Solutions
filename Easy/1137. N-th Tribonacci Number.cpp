#include <iostream>
using namespace std;

int tribonacci(int n);

int main(void)
{
    int n;
    cin >> n;
    
    cout << tribonacci(n);

    return 0;
}

int tribonacci(int n) 
{
    if(n == 0 || n == 1) return n;
    if(n == 2) return 1;

    int dp[(n + 1)], i = 3;

    dp[0] = 0, dp[1] = 1, dp[2] = 1;

    for(; i <= n; i++)
    {
        dp[i] = dp[(i - 1)] + dp[(i - 2)] + dp[(i - 3)];
    } 

    return dp[n];
}