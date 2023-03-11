#include <iostream>
using namespace std;

int missingNumber(int nums[], int n);

int main()
{
    int n, i = 0;
    cin >> n;
    
    int nums[n];
    
    for(; i < n; i++)
    {
        cin >> nums[i];
    }
    
    cout << missingNumber(nums, n);

    return 0;
}

int missingNumber(int nums[], int n) 
{
    int xor_1 = 0, xor_2 = 0, i = 0;

    //XOR never exceeds the larget number and 0^n = n;
    
    for(; i < n; i++)
    {
        xor_1 ^= i;
        xor_2 ^= nums[i];
    }

    return ((xor_1 ^ n) ^ xor_2);
}