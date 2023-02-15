#include <iostream>
#include <cstring>
using namespace std;

int nthUglyNumber(int n);

int main()
{
    int n;
    
    cin >> n;
    
    cout << nthUglyNumber(n);

    return 0;
}

int nthUglyNumber(int n) 
{
    if(n <= 6) return n;

    int dp[n], i = 1, L2_index = 0, L3_index = 0, L5_index = 0, mul2, mul3, mul5;
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(; i < n; i++)
    {
        mul2 = dp[L2_index] * 2;
        mul3 = dp[L3_index] * 3;
        mul5 = dp[L5_index] * 5;

        dp[i] = min(mul2, min(mul3, mul5));

        if(dp[i] == mul2) L2_index++;
        if(dp[i] == mul3) L3_index++;
        if(dp[i] == mul5) L5_index++;
    }   

    return dp[(n - 1)];  
}