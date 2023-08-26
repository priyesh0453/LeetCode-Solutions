#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool static comparator(vector <int> x, vector <int> y);
int findLongestChain(vector <vector <int>>& pairs, int noOfPairs);

int main()
{
    int noOfPairs, i = 0, j; 
    cin >> noOfPairs;
    
    vector <vector <int>> pairs(noOfPairs, vector <int> (2));
    
    for(; i < noOfPairs; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> pairs[i][j];
        }
    }
    
    cout << findLongestChain(pairs, noOfPairs);

    return 0;
}

int findLongestChain(vector <vector <int>>& pairs, int noOfPairs) 
{
    int end, length = 1, i = 1;

    sort(pairs.begin(), pairs.end(), comparator);

    end = pairs[0][1];

    for(; i < noOfPairs; i++)
    {
        if(pairs[i][0] > end)
        {
            length++;
            end = pairs[i][1];
        }
    }

    return length;
}

bool static comparator(vector <int> x, vector <int> y)
{
    return (y[1] > x[1]);
}