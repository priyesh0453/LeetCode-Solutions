#include <iostream>
using namespace std;

int getMaximumGenerated(int n);

int main(void)
{
    int n;
    cin >> n;
    
    cout << getMaximumGenerated(n);

    return 0;
}

int getMaximumGenerated(int n) 
{
    if(n == 0 || n == 1) return n;

    int dp[(n+1)], i = 2, maxNum = 0;

    dp[0] = 0, dp[1] = 1;

    for(; i <= n; i++)
    {
        dp[i] = ((i % 2) == 0) ? dp[(i / 2)] : dp[(i / 2)] + dp[((i / 2) + 1)];
        maxNum = max(dp[i], maxNum);
    }

    return maxNum;
}