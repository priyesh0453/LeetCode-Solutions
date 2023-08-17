#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void updateMatrix(vector <vector <int>>& mat, int m, int n, vector <vector <int>>& nearestDist);

int main()
{
    int m, n, i = 0, j;
    cin >> m >> n;
    
    vector <vector <int>> mat(m, vector <int> (n)), nearestDist(m, vector <int> (n, 0));
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "\n";
    
    updateMatrix(mat, m, n, nearestDist);
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << nearestDist[i][j] << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}

void updateMatrix(vector <vector <int>>& mat, int m, int n, vector <vector <int>>& nearestDist) 
{
    int i = 0, j, tempRow, tempCol, tempDist, rowIndices[] = {-1, 0, 1, 0}, colIndices[] = {0, 1, 0, -1}, row, col;
    vector <vector <int>> visited (m, vector <int> (n, 0));
    queue <pair <pair <int, int>, int>> tempQ;
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j] == 0)
            {
                tempQ.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    } 

    while(!tempQ.empty())
    {
        tempRow = tempQ.front().first.first;
        tempCol = tempQ.front().first.second;
        tempDist = tempQ.front().second;

        tempQ.pop();

        nearestDist[tempRow][tempCol] = tempDist;

        for(i = 0; i < 4; i++)
        {
            row = tempRow + rowIndices[i];
            col = tempCol + colIndices[i];

            if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col])
            {
                visited[row][col] = 1;
                tempQ.push({{row, col}, tempDist + 1});
            }
        }
    }     
}