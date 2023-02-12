#include <iostream>
using namespace std;

const int max_size = 201;
int minPathSum(int grid[][max_size], int m, int n);

int main()
{
    int m, n, i = 0, j;
    cin >> m;
    cin >> n;
    
    int grid[m][max_size];
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    cout << minPathSum(grid, m, n);

    return 0;
}

int minPathSum(int grid[][max_size], int m, int n) 
{
    int dp[m][n], i = 0, j;

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 && j != 0) 
            {
                dp[i][j] = grid[i][j] + dp[i][(j - 1)];
            }
            else if(j == 0 && i != 0) 
            {   
                dp[i][j] = grid[i][j] + dp[(i - 1)][j];   
            }             
            else if(i != 0 && j != 0)
            {
                 dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][(j - 1)]);
            }
            else
            {
                dp[i][j] = grid[i][j];
            }
        }
    }
    
    return dp[(m - 1)][(n - 1)];
}