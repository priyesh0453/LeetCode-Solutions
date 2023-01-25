#include <iostream>
using namespace std;

int maxSubArray(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    cout << maxSubArray(nums, size);

    return 0;
}

int maxSubArray(int nums[], int size) 
{
    if(size == 1) return nums[0];

    int i = 0, sum = 0, maxSum = nums[0];

    for(; i < size; i++)
    {
        sum += nums[i];
        maxSum = max(sum, maxSum);

        if(sum < 0) sum = 0;
    }

    return maxSum;
}