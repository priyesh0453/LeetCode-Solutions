#include <iostream>
#include <vector>
using namespace std;

void generate(int numRows);
void print(vector <vector<int>> &dp, int numRows);

int main(void)
{
    int numRows;
    cin >> numRows;
    
    if(numRows > 0) generate(numRows);
    else cout << "Invalid Input!" << endl;

    return 0;
}

void generate(int numRows) 
{
    vector <vector<int>> dp(numRows);

    int i = 0, j;

    for(; i < numRows; i++)
    {
        dp[i].resize((i+1));

        dp[i][i] = 1;
        dp[i][0] = 1;
    
        for(j = 1; j < i; j++)
        {
            dp[i][j] = dp[(i - 1)][(j - 1)] + dp[(i - 1)][j];
        }
    }
    
    print(dp, numRows);
}

void print(vector <vector<int>> &dp, int numRows)
{
    cout << "[[";
    
    for(int i = 0 ; i < numRows; i++)
    {
        if(numRows != 1) cout << "\b[";
        
        for(int j = 0; j <= i; j++)
        {
            cout << dp[i][j] << ",";
        }
        cout << "\b],";
    }
    
    cout << "\b]" << endl;
}