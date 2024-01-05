#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector <int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << lengthOfLIS(nums, noOfElements);

    return 0;
}

int lengthOfLIS(vector <int>& nums, int noOfElements) 
{
    /*  Simple DP approach for maintaining tails length of longest subsequence until each index - O(N^2)

    int i = 1, j;
    vector <int> tailLengths(noOfElements, 1);

    for(; i < noOfElements; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(nums[i] > nums[j]) tailLengths[i] = max(tailLengths[i], tailLengths[j] + 1);
        }
    }

    return *max_element(tailLengths.begin(), tailLengths.end()); 
    */

    //Binary Search Approach - O(NLogN)

    int longestSubLength = 1, tempIndex, i = 1;
    vector <int> longestSub;

    longestSub.push_back(nums[0]);

    for(; i < noOfElements; i++)
    {
        if(nums[i] > longestSub.back())
        {
            longestSub.push_back(nums[i]);
            longestSubLength++;
        }
        else
        {
            tempIndex = lower_bound(longestSub.begin(), longestSub.end(), nums[i]) - longestSub.begin();
            longestSub[tempIndex] = nums[i];
        }
    }

    return longestSubLength;
}