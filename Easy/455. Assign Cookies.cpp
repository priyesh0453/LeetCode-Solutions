#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, int noOfChildren, vector<int>& s, int noOfCookies);

int main()
{
    int noOfChildren, noOfCookies, i = 0;
    cin >> noOfChildren >> noOfCookies;
    
    vector <int> g(noOfChildren), s(noOfCookies);
    
    for(; i < noOfChildren; i++)
    {
        cin >> g[i];
    }
    
    for(i = 0; i < noOfCookies; i++)
    {
        cin >> s[i];
    }
    
    cout << findContentChildren(g, noOfChildren, s, noOfCookies);

    return 0;
}

int findContentChildren(vector<int>& g, int noOfChildren, vector<int>& s, int noOfCookies) 
{    
    sort(g.begin(), g.end()), sort(s.begin(), s.end());

    int i = 0, gIndex = 0, sIndex = 0;

    for(; (gIndex < noOfChildren && sIndex < noOfCookies) ;)
    {
        if(s[sIndex] >= g[gIndex])
        {
            gIndex++;
            sIndex++;
        }
        else sIndex++;
    }

    return gIndex;
}