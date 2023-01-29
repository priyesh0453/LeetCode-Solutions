#include <iostream>
using namespace std;

int Jump(int nums[], int noOfSteps);

int main()
{
    int noOfSteps, i = 0;
    cin >> noOfSteps;
    
    int nums[noOfSteps];
    
    for(; i < noOfSteps; i++)
    {
        cin >> nums[i];
    }
    
    cout << Jump(nums, noOfSteps);

    return 0;
}

int Jump(int nums[], int noOfSteps) 
{
    if(noOfSteps == 1) return 0;

    int i = 0, minJumps = 0, start = -1, end = 0, counter = (noOfSteps - 1);

    for(;; i++)
    {
        if(end >= counter) break;

        if(i > start)
        {
            minJumps++;
            start = end;
        }
        end = max(end, (nums[i] + i));
    }
    
    return minJumps;
}