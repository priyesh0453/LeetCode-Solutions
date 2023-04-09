#include <iostream>
using namespace std;

int pivotIndex(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << pivotIndex(nums, length);

    return 0;
}

int pivotIndex(int nums[], int length) 
{
    int totalSum = 0, leftSum = 0, rightSum, i = 0;

    for(; i < length; i++)
    {
        totalSum += nums[i];
    }

    rightSum = totalSum, i = 0;

    for(; i < length; i++)
    {
        rightSum -= nums[i];
        
        if(leftSum == rightSum) return i;

        leftSum += nums[i];
    }

    return -1;
}