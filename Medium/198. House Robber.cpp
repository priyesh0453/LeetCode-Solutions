#include <iostream>
using namespace std;

int rob(int nums[], int noOfHouses);

int main()
{
    int noOfHouses;
    cin >> noOfHouses;
    
    int nums[noOfHouses], i = 0;
    
    for(; i < noOfHouses; i++)
    {
        cin >> nums[i];
    }
    
    cout << rob(nums, noOfHouses);
 
    return 0;
}

int rob(int nums[], int noOfHouses) 
{
    if(noOfHouses == 1) return nums[0];
    if(noOfHouses == 2) return max(nums[0], nums[1]);

    int dp1 = nums[0], dp2 = max(nums[0], nums[1]), i = 2, dp_temp;

    for(; i < noOfHouses; i++)
    {
        dp_temp = dp2;
        dp2= max(dp2, (nums[i] + dp1));
        dp1 = dp_temp;
    }

    return dp2;
}