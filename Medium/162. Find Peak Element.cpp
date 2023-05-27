#include <iostream>
using namespace std;

int findPeakElement(int nums[], int length);

int main()
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << findPeakElement(nums, length);

    return 0;
}

int findPeakElement(int nums[], int length)
{
    if(length == 1) return 0;
    
    int left_Index = 0, right_Index = (length - 1), mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (right_Index - left_Index) / 2;

        if(mid_Index == 0) return nums[0] > nums[1] ? 0 : 1;
        if(mid_Index == (length - 1)) return nums[(length - 1)] > nums[(length - 2)] ? (length - 1) : (length - 2);

        if(nums[mid_Index] >= nums[(mid_Index - 1)] && nums[mid_Index] >= nums[(mid_Index + 1)]) return mid_Index;
        else if(nums[(mid_Index)] < nums[(mid_Index - 1)]) right_Index = mid_Index - 1;
        else left_Index = mid_Index + 1;
    }    

    return left_Index;
}