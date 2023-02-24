#include <iostream>
using namespace std;

int numberOfArithmeticSlices(int nums[], int length);

int main()
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
     
    cout << numberOfArithmeticSlices(nums, length);

    return 0;
}

int numberOfArithmeticSlices(int nums[], int length) 
{
    if(length < 3) return 0;

    int subarrays = 0, totalSubarrays = 0, i = 2;

    for(; i < length; i++)
    {
        if((nums[i] - nums[( i - 1)]) == (nums[(i - 1)] - nums[(i - 2)]))
        {
            subarrays++;
            totalSubarrays += subarrays;
        }
        else subarrays = 0;
    }

    return totalSubarrays;        
}