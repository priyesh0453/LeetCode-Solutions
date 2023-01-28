#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int maxSize = 201;
int minimumTotal(int triangle[][maxSize], int size);

int main()
{
    int size, i = 0, j;
    cin >> size;
    
    int triangle[size][maxSize];
    
    for(; i < size; i++)
    {
        for(j = 0; j <= i; j++)
        {
            cin >> triangle[i][j]; 
        }
    }
    
    cout << minimumTotal(triangle, size);

    return 0;
}

int minimumTotal(int triangle[][maxSize], int size) 
{
    if(size == 1) return triangle[0][0];

    int i = 1, sum, minSum = INT_MAX, j;
    vector<vector<int>> dp(size);

    dp[0] = vector<int> (1, triangle[0][0]);

    for(; i < size; i++)
    {
        dp[i] = vector<int>((i + 1), 0);

        for(j = 0; j <= i; j++)
        {
            if(j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if(j == i) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    for(i = 0; i < size; i++)
    {
        minSum = min(minSum, dp[size - 1][i]);
    }   

    return minSum;
}