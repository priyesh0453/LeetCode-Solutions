#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int calcMinTurns(string& s, vector <vector <int>>& dp, int start, int end);
int strangePrinter(string s); 


int main()
{
    string s;
    cin >> s;
    
    cout << strangePrinter(s);
}

int strangePrinter(string s) 
{
    int length = s.length();
    vector <vector <int>> dp(length, vector <int> (length, -1));

    return calcMinTurns(s, dp, 0, (length - 1));
}

int calcMinTurns(string& s, vector <vector <int>>& dp, int start, int end)
{
    if(start == end) return 1;
    if(dp[start][end] != -1) return dp[start][end];

    int minTurns = INT_MAX, i = start;

    for(; i < end; i++)
    {
        minTurns = min(minTurns, (calcMinTurns(s, dp, start, i) + calcMinTurns(s, dp, (i + 1), end)));
    }

    dp[start][end] = s[start] != s[end] ? minTurns : (minTurns - 1);

    return dp[start][end];
}