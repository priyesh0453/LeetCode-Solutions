#include <iostream>
#include <vector>
using namespace std;

int minTaps(int n, vector <int>& ranges);

int main()
{
    int n, i = 0;
    cin >> n;
    
    vector <int> ranges(n + 1);
    
    for(; i <= n; i++)
    {
        cin >> ranges[i];
    }
    
    cout << minTaps(n, ranges);

    return 0;
}

int minTaps(int n, vector <int>& ranges) 
{
    int i = 0, tempIndex, tempEnd = 0, minTaps = 0, maxReach = 0;
    vector <int> limit(n + 1, 0);

    for(; i <= n; i++)
    {
        if(ranges[i])
        {
            tempIndex = max(0, i - ranges[i]);
            limit[tempIndex] = max(limit[tempIndex], i + ranges[i]);
        }
    }

    for(i = 0; i <= n && tempEnd < n;)
    {
        minTaps++;

        while(i <= n && i <= tempEnd)
        {
            maxReach = max(maxReach, limit[i]);
            i++;
        }

        if(tempEnd == maxReach) return -1;

        tempEnd = maxReach;
    }

    return minTaps;
}