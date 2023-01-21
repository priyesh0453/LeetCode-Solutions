#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(int cost[], int length);

int main(void)
{
    int n, i = 0;
    cin >> n;
    
    int cost[n];
    
    for(; i < n; i++)
    {
        cin >> cost[i];
    }
    
    cout << minCostClimbingStairs(cost, n);

    return 0;
}

int minCostClimbingStairs(int cost[], int length) 
{
    if(length == 2) return min(cost[0], cost[1]);

    int i = (length - 1), dp_1 = 0, dp_2 = 0, dp_i;

    for(; i >= 0; i--)
    {
        dp_i = cost[i] + min(dp_1, dp_2);
        dp_2 = dp_1;
        dp_1 = dp_i;
    }

    return min(dp_1, dp_2);
}