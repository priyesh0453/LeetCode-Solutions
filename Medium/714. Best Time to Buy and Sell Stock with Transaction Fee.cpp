#include <iostream>
using namespace std;

int maxProfit(int prices[], int length, int fee);

int main()
{
    int length, fee, i = 0;
    cin >> length;
    cin >> fee;
    
    int prices[length];
    
    for(; i < length; i++)
    {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices, length, fee);

    return 0;
}

int maxProfit(int prices[], int length, int fee) 
{
    if(length == 1) return 0;
    if(length == 2) return (prices[1] > prices[0] ? (prices[1] - prices[0] - fee) : 0);

    int dp[length][2], i = 1;

    dp[0][0] = 0;
    dp[0][1] = -prices[0] - fee;
    
    for(; i < length; i++)
    {
        dp[i][0] = max((dp[(i - 1)][1] + prices[i]), dp[(i - 1)][0]);   //sold or carrying forward or no action
        dp[i][1] = max((dp[(i - 1)][0] - prices[i] - fee), dp[(i - 1)][1]);   //buying or carrying forward
    }

    return dp[(length - 1)][0];
}