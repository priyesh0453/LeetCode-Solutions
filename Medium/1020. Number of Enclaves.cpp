#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numEnclaves(vector<vector<int>>& grid, int m, int n);

int main()
{
    int m, n, i = 0, j;
    cin >> m >> n;
    
    vector <vector <int>> grid(m, vector <int> (n));
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    cout << numEnclaves(grid, m, n);

    return 0;
}

int numEnclaves(vector<vector<int>>& grid, int m, int n)
{
    int noOfLands = 0, noOfWalkLands = 0, i = 0, j, tempRow, tempCol, delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1}, nRow, nCol; 
    vector <vector <int>> visited (m, vector <int> (n, 0));
    queue <pair <int, int>> temp;
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == 1) noOfLands++;
            if(i == 0 || j == 0 || i == (m - 1) || j == (n - 1))
            {
                if(grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    temp.push({i, j});
                    noOfWalkLands++;
                }
            }
        }
    }
    
    while(!temp.empty())
    {
        tempRow = temp.front().first;
        tempCol = temp.front().second;
        
        temp.pop();
        
        for(i = 0; i < 4; i++)
        {
            nRow = tempRow + delRow[i];
            nCol = tempCol + delCol[i];
            
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0)
            {
                visited[nRow][nCol] = 1;
                temp.push({nRow, nCol});
                noOfWalkLands++;
            }
        }
    }
    
    return (noOfLands - noOfWalkLands);    
}