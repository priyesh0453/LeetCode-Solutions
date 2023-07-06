#include <iostream>
#include <vector>
using namespace std;

bool dfsTraversal(vector <vector <int>>& graph, vector <int>& visited, int i, int currentColor);
bool isBipartite(vector<vector<int>>& graph, int noOfVertices);

int main()
{
    int noOfVertices, i = 0, j, col;
    cin >> noOfVertices;
    
    vector <vector <int>> graph(noOfVertices);
    
    for(; i < noOfVertices; i++)
    {
        cin >> col;
        vector <int> row(col);
        
        for(j = 0; j < col; j++)
        {
            cin >> row[j];
        }
        
        graph[i] = row;
    }
    
    cout << isBipartite(graph, noOfVertices);

    return 0;
}

bool isBipartite(vector<vector<int>>& graph, int noOfVertices) 
{
    int i = 0;
    vector <int> visited(noOfVertices, 0);

    for(; i < noOfVertices; i++)
    {
        if(visited[i] == 0)
        {
            if(dfsTraversal(graph, visited, i, 1) == false) return false;
        }
    }
    
    return true;
}

bool dfsTraversal(vector <vector <int>>& graph, vector <int>& visited, int i, int currentColor)
{
    visited[i] = currentColor;

    for(auto iterator : graph[i])
    {
        if(visited[iterator] == 0)
        {
            if(dfsTraversal(graph, visited, iterator, currentColor == 1 ? 2 : 1) == false) return false;
        }
        else if(visited[iterator] == currentColor) return false;
    }

    return true;
}