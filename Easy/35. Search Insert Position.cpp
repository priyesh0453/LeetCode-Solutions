#include <iostream>
using namespace std;

int searchInsert(int nums[], int target, int length);

int main()
{
    int target, length, i = 0;
    cin >> target;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << searchInsert(nums, target, length);

    return 0;
}

int searchInsert(int nums[], int target, int length) 
{
    int left_Index = 0, right_Index = (length - 1), mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = (left_Index + right_Index) / 2;
        
        if(nums[mid_Index] == target) return mid_Index;
        else if(nums[mid_Index] < target) left_Index = mid_Index + 1;
        else right_Index = mid_Index - 1; 
    }

    return left_Index;
}