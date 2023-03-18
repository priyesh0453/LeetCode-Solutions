#include <iostream>
using namespace std;

int coinChange(int coins[], int noOfDistinctCoins, int amount);

int main(void)
{
    int noOfDistinctCoins, i = 0, amount;
    cin >> amount;
    cin >> noOfDistinctCoins;
    
    int coins[noOfDistinctCoins];
    
    for(; i < noOfDistinctCoins; i++)
    {
        cin >> coins[i];
    }
    
    cout << coinChange(coins, noOfDistinctCoins, amount);
}

int coinChange(int coins[], int noOfDistinctCoins, int amount) 
{
    if(amount == 0) return 0;

    int i = 1, j;
    unsigned int dp[(amount + 1)];
        
    dp[0] = 0;

    for(; i <= amount; i++)
    {
        dp[i] = (amount + 1);

        for(j = 0; j < noOfDistinctCoins; j++)
        {
            if(i >= coins[j])
            {
                dp[i] = min(dp[i], (dp[(i - coins[j])] + 1));
            }
        }
    }

    return dp[amount] > amount ? - 1 : dp[amount];
}