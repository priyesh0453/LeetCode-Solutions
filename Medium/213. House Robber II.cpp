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

    int dp1 = nums[0], dp2_first = max(dp1, nums[1]), dp2_last, i = 2, dp_temp, counter = (noOfHouses - 1);

    for(; i < counter; i++)
    {
        dp_temp = dp2_first;
        dp2_first = max(dp2_first, (nums[i] + dp1));
        dp1 = dp_temp;
    }

    dp1 = nums[1];
    dp2_last = max(dp1, nums[2]);
    i = 3;

    for(; i < noOfHouses; i++)
    {
        dp_temp = dp2_last;
        dp2_last = max(dp2_last, (nums[i] + dp1));
        dp1 = dp_temp;
    }

    return max(dp2_first, dp2_last);
}