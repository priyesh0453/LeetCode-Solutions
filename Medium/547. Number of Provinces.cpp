#include <iostream>
#include <vector>
using namespace std;

void dfsTraversal(int node, vector <int>& visited, vector <int> list[]);
int findCircleNum(vector <vector <int>>& isConnected, int V);

int main()
{
    int V, i = 0, j;
    cin >> V;
    
    vector <vector <int>> isConnected(V, vector <int> (V));
    
    for(; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    cout << findCircleNum(isConnected, V);

    return 0;
}

int findCircleNum(vector <vector <int>>& isConnected, int V) 
{
    vector <int> list[V];
    int i = 0, j, noOfProvinces = 0;
    vector <int> visited(V, 0);
    
    for(; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            if(i != j && isConnected[i][j] == 1)
            {
                list[i].push_back(j);
                list[j].push_back(i);
            }
        }
    }
    
    for(i = 0; i < V; i++)
    {
        if(visited[i] == 0)
        {
            noOfProvinces++;
            dfsTraversal(i, visited, list);
        }
    }
    
    return noOfProvinces;    
}

void dfsTraversal(int node, vector <int>& visited, vector <int> list[])
{
    visited[node] = 1;
    
    for(auto iterator : list[node])
    {
        if(visited[iterator] == 0)
        {
            dfsTraversal(iterator, visited, list);
        }
    }
}