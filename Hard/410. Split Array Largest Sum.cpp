#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int splitArray(vector<int>& nums, int noOfElements, int k);
int countSplits(vector <int> nums, int noOfElements, int mid);

int main()
{
    int noOfElements, k, i = 0;
    cin >> noOfElements >> k;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << splitArray(nums, noOfElements, k);

    return 0;
}

int splitArray(vector<int>& nums, int noOfElements, int k) 
{
    int i = 0, low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0), mid, noOfSplits;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        noOfSplits = countSplits(nums, noOfElements, mid);

        if(noOfSplits > k) low = mid + 1;
        else high = mid - 1;
    }    

    return low;
}

int countSplits(vector <int> nums, int noOfElements, int mid)
{
    int splits = 1, i = 0, temp = 0;

    for(; i < noOfElements; i++)
    {
        if(temp + nums[i] <= mid) temp += nums[i];
        else
        {
            splits++;
            temp = nums[i];
        }
    }
    
    return splits;
}