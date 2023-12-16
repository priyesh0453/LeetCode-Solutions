#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string destCity(vector<vector<string>>& paths, int noOfPaths);

int main()
{
    int noOfPaths;
    cin >> noOfPaths;

    vector <vector <string>> paths(noOfPaths);
    
    for (int i = 0; i < noOfPaths; i++) 
    {
        string from, to;
        cin >> from >> to;
        paths[i] = {from, to};
    }
    
    cout << destCity(paths, noOfPaths);

    return 0;
}

string destCity(vector <vector <string>>& paths, int noOfPaths) 
{
    unordered_map<string, int> outgoings;

    for(int i = 0; i < noOfPaths; i++)
    {
        outgoings[paths[i][1]]++;
        outgoings[paths[i][0]]--;
    }    

    for(auto &iterator : outgoings)
    {
        if(iterator.second == 1) return iterator.first;
    }

    return "";
}
