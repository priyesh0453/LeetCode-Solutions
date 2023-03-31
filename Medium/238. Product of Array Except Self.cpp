#include <iostream>
#include <cstring>
using namespace std;

void productExceptSelf(int nums[], int length);
void printArray(int output[], int length);

int main(void)
{
    int length, target, i = 0;
    cin >> length;
    
    int nums[length];
    
    for(; i < length; i++)
    {
        cin >> nums[i];
    }
    
    productExceptSelf(nums, length);

    return 0;
}

void productExceptSelf(int nums[], int length)
{
    int i = 1, counter = 1;

    int output[length];
    memset(output, 0, sizeof(output));

    output[0] = 1;

    for(; i < length; i++)
    {
        output[i] = output[(i - 1)] * nums[(i - 1)];
    }   

    i = (length - 1);
        
    for(; i >= 0; i--)
    {
        output[i] *= counter;
        counter *= nums[i];
    } 

    printArray(output, length);
}

void printArray(int output[], int length)
{
    int i = 0;
    
    for(; i < length; i++)
    {
        cout << output[i] << " ";
    }
    
    cout << endl;
}