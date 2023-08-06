#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int minimumSeconds(vector<int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << minimumSeconds(nums, noOfElements);

    return 0;
}

int minimumSeconds(vector<int>& nums, int noOfElements) 
{
    int i = 0, minTime = INT_MAX, tempTime, tempLength;
    unordered_map <int, vector <int>> posOfElements;
    
    for(; i < noOfElements; i++)
    {
        posOfElements[nums[i]].push_back(i);
    }
    
    for(auto [num, indices] : posOfElements)
    {
        indices.push_back(indices[0] + noOfElements);
        
        tempLength = indices.size();
        tempTime = 0;
        
        for(i = 1; i < tempLength; i++)
        {
            tempTime = max(tempTime, ((indices[i] - indices[(i - 1)]) / 2));
        }
        
        minTime = min(minTime, tempTime);
    }
    
    return minTime;       
}