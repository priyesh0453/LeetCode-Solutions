#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long minimumReplacement(vector <int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << minimumReplacement(nums, noOfElements);

    return 0;
}

long long minimumReplacement(vector <int>& nums, int noOfElements) 
{
    int i = noOfElements - 2, maxVal = nums[i + 1], counter;
    long long noOfOps = 0;

    for(; i >= 0; i--)
    {
        counter = ceil((double)(nums[i]) / maxVal);
        noOfOps += counter - 1;
        maxVal = nums[i] / counter;
    } 

    return noOfOps;
}