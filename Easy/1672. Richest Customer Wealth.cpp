#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts, int m, int n);

int main()
{
    int m, n, i = 0, j;
    cin >> m >> n;
    
    vector <vector <int>> accounts (m, vector <int> (n));
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> accounts[i][j];
        }
    }
    
    cout << maximumWealth(accounts, m, n);

    return 0;
}

int maximumWealth(vector<vector<int>>& accounts, int m, int n) 
{
    int i = 0, j, maxWealth = 0, tempSum = 0;

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            tempSum += accounts[i][j];
        }
        maxWealth = max(maxWealth, tempSum);
        tempSum = 0;
    }    

    return maxWealth;
}