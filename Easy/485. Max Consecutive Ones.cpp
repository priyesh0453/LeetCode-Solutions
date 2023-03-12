#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(int nums[], int length);

int main(void)
{
    int n, i = 0;
    cin >> n;
    
    int nums[n];
    
    for(; i < n; i++)
    {
        cin >> nums[i];
    }
    
    cout << findMaxConsecutiveOnes(nums, n);

    return 0;
}

int findMaxConsecutiveOnes(int nums[], int length) 
{
    int i = 0, counter = 0, max_Count = 0;

    for(; i < length; i++)
    {
        if(nums[i] == 1)
        {
            counter++;
            max_Count = max(max_Count, counter);
        }
        else counter = 0;
    }
    return max_Count;    
}