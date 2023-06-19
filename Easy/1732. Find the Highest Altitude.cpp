#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain, int n);

int main()
{
    int n, i = 0;
    cin >> n;
    
    vector <int> gain(n);
    
    for(; i < n; i++)
    {
        cin >> gain[i];
    }
    
    cout << largestAltitude(gain, n);

    return 0;
}

int largestAltitude(vector<int>& gain, int n)
{
    int i = 0, highestAlt = 0, tempHeight = 0;

    for(; i < n; i++)
    {
        tempHeight += gain[i];
        highestAlt = max(tempHeight, highestAlt);
    }

    return highestAlt;
}