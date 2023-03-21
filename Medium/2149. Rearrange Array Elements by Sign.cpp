#include <iostream>
using namespace std;

void rearrangeArray(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    rearrangeArray(nums, length);

    return 0;
}

void rearrangeArray(int nums[], int length) 
{
    int i = 0, pos = 0, neg = 1, output[length];

    for(; i < length; i++)
    {
        if(nums[i] >= 0) 
        {
            output[pos] = nums[i];
            pos += 2;
        }
        else
        {
            output[neg] = nums[i];
            neg += 2;
        }
    }

    for(i = 0; i < length; i++)
    {
        cout << output[i] << " ";
    }
}