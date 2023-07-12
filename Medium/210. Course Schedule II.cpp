#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findOrder(int numCourses, vector<vector<int>>& prerequisites, vector <int>& order);
void display(vector <int> order, int numCourses);

int main()
{
    int numCourses, P, i = 0, j, col;
    cin >> numCourses >> P;
    
    vector <vector <int>> prerequisites(numCourses);
    vector <int> order;
    
    for(; i < P; i++)
    {
        vector <int> row(2);
        
        for(j = 0; j < 2; j++)
        {
            cin >> row[j];
        }
        
        prerequisites[i] = row;
    }
    
    findOrder(numCourses, prerequisites, order);
    display(order, numCourses);
    
    return 0;
}

void findOrder(int numCourses, vector<vector<int>>& prerequisites, vector <int>& order) 
{
    vector <vector <int>> adj(numCourses);
    vector <int> inDegree(numCourses, 0);
    queue <int> temp;
    int i = 0, counter = 0, node;

    for(auto iterator : prerequisites)
    {
        adj[iterator[1]].push_back(iterator[0]);
        inDegree[iterator[0]]++;
    } 
    
    for(i = 0; i < numCourses; i++)
    {
        if(!inDegree[i]) temp.push(i);
    }
    
    while(!temp.empty())
    {
        node = temp.front();
        temp.pop();
        order.push_back(node);
        
        for(auto iterator : adj[node])
        {
            inDegree[iterator]--;
            
            if(!inDegree[iterator]) temp.push(iterator);
        }
    }
}

void display(vector <int> order, int numCourses)
{
    int i = 0;
    
    for(; i < numCourses; i++)
    {
        cout << order[i] << " ";
    }
}