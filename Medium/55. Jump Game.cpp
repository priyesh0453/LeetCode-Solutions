#include <iostream>
using namespace std;

bool canJump(int nums[], int noOfSteps);

int main()
{
    int noOfSteps, i = 0;
    cin >> noOfSteps;
    
    int nums[noOfSteps];
    
    for(; i < noOfSteps; i++)
    {
        cin >> nums[i];
    }
    
    cout << (canJump(nums, noOfSteps) == 0 ? "false" : "true");

    return 0;
}

bool canJump(int nums[], int noOfSteps) 
{
    if(noOfSteps == 1) return true;

    int max_steps = 0, i = 0;

    for(; i < noOfSteps; i++)
    {
        if(max_steps < i) return false;
        
        max_steps = max(max_steps, (nums[i] + i));
    }
    
    return true;
}