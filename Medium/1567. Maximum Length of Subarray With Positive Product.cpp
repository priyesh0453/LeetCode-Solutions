#include <iostream>
using namespace std;

int getMaxLen(int nums[], int size);

int main()
{
    int size, i = 0;
    cin >> size;
    
    int nums[size];
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    cout << getMaxLen(nums, size);

    return 0;
}

int getMaxLen(int nums[], int size) 
{
    int maxLength = 0, i = 0, startIndex = 0, endIndex = 0, first_neg_index, last_neg_index, noOfNegatives;

    for(; i < size; i = endIndex + 1)
    {
        startIndex = i;

        while((startIndex < size) && (nums[startIndex] == 0)) startIndex++;

        endIndex = startIndex;
        noOfNegatives = 0;
        first_neg_index = -1, last_neg_index = -1;

        while((endIndex < size) && (nums[endIndex] != 0))
        {
            if(nums[endIndex] < 0)
            {
                noOfNegatives++;
                if(first_neg_index == -1) first_neg_index = endIndex;
                last_neg_index = endIndex; 
            }
            endIndex++;
        }

        if((noOfNegatives % 2) == 0) maxLength = max(maxLength, (endIndex - startIndex));
        else
        {
            if(first_neg_index != -1) maxLength = max(maxLength, (endIndex - first_neg_index - 1));
            if(last_neg_index != -1) maxLength = max(maxLength, (last_neg_index - startIndex));
        }           
    }

    return maxLength;
}