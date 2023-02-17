#include <iostream>
using namespace std;

int minDistance(string word1, string word2);

int main()
{
    string word1, word2;
    cin >> word1;
    cin >> word2;
    
    cout << minDistance(word1, word2);

    return 0;
}

int minDistance(string word1, string word2) 
{
    int word1_length = word1.length(), word2_length = word2.length();

    if(word1_length == 0 && word2_length == 0) return 0;
    else if(word1_length == 0 && word2_length != 0) return word2_length;
    else if(word2_length == 0 && word1_length != 0) return word1_length;
    else
    {
        int dp[(word1_length + 1)][(word2_length + 1)], i = 1, j = 0;

        for(; j <= word2_length; j++)
        {
            dp[0][j] = j;
        }

        for(; i <= word1_length; i++)
        {
            dp[i][0] = i;

            for(j = 1; j <= word2_length; j++)
            {
                if(word1[(i - 1)] == word2[j - 1]) dp[i][j] = dp[(i - 1)][(j - 1)];
                else dp[i][j] = min(dp[(i - 1)][(j - 1)], min(dp[(i - 1)][j], dp[i][(j - 1)])) + 1;
            }
        }

        return dp[word1_length][word2_length];
    }
}