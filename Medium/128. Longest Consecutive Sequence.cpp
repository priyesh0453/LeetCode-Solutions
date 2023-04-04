#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << longestConsecutive(nums, length);

    return 0;
}

int longestConsecutive(int nums[], int length) 
{
    if(length == 0) return 0;
        
    int temp, i = 0, longestConsecutiveLength = 1, count = 0;
    unordered_set <int> Set;

    for(; i < length; i++)
    {
        Set.insert(nums[i]);
    }
    
    for(auto iterator : Set)
    {
        if(Set.find(iterator - 1) == Set.end())
        {
            count = 1;
            temp = iterator;
            
            while(Set.find(temp + 1) != Set.end())
            {
                temp++;
                count++;
            }

            longestConsecutiveLength = max(longestConsecutiveLength, count);
        }
    }

    return longestConsecutiveLength;
}