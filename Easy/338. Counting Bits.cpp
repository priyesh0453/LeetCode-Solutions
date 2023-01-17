#include <iostream>
#include <vector>
using namespace std;

void countBits(int n);

int main(void)
{
    int n;
    cin >> n;
    
    countBits(n);

    return 0;
}

void countBits(int n) 
{
    vector <int> dp(n + 1);
    int i = 1;

    dp[0] = 0;
    
    cout << "[" << dp[0] << ",";

    for(; i <= n; i++)
    {
        dp[i] = (i & 1) + dp[(i >> 1)];
        cout << dp[i] << ",";
    }
    
    cout << "\b]" << endl;
}