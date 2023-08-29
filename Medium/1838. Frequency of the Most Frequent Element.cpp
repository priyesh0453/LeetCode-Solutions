#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector <int>& nums, int noOfElements, int k);

int main()
{
    int noOfElements, k, i = 00;
    cin >> noOfElements >> k;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << maxFrequency(nums, noOfElements, k);

    return 0;
}

int maxFrequency(vector <int>& nums, int noOfElements, int k) 
{
    int leftIndex = 0, rightIndex = 0, maxFreq = 0;

    sort(nums.begin(), nums.end());

    long currentSum = nums[0];

    while(rightIndex < noOfElements)
    {
        if(((rightIndex - leftIndex + 1) * (long) nums[rightIndex]) <= (k + currentSum))
        {
            maxFreq = max(maxFreq, (rightIndex - leftIndex + 1));
            rightIndex++;

            if(rightIndex < noOfElements) currentSum += nums[rightIndex];
        }
        else
        {
            currentSum -= nums[leftIndex];
            leftIndex++;
        }
    }   

    return maxFreq;
}