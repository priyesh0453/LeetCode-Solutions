#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<string>>& result);
bool checkValidity(vector <string>& tempRows, int row, int col, int n);
void solveNQueens(vector <string>& tempRows, vector <vector <string>>& result, int n, int col);

int main()
{
    int n, i = 0;
    cin >> n;
    
    vector <vector <string>> result;
    vector <string> tempRows(n);
    string s(n, '.');

    for(; i < n; i++)
    {
        tempRows[i] = s;
    }
    
    solveNQueens(tempRows, result, n, 0); 
    display(result);
    
    return 0;
}

void solveNQueens(vector <string>& tempRows, vector <vector <string>>& result, int n, int col)
{
    if(col == n)
    {
        result.push_back(tempRows);
        return;
    }

    int row = 0;

    for(; row < n; row++)
    {
        if(checkValidity(tempRows, row, col, n))
        {
            tempRows[row][col] = 'Q';
            solveNQueens(tempRows, result, n, (col + 1));
            tempRows[row][col] = '.';
        }
    }
}

bool checkValidity(vector <string>& tempRows, int row, int col, int n)
{
    int tempRow = row, tempCol = col;

    while(row >= 0 && col >= 0)
    {
        if(tempRows[row][col] == 'Q') return false;

        row--;
        col--;
    }

    row = tempRow, col = tempCol;

    while(col >= 0)
    {
        if(tempRows[row][col] == 'Q') return false;
        
        col--;
    }

    row = tempRow, col = tempCol;
    
    while(row < n && col >= 0)
    {
        if(tempRows[row][col] == 'Q') return false;

        row++;
        col--;
    }

    return true;
}

void display(vector<vector<string>>& result)
{
    int i = 0, j, noOfSol = result.size(), n = result[0].size();;

    for(; i < noOfSol; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}