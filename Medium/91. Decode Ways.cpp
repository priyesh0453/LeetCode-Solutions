#include <iostream>
#include <cstring>
using namespace std;

int numDecodings(string s);

int main()
{
    string s;
    cin >> s;
     
    cout << numDecodings(s);

    return 0;
}

int numDecodings(string s) 
{
    int length = s.length();

    if(length == 1) return (s.at(0) == '0' ? 0 : 1);

    int dp[(length + 2)], singleDigit, doubleDigit = 0, counter = (length - 1), i = counter;
    memset(dp, 0, sizeof(dp));

    dp[(length + 1)] = dp[length] = 1;

    for(; i >= 0; i--)
    {
        singleDigit = s[i] - '0';
        
        if(i < counter)
        {
            doubleDigit = (singleDigit * 10) + s[(i + 1)] - '0';
        }

        if(singleDigit > 0) dp[i] += dp[(i + 1)];
        if(doubleDigit > 9 && doubleDigit < 27) dp[i] += dp[(i + 2)];
    }

    return dp[0];
}