#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRect(vector <int>& height, int cols);
int maximalRectangle(vector<vector<char>>& matrix, int rows, int cols);

int main()
{
    int rows, cols, i = 0, j;
    cin >> rows >> cols;
    
    vector <vector <char>> matrix(rows, vector <char> (cols));
    
    for(; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    cout << maximalRectangle(matrix, rows, cols);

    return 0;
}

int maximalRectangle(vector<vector<char>>& matrix, int rows, int cols) 
{
    int i = 0, j, tempArea, maxArea = 0;
    vector <int> height(cols, 0);

    for(; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }

        tempArea = largestRect(height, cols);
        maxArea = max(maxArea, tempArea);
    }    

    return maxArea;
}

int largestRect(vector <int>& height, int cols)
{
    int maxA = 0, i = 0, tempHeight, tempWidth;
    stack <int> temp;

    for(; i <= cols; i++)
    {
        while(!temp.empty() && (i == cols || height[temp.top()] > height[i]))
        {
            tempHeight = height[temp.top()];
            
            temp.pop();

            if(temp.empty()) tempWidth = i;
            else tempWidth = i - 1 - temp.top();

            maxA = max(maxA, (tempHeight * tempWidth));
        }

        temp.push(i);
    }

    return maxA;
}