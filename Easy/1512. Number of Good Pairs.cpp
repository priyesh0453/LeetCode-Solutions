#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int>& nums);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << numIdenticalPairs(nums);

    return 0;
}

int numIdenticalPairs(vector<int>& nums) 
{  
    unordered_map <int, int> freq;
    int noOfPairs = 0;

    for(int num : nums) 
    {   
        noOfPairs += freq[num];
        freq[num]++;
    }

    return noOfPairs;
}