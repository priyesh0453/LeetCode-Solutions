#include <iostream>
using namespace std;

int search(int nums[], int length, int target);

int main(void)
{
    int length, target, i = 0;
    cin >> length;
    cin >> target;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << search(nums, length, target);

    return 0;
}

int search(int nums[], int length, int target)
{
    int left_Index = 0, right_Index = (length - 1), mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (-left_Index + right_Index) / 2;

        if(nums[mid_Index] == target) return mid_Index;

        if(nums[left_Index] <= nums[mid_Index])
        {
            if(nums[left_Index] <= target && target <= nums[mid_Index]) right_Index = mid_Index - 1;
            else left_Index = mid_Index + 1;
        }
        else
        {
            if(nums[mid_Index] <= target && target <= nums[right_Index]) left_Index = mid_Index + 1;
            else right_Index = mid_Index - 1;
        }
    }

    return -1;   
}