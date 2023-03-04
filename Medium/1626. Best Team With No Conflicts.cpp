#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int bestTeamScore(int scores[], int noOfPlayers, int ages[]);

int main()
{
    int noOfPlayers, i = 0;
    
    cin >> noOfPlayers;
    
    int scores[noOfPlayers], ages[noOfPlayers];
    
    for(; i < noOfPlayers; i++)
    {
        cin >> scores[i];
        cin >> ages[i];
    }
    
    cout << bestTeamScore(scores, noOfPlayers, ages);

    return 0;
}

int bestTeamScore(int scores[], int noOfPlayers, int ages[])
{
    int i = 0;

    vector<vector<int>> arr;

    for(; i < noOfPlayers; i++)
    {
        arr.push_back({-ages[i], -scores[i]});
    }

    sort(arr.begin(), arr.end());

    int dp[noOfPlayers], maxScore = 0, j;
    memset(dp, 0, sizeof(dp));
    i = 0;

    for(; i < noOfPlayers; i++)
    {
        for(j = i; j >= 0; j--)
        {
            if(-arr[i][1] <= -arr[j][1]) dp[i] = max(dp[i], (dp[j] - arr[i][1]));
        }
        maxScore = max(maxScore, dp[i]);
    }

    return maxScore;
}