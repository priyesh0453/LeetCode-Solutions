#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << removeDuplicates(nums, length);

    return 0;
}

int removeDuplicates(int nums[], int length) 
{
    int i = 0, j = 1;

    for(; j < length; j++)
    {
        if(nums[i] != nums[j]) nums[++i] = nums[j];
    }

    return (i + 1);    
}