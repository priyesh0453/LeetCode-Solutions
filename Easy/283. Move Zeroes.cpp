#include <iostream>
using namespace std;

void moveZeroes(int nums[], int length);
void printArray(int nums[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    moveZeroes(nums, length);

    return 0;
}

void moveZeroes(int nums[], int length) 
{
    int i = 0, zero_index = -1;

    for(; i < length; i++)
    {
        if(nums[i] == 0)
        {
            zero_index = i;
            break;
        }
    }

    if(zero_index == -1)
    {
        printArray(nums, length);
        return ;
    }

    i = zero_index + 1;

    for(; i < length; i++)
    {
        if(nums[i] != 0) 
        {
            swap(nums[i], nums[zero_index]);
            zero_index++;
        }
    }

    printArray(nums, length);    
}

void printArray(int nums[], int length)
{
    int i = 0;
    
    for(; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}