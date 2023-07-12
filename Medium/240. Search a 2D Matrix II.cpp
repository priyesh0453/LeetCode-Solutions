#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target, int m, int n);

int main()
{
    int target, m, n, i = 0, j;
    cin >> target >> m >> n;
    
    vector <vector <int>> matrix(m, vector <int> (n));
    
    for(; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    cout << searchMatrix(matrix, target, m, n);

    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int m, int n) 
{
    int left_Index = 0, right_Index = (n - 1), mid_Index;

    while(left_Index < m && right_Index >= 0)
    {
        if(matrix[left_Index][right_Index] == target) return true;

        if(matrix[left_Index][right_Index] > target) right_Index--;
        else left_Index++;
    }    

    return false;
}