#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector <int>& nums);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    cout << findDuplicate(nums);

    return 0;
}

int findDuplicate(vector <int>& nums) 
{
    int hare = 0, tortoise = 0;

    while(1)
    {
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];

        if(hare == tortoise) break;
    }

    tortoise = 0;

    while(hare != tortoise)
    {
        hare = nums[hare];
        tortoise = nums[tortoise];
    }

    return tortoise;
}