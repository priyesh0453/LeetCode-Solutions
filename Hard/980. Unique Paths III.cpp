#include <iostream>
#include <vector>
using namespace std;

int uniquePathsIII(vector<vector<int>>& grid, int m, int n);
void calcWays(vector <vector <int>>& grid, int m, int n, int startX, int startY, int& noOfEmpties, int currentCount, int& noOfWays);

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
    
    cout << uniquePathsIII(grid, m, n);

    return 0;
}

int uniquePathsIII(vector<vector<int>>& grid, int m, int n) 
{
    int i = 0, j, noOfEmpties = 0, startX, startY, noOfWays = 0, currentCount = 0;

    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == 0) noOfEmpties++;
            else if(grid[i][j] == 1) startX = i, startY = j;
        }
    }  

    calcWays(grid, m, n, startX, startY, noOfEmpties, currentCount, noOfWays);

    return noOfWays;
}

void calcWays(vector <vector <int>>& grid, int m, int n, int startX, int startY, int& noOfEmpties, int currentCount, int& noOfWays)
{
    if(startX < 0 || startX >= m || startY < 0 || startY >= n || grid[startX][startY] == -1) return;
    if(grid[startX][startY] == 2)
    {
        if((currentCount - 1) == noOfEmpties) noOfWays++;
        return;
    }

    grid[startX][startY] = -1;
    vector <pair<int, int>> neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int tempX, tempY;

    for(auto iterator : neighbours)
    {
        tempX = startX + iterator.first;
        tempY = startY + iterator.second;

        if(tempX >= 0 && tempX < m && tempY >= 0 && tempY < n) calcWays(grid, m, n, tempX, tempY, noOfEmpties, (currentCount + 1), noOfWays);
    }

    grid[startX][startY] = 0;

}