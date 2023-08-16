#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSlidingWindow(vector <int>& nums, int k, int noOfElements, vector <int>& maxSlidingWin);

int main()
{
    int k, noOfElements, i = 0, tempLength;
    cin >> k >> noOfElements;
    
    vector <int> nums(noOfElements), maxSlidingWin;
    
    for(; i < noOfElements; i++)
    {
        cin >> nums[i];
    }
    
    maxSlidingWindow(nums, k, noOfElements, maxSlidingWin);
    
    tempLength = maxSlidingWin.size();
    
    for(i = 0; i < tempLength; i++)
    {
        cout << maxSlidingWin[i] << " ";
    }
    
    return 0;
}

void maxSlidingWindow(vector <int>& nums, int k, int noOfElements, vector <int>& maxSlidingWin) 
{
    int i = 0;
    deque <int> tempDq;

    for(; i < noOfElements; i++)
    {
        if(!tempDq.empty() && tempDq.front() == (i - k)) tempDq.pop_front();

        while(!tempDq.empty() && nums[i] >= nums[tempDq.back()]) tempDq.pop_back();

        tempDq.push_back(i);

        if(i >= (k - 1)) maxSlidingWin.push_back(nums[tempDq.front()]); 
    }  
}