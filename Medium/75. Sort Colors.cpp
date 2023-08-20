#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector <int>& nums, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> nums(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    sortColors(nums, noOfElements);

    return 0;
}

void sortColors(vector <int>& nums, int noOfElements) 
{
    int start_Index = 0, end_Index = (noOfElements - 1), temp_Index = 0;

    while(temp_Index <= end_Index)
    {
        if(!nums[temp_Index])
        {
            swap(nums[start_Index], nums[temp_Index]);
            start_Index++;
            temp_Index++;
        }
        else if(nums[temp_Index] == 2)
        {
            swap(nums[end_Index], nums[temp_Index]);
            end_Index--;
        }
        else temp_Index++;
    }    
}