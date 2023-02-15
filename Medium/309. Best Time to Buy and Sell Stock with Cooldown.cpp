#include <iostream>
using namespace std;

int maxProfit(int prices[], int length);

int main()
{
    int length, i = 0;
    cin >> length;
    
    int prices[length];
    
    for(; i < length; i++)
    {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices, length);

    return 0;
}

int maxProfit(int prices[], int length) 
{
    if(length == 1) return 0;
    if(length == 2) return (prices[1] > prices[0] ? (prices[1] - prices[0]) : 0);

    int dp[length][2], i = 2;

    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(0, (dp[0][1] + prices[1]));
    dp[1][1] = max(dp[0][1], -prices[1]);

    for(; i < length; i++)
    {
        dp[i][0] = max((dp[(i - 1)][1] + prices[i]), dp[(i - 1)][0]);   //sold or no action
        dp[i][1] = max((dp[(i - 2)][0] - prices[i]), dp[(i - 1)][1]);   //buying or carrying forward
    }

    return dp[(length - 1)][0];
}