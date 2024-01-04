#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minOperations(vector <int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums (noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i]; 
    }
    
    cout << minOperations(nums, noOfElements);

    return 0;
}

int minOperations(vector <int>& nums, int noOfElements) 
{
    int i = 0, minOps = 0;
    unordered_map <int, int> freq;

    for(; i < noOfElements; i++)
    {
        freq[nums[i]]++;
    }    

    for(auto [element, count] : freq)
    {
        if(count == 1) return -1;

        minOps += (count / 3) + (count % 3 != 0);
    }

    return minOps;
}