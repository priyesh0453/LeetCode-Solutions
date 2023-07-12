#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

int main()
{
    int numCourses, P, i = 0, j, col;
    cin >> numCourses >> P;
    
    vector <vector <int>> prerequisites(numCourses);
    
    for(; i < P; i++)
    {
        cin >> col;
        vector <int> row(col);
        
        for(j = 0; j < col; j++)
        {
            cin >> row[j];
        }
        
        prerequisites[i] = row;
    }
    
    cout << canFinish(numCourses, prerequisites);

    return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{ 
    vector <vector <int>> adj(numCourses);
    vector <int> inDegree(numCourses, 0);
    queue <int> temp;
    int i = 0, counter = 0, node;

    for(auto iterator : prerequisites)
    {
        adj[iterator[0]].push_back(iterator[1]);
        inDegree[iterator[1]]++;
    } 
    
    for(i = 0; i < numCourses; i++)
    {
        if(!inDegree[i]) temp.push(i);
    }
    
    while(!temp.empty())
    {
        node = temp.front();
        temp.pop();
        counter++;
        
        for(auto iterator : adj[node])
        {
            inDegree[iterator]--;
            
            if(!inDegree[iterator]) temp.push(iterator);
        }
    }
    
    return (counter == numCourses);  
}