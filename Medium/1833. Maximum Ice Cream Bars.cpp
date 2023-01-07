#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector <int> costs, int noOfBars, int coins) ;

int main()
{
    vector <int> costs;
    int i = 0, var, coins, noOfBars;
    
    cin >> noOfBars;
    
    for(; i < noOfBars; i++)
    {
        cin >> var;
        costs.push_back(var);
    }
    
    cin >> coins;
    
    cout << maxIceCream(costs, noOfBars, coins);

    return 0;
}

int maxIceCream(vector <int> costs, int noOfBars, int coins) 
{
    sort(costs.begin(), costs.end());
        
    int i = 0,  maxBarsBought = 0;

    if(coins < costs[i]) return 0;

    while(coins >= costs[i])
    {
        coins -= costs[i];
        maxBarsBought++;
        i++;
            
        if(i == noOfBars) break;
    }

    return maxBarsBought;
}