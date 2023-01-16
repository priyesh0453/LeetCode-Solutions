#include <iostream>
#include <vector>
using namespace std;

void getRow(int rowIndex);
void print(vector <vector<int>> &dp, int noOfRows);

int main(void)
{
    int rowIndex;
    cin >> rowIndex;
    
    if(rowIndex >= 0) getRow(rowIndex);
    else cout << "Invalid Input!" << endl;

    return 0;
}

void getRow(int rowIndex) 
{
    int noOfRows = rowIndex + 1;
    vector <vector<int>> dp(noOfRows);

    int i = 0, j;

    for(; i < noOfRows; i++)
    {
        dp[i].resize((i+1));

        dp[i][i] = 1;
        dp[i][0] = 1;

        for(j = 1; j < i; j++)
        {
            dp[i][j] = dp[(i - 1)][(j - 1)] + dp[(i - 1)][j];
        }
    }

    print(dp, (rowIndex + 1));
}

void print(vector <vector<int>> &dp, int noOfCol)
{
    cout << "[";
    
    for(int i = 0 ; i < noOfCol; i++)
    {
        cout << dp[noOfCol - 1][i] << ",";
    }
    
    cout << "\b]" << endl;
}