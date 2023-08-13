#include <iostream>
#include <vector>
using namespace std;

bool validPartition(vector <int>& nums, int noOfElements);
bool checkValidity(vector <int>& nums, int noOfElements, vector <int>& dp, int index);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << validPartition(nums, noOfElements);

    return 0;
}

bool validPartition(vector <int>& nums, int noOfElements) 
{
    vector <int> dp(noOfElements, -1);

    return checkValidity(nums, noOfElements, dp, 0);   
}

bool checkValidity(vector <int>& nums, int noOfElements, vector <int>& dp, int index)
{
    if(index >= noOfElements) return true;
    if(dp[index] != -1) return dp[index];

    if((index + 1) < noOfElements && nums[index] == nums[(index + 1)])
    {
        dp[index] = checkValidity(nums, noOfElements, dp, (index + 2));
        if(dp[index]) return true;

        if((index + 2) < noOfElements && nums[index] == nums[(index + 2)])
        {
            dp[index] = checkValidity(nums, noOfElements, dp, (index + 3));
            if(dp[index]) return true;
        }
    }

    if((index + 2) < noOfElements && (nums[index] - nums[index + 1] == -1) && (nums[index] - nums[index + 2] == -2))
    {
        dp[index] = checkValidity(nums, noOfElements, dp, (index + 3));
        if(dp[index]) return true;
    }

    return dp[index] = 0;
}