#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << singleNumber(nums, noOfElements);
    
    return 0;
}

int singleNumber(vector<int>& nums, int noOfElements) 
{
    int i = 0, singleElement = 0;

    for(; i < noOfElements; i++)
    {
        singleElement ^= nums[i];
    }

    return singleElement;
}