#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int max_Length = 101;
int minFallingPathSum(int matrix[][max_Length], int length);

int main()
{
    int length, i = 0, j;
    cin >> length;
    
    int matrix[max_Length][max_Length];
    memset(matrix, 0, sizeof(matrix));
    
    for(; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    cout << minFallingPathSum(matrix, length);

    return 0;
}

int minFallingPathSum(int matrix[][max_Length], int length) 
{
    int minSum = 0, dp[length][length], i = 0, j, temp, first_index, second_index, third_index;
    memset(dp, 0, sizeof(dp));

    for(; i < length; i++)
    {
        temp = INT_MAX;

        for(j = 0; j < length; j++)
        {
            first_index = second_index = third_index = matrix[i][j];

            if(i == 0)
            {
                dp[i][j] = matrix[i][j];
                temp = min(temp, dp[i][j]);
                continue;
            }
            
            second_index += dp[(i - 1)][j];

            if(j >= 1) first_index += dp[(i - 1)][(j - 1)];
            else first_index = INT_MAX;

            if(j <= (length - 2)) third_index += dp[(i - 1)][(j + 1)];
            else third_index = INT_MAX;

            dp[i][j] += min(first_index, min(second_index, third_index));
            temp = min(temp, dp[i][j]);
        }

        minSum = temp;
    }

    return minSum;        
}