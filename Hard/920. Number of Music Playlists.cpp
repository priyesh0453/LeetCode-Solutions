#include <iostream>
#include <vector>
using namespace std;

int numMusicPlaylists(int n, int goal, int k);
long long calcNoOfPlaylists(int n, int goal, int k, vector <vector <int>>& dp);

int MOD = 1e9 + 7;

int main()
{
    int n, goal, k;
    cin >> n >> goal >> k;
    
    cout << numMusicPlaylists(n, goal, k);

    return 0;
}

int numMusicPlaylists(int n, int goal, int k) 
{
    vector <vector <int>> dp((n + 1), vector <int> ((goal + 1), -1));

    return calcNoOfPlaylists(n, goal, k, dp);    
}

long long calcNoOfPlaylists(int n, int goal, int k, vector <vector <int>>& dp)
{
    if(!n && !goal) return 1;
    if(!n || !goal) return 0;
    if(dp[n][goal] != -1) return dp[n][goal];

    long long selectDiffSong = calcNoOfPlaylists((n - 1), (goal -1), k, dp) * n, notSelectDiff = calcNoOfPlaylists(n, (goal - 1), k, dp) * max((n - k), 0);

    dp[n][goal] = (selectDiffSong + notSelectDiff) % MOD;

    return dp[n][goal];
}