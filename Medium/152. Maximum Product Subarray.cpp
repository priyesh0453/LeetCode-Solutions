#include <iostream>
using namespace std;

int maxProduct(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    cout << maxProduct(nums, size);

    return 0;
}

int maxProduct(int nums[], int size) 
{
    int maxProduct = nums[0], minProduct = nums[0], maxResult = nums[0], i = 1, temp;

    for(; i < size; i++)
    {
        temp = max((nums[i] * maxProduct), max((nums[i] * minProduct), nums[i]));
        minProduct = min((nums[i] * maxProduct), min((nums[i] * minProduct), nums[i]));

        maxProduct = temp;
        maxResult = max(maxResult, maxProduct);
    }

    return maxResult;
}