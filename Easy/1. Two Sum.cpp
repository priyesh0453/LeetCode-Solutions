#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void twoSum(vector <int> nums, int  sizeOfNums, int target);

int main()
{
    vector <int> nums;
    int i = 0, var, sizeOfNums, target;
    
    cin >> sizeOfNums;
    
    for(; i < sizeOfNums; i++)
    {
        cin >> var;
        nums.push_back(var);
    }
    
    cin >> target;

    twoSum(nums, sizeOfNums, target);

    return 0;
}

void twoSum(vector <int> nums, int  sizeOfNums, int target) 
{
    unordered_map <int, int> hashMap;
    int i = 0;

    for(; i < sizeOfNums; i++)
    {
        if(hashMap.count((target - nums[i])) != 0) break;
        
        hashMap[nums[i]] = i;
    }
    
    cout << "[" << hashMap[(target - nums[i])] << ", " << i << "]";
}