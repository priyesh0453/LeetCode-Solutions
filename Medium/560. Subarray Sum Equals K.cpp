#include <iostream>
#include <unordered_map>
using namespace std;

int subarraySum(int nums[], int length, int k);

int main(void)
{
    int length, k, i = 0;
    cin >> length;
    cin >> k;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << subarraySum(nums, length, k);

    return 0;
}

int subarraySum(int nums[], int length, int k) 
{
    int i = 0, prefixSum = 0, noOfReqSubArr = 0, remove;
    unordered_map <int, int> preSumHash;
        
    preSumHash[0] = 1;

    for(; i < length; i++)
    {
        prefixSum += nums[i];
        remove = prefixSum - k;
        noOfReqSubArr += preSumHash[remove];
        preSumHash[prefixSum]++;
    }

    return noOfReqSubArr;
}