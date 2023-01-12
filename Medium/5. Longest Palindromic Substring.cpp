#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s);

int main()
{
    string s;
    cin >> s;
    
    cout << longestPalindrome(s);

    return 0;
}

string longestPalindrome(string s) 
{    
    int length = s.size(), maxLength = 0, i, j, difference = 0, counter;
    vector<vector<int>> dp(length, vector<int>(length, 0));
    string longestPalindrome;

    for(; difference < length; difference++)
    {
        for(i = 0, j = (difference + i); j < length; j++)
        {
            if(i == j) dp[i][j] = 1;
            else if(difference == 1) dp[i][j] = (s[i] == s[j]) ? 2 : 0;
            else
            {
                if(dp[i+1][j-1] != 0 && s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            }

            if(dp[i][j] != 0)
            {
                counter = (j - i + 1);
                if(counter > maxLength)
                {
                    maxLength = counter;
                    longestPalindrome = s.substr(i, counter);
                }
            }
            i++;
        }           
    }
    return longestPalindrome;
}