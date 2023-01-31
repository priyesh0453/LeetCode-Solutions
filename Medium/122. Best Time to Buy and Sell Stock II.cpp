#include <iostream>
#include <climits>
using namespace std;

int maxProfit(int prices[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int prices[size];
    
    for(; i < size; i++)
    {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices, size);

    return 0;
}

int maxProfit(int prices[], int size) 
{
    int profit = 0, i = 0, buyPrice = INT_MAX, maxProfit = 0;

    for(; i < size; i++)
    {
        if(prices[i] < buyPrice)
        {
            buyPrice = prices[i];
        }
        else if(profit < prices[i] - buyPrice)
        {
            profit = prices[i] - buyPrice;
            maxProfit += profit;
            profit = 0;
            buyPrice = prices[i];
        }
    }
    
    return maxProfit;     
}