#include <iostream>
using namespace std;

void buildArray(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    buildArray(nums, size);

    return 0;
}

void buildArray(int nums[], int size) 
{
    int i = 0, max_Length = 1001;

    for(; i < size; i++)
    {
        nums[i] = (nums[i] + (nums[nums[i]] % max_Length) * max_Length);
    }
        
    for(i = 0; i < size; i++)
    {
        nums[i] /= max_Length;
        cout << nums[i] << ",";
    }
    cout << "\b";
}