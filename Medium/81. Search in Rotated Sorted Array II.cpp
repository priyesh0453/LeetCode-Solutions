#include <iostream>
using namespace std;

bool search(int nums[], int target, int size);

int main()
{
    int size, target, i = 0;
    cin >> size;
    cin >> target;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    cout << search(nums, target, size);

    return 0;
}

bool search(int nums[], int target, int size) 
{
    int left_Index = 0, right_Index = (size - 1), mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (-left_Index + right_Index) / 2;

        if(nums[mid_Index] == target) return true;

        if((nums[left_Index] == nums[mid_Index]) && (nums[right_Index] == nums[mid_Index]))
        {
            left_Index++;
            right_Index--;
        }
        else if(nums[left_Index] <= nums[mid_Index])
        {
            if((nums[left_Index] <= target) && (nums[mid_Index] > target)) right_Index = mid_Index - 1;
            else left_Index = mid_Index + 1;
        }
        else
        {
            if((nums[right_Index] >= target) && (nums[mid_Index] < target)) left_Index = mid_Index + 1;
            else right_Index = mid_Index - 1;
        }
    }

    return false;    
}