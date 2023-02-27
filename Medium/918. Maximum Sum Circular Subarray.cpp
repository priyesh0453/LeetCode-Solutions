#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySumCircular(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    cout << maxSubarraySumCircular(nums, size);

    return 0;
}

int maxSubarraySumCircular(int nums[], int size) 
{
    if(size == 1) return nums[0];

    int i = 0, temp_max = 0, temp_min = 0, max_sum = INT_MIN, min_sum = INT_MAX, total_sum = 0;

    for(; i < size; i++)
    {
        total_sum += nums[i];
        temp_max += nums[i];
        temp_min += nums[i];

        if(temp_max > max_sum) max_sum = temp_max;
        if(temp_min < min_sum) min_sum = temp_min;
        if(temp_max < 0) temp_max = 0;
        if(temp_min > 0) temp_min = 0;
    }

    return ((total_sum == min_sum) ? max_sum : (max(max_sum, (total_sum - min_sum)))); 
}