#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> prices, int length);

int main(void)
{
    int n;
    cin >> n;
    
    vector <int> prices(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices, n);

    return 0;
}

int maxProfit(vector<int> prices, int length) 
{
    int maxProfit = 0, i = 0, buyPrice = INT_MAX;

    for(; i < length; i++)
    {
        if(prices[i] < buyPrice)
        {
            buyPrice = prices[i];
        }
        else if(maxProfit < prices[i] - buyPrice)
        {
            maxProfit = prices[i] - buyPrice;
        }
    }
        
    return maxProfit;
}