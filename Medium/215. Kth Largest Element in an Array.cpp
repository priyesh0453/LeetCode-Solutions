#include <iostream>
#include <queue>
using namespace std;

int findKthLargest(int nums[], int length, int k);

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
    
    cout << findKthLargest(nums, length, k);

    return 0;
}

int findKthLargest(int nums[], int length, int k) 
{
    priority_queue <int, vector <int>, greater <int>> minHeap;

    int i = 0;

    for(; i < length; i++)
    {
        if(minHeap.size() < k) minHeap.push(nums[i]);
        else
        {
            if(minHeap.top() < nums[i])
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
    }   

    return minHeap.top(); 
}