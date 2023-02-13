#include <iostream>
#include <cstring>
using namespace std;

const int max_length = 301;
int maximalSquare(int matrix[][max_length], int m, int n);

int main()
{
    int m, n, i = 0, j;
    cin >> m;
    cin >> n;
    
    int matrix[m][max_length];
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    cout << maximalSquare(matrix, m, n);

    return 0;
}

int maximalSquare(int matrix[][max_length], int m, int n) 
{
    if(m == 0 || n == 0) return 0;
        
    int dp[m][n], i = 0, j, max_size = 0;
    memset(dp, 0, sizeof(dp));

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 || j == 0 || matrix[i][j] == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else
            {
                dp[i][j] = (min(dp[(i - 1)][j], min(dp[(i - 1)][(j - 1)], dp[i][(j - 1)])) + 1);
            }
                
            max_size = max(max_size, dp[i][j]);
        } 
    }

    return (max_size * max_size);
}