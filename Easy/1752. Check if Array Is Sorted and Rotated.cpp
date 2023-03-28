#include <iostream>
using namespace std;

bool check(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << check(nums, length);

    return 0;
}

bool check(int nums[], int length) 
{
    int i = 0, count = 0;

    for(; i < length; i++)
    {
        if(nums[i] > nums[(i + 1) % length])
        {
            count++;
        }
    }

    return (count <= 1);    
}