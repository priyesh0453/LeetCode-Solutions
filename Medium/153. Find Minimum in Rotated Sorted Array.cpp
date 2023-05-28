#include <iostream>
#include <climits>
using namespace std;

int findMin(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    cout << findMin(nums, size);

    return 0;
}

int findMin(int nums[], int size) 
{
    int left_Index = 0, right_Index = (size - 1), mid_Index, minElement = INT_MAX;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (-left_Index + right_Index) / 2;

        if(nums[left_Index] < nums[right_Index]) return min(minElement, nums[left_Index]);

        if(nums[left_Index] <= nums[mid_Index])
        {
            minElement = min(minElement, nums[left_Index]);
            left_Index = mid_Index + 1;
        }
        else
        {
            minElement = min(minElement, nums[mid_Index]);
            right_Index = mid_Index - 1;
        }
    }

    return minElement;    
}