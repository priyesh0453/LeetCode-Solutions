#include <iostream>
using namespace std;

int dfs(char grid[][300], int i, int j, int m, int n);
int numIslands(char grid[][300], int m, int n);

int main(void)
{
    int m, n, i = 0, j;
    cin >> m;
    cin >> n;
    
    char grid[m][300];
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    cout << numIslands(grid, m, n);

    return 0;
}

int dfs(char grid[][300], int i, int j, int m, int n)
{
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return 0;

    grid[i][j] = '0';

    dfs(grid, i + 1, j, m, n);
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i, j + 1, m, n);
    dfs(grid, i, j - 1, m, n);
            
    return 1;
}
        
int numIslands(char grid[][300], int m, int n) 
{
    if(m == 0) return 0;

    int i = 0, j, noOfIslands = 0;    

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == '1') noOfIslands += dfs(grid, i, j, m, n);
        }
    }

    return noOfIslands;
}