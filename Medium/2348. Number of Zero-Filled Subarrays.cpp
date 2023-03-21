#include <iostream>
using namespace std;

long long zeroFilledSubarray(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << zeroFilledSubarray(nums, length);

    return 0;
}

long long zeroFilledSubarray(int nums[], int length) 
{
    int i = 0, count = 0;
    long long count_Subarr = 0;

    for(; i < length; i++)
    {
        if(nums[i] == 0)
        {
            count++;
            count_Subarr += count;
        }
        else count = 0;
    } 

    return count_Subarr;   
}