#include <iostream>
#include <vector>
using namespace std;

int calcMinDelSum(string& s1, string& s2, vector <vector <int>>& dp, int s1_Index, int s2_Index);
int minimumDeleteSum(string s1, string s2);

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << minimumDeleteSum(s1, s2);

    return 0;
}

int minimumDeleteSum(string s1, string s2) 
{
    int length1 = s1.length(), length2 = s2.length();
    vector <vector <int>> dp((length1 + 1), vector <int> ((length2 + 1), -1));

    return calcMinDelSum(s1, s2, dp, (length1 - 1), (length2 - 1));    
}

int calcMinDelSum(string& s1, string& s2, vector <vector <int>>& dp, int s1_Index, int s2_Index)
{
    if(s1_Index < 0 && s2_Index < 0) return 0;
    else if(s1_Index >= 0 && s2_Index < 0)
    {
        int tempSum = 0;

        while(s1_Index >= 0) tempSum += s1[s1_Index--];

        return tempSum;
    }
    else if(s1_Index < 0 && s2_Index >= 0)
    {
        int tempSum = 0;

        while(s2_Index >= 0) tempSum += s2[s2_Index--];

        return tempSum;
    }

    if(dp[s1_Index][s2_Index] != -1) return dp[s1_Index][s2_Index];

    if(s1[s1_Index] == s2[s2_Index]) dp[s1_Index][s2_Index] = (calcMinDelSum(s1, s2, dp, (s1_Index - 1), (s2_Index - 1)));
    else dp[s1_Index][s2_Index] = min((s1[s1_Index] + calcMinDelSum(s1, s2, dp, (s1_Index - 1), s2_Index)), (s2[s2_Index] + calcMinDelSum(s1, s2, dp, s1_Index, (s2_Index - 1))));

    return dp[s1_Index][s2_Index];
}