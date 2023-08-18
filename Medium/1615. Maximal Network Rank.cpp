#include <iostream>
#include <vector>
using namespace std;

int maximalNetworkRank(int n, vector <vector <int>>& roads, int noOfConnections);

int main()
{
    int n, i = 0, j, noOfConnections;
    cin >> n >> noOfConnections;
    
    vector <vector <int>> roads(noOfConnections, vector <int> (2));
    
    for(; i < noOfConnections; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> roads[i][j];
        }
    }

    cout << maximalNetworkRank(n, roads, noOfConnections);
    
    return 0;
}

int maximalNetworkRank(int n, vector <vector <int>>& roads, int noOfConnections) 
{
    int i = 0, j, maxRank = 0;
    vector <int> rank(n, 0);
    vector <vector <int>> connections(n, vector <int> (n, 0));

    for(; i < noOfConnections; i++)
    {
        connections[roads[i][0]][roads[i][1]] = 1;
        connections[roads[i][1]][roads[i][0]] = 1;

        rank[roads[i][0]]++;
        rank[roads[i][1]]++;
    }

    for(i = 0; i < n; i++)
    {
        for(j = (i + 1); j < n; j++)
        {
            maxRank = max(maxRank, rank[i] + rank[j] - connections[i][j]);
        }
    }

    return maxRank;   
}