#include <iostream>
using namespace std;

const int max_size = 101;
int uniquePathsWithObstacles(int obstacleGrid[][max_size], int m, int n);

int main()
{
    int m, n, i = 0, j;
    cin >> m;
    cin >> n;
    
    int obstacleGrid[m][max_size];
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> obstacleGrid[i][j]; 
        }
    }
    
    cout << uniquePathsWithObstacles(obstacleGrid, m, n);

    return 0;
}

int uniquePathsWithObstacles(int obstacleGrid[][max_size], int m, int n) 
{
    if(obstacleGrid[0][0] == 1 || obstacleGrid[(m - 1)][(n - 1)] == 1) return 0;

    int dp[m][n], i = 0, j, left, top;

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else
            {
                left = 0, top = 0;
                if(i != 0) top = dp[(i - 1)][j];
                if(j != 0) left = dp[i][(j - 1)]; 
                
                dp[i][j] = top + left;
            }               
        }
    }

    return dp[(m - 1)][(n - 1)];
}