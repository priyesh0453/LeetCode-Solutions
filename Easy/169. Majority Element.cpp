#include <iostream>
using namespace std;

int majorityElement(int nums[], int n);

int main(void)
{
    int n, i = 0;
    cin >> n;
    
    int nums[n];
    
    for(; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << majorityElement(nums, n);

    return 0;
}

int majorityElement(int nums[], int n) 
{
    //Moore's Voting Algoithm
        
    int i = 0, num, count = 0;

    for(; i < n; i++)
    {
        if(count == 0)
        {
            num = nums[i];
            count++;
        }
        else if(nums[i] == num) count++;
        else count--;
    }

    return num;    
}