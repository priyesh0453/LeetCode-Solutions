#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector <int>& nums, int mid, int length);
int smallestDivisor(vector<int>& nums, int threshold, int length);

int main()
{
    int length, threshold, i = 0;
    cin >> length >> threshold;
    
    vector <int> nums(length);
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << smallestDivisor(nums, threshold, length);

    return 0;
}

int smallestDivisor(vector<int>& nums, int threshold, int length) 
{
    int low = 1, high = *max_element(nums.begin(), nums.end()), mid;

    while(low < high)
    {
        mid = low + (high - low) / 2;

        if(sum(nums, mid, length) <= threshold) high = mid;
        else low = (mid + 1);
    }

    return low;
}

int sum(vector <int>& nums, int mid, int length)
{
    int i = 0, sum = 0;

    for(; i < length; i++)
    {
        sum += (nums[i] + mid - 1) / mid;
    }
    
    return sum;
}