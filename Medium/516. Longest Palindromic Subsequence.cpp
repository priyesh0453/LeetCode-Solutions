#include <iostream>
using namespace std;

int longestPalindromeSubseq(string s);

int main()
{
    string s;
    cin >> s;
    
    
    cout << longestPalindromeSubseq(s);

    return 0;
}

int longestPalindromeSubseq(string s) 
{
    int length = s.length(), dp[length][length], i = (length - 1), j;

    for(; i >= 0; i--)
    {
        dp[i][i] = 1;

        for(j = (i + 1); j < length; j++)
        {
            if(s[i] == s[j])
            {
                dp[i][j] = 2;
                if(i < (j - 1))
                {
                    dp[i][j] += dp[(i + 1)][(j - 1)];
                }
            }
            else
            {
                dp[i][j] = max(dp[(i + 1)][j], dp[i][(j - 1)]);
            }
        }
    }

    return dp[0][(length - 1)];  
}