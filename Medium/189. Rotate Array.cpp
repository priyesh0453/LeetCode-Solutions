#include <iostream>
#include <vector>
using namespace std;

void rotate(int nums[], int length, int k);

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
    
    rotate(nums, length, k);

    return 0;
}

void rotate(int nums[], int length, int k) 
{
    int noOfShifts = (k % length);
        
    if(noOfShifts == 0)
    {
        for(int i = 0; i < length; i++)
        {
            cout << nums[i] << " ";
        }
        return;
    }

    int counter = (length - noOfShifts), i = counter;
    vector <int> temp(noOfShifts);

    for(; i < length; i++)
    {
        temp[(i - counter)] = nums[i];
    }
        
    for(i = counter; i > 0; i--)
    {
        nums[(i + noOfShifts - 1)] = nums[i - 1];
    } 

    for(i = 0; i < noOfShifts; i++)
    {
        nums[i] = temp[i];
    }   

    for(i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}