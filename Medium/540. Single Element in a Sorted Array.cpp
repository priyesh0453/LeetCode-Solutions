#include <iostream>
using namespace std;

int singleNonDuplicate(int nums[], int length);

int main()
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << singleNonDuplicate(nums, length);

    return 0;
}

int singleNonDuplicate(int nums[], int length) 
{
    int left_Index = 0, right_Index = (length - 2), mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (right_Index - left_Index) / 2;

        if(nums[mid_Index] == nums[(mid_Index ^ 1)]) left_Index = mid_Index + 1;
        else right_Index = mid_Index - 1;
    }
    
    return nums[left_Index];    
}