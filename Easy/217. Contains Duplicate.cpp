#include <iostream>
#include <set>
using namespace std;

bool containsDuplicate(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    cout << containsDuplicate(nums, length);

    return 0;
}

bool containsDuplicate(int nums[], int length) 
{
    int i = 0;
    set <int> arr;

    for(; i < length; i++)
    {
        arr.insert(nums[i]);
    }

    return (arr.size() != length);
}