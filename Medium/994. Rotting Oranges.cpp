#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid, int m, int n);

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
    
    cout << orangesRotting(grid, m, n);

    return 0;
}

int orangesRotting(vector<vector<int>>& grid, int m, int n) 
{
    int minTime = 0, i = 0, j, noOfFresh = 0, noOfNewRot = 0, tempRow, tempCol, tempTime, diffRow[] = {-1, 0, 1, 0}, diffCol[] = {0, 1, 0, -1}, nRow, nCol;
    vector <vector <int>> visited (m, vector <int> (n, 0));
    queue <pair <pair <int, int>, int>> temp; 
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == 1) noOfFresh++;
            if(grid[i][j] == 2)
            {
                temp.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }
    
    while(!temp.empty())
    {
        tempTime = temp.front().second;
        tempRow = temp.front().first.first;
        tempCol = temp.front().first.second;
        
        temp.pop();
        
        minTime = max(minTime, tempTime);
        
        for(i = 0; i < 4; i++)
        {
            nRow = tempRow + diffRow[i];
            nCol = tempCol + diffCol[i];
            
            if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1)
            {
                visited[nRow][nCol] = 2;
                temp.push({{nRow, nCol}, (tempTime + 1)});
                
                noOfNewRot++;
            }
        }
        
        
    }
    
    if(noOfNewRot != noOfFresh) return -1;
    
    return minTime;    
}