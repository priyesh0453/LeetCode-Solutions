#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int noOfElements, int k);

int main()
{
    int noOfElements, k, i = 0;
    cin >> noOfElements >> k;
    
    vector <int> arr(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> arr[i];
    }
    
    cout << findKthPositive(arr, noOfElements, k);

    return 0;
}

int findKthPositive(vector<int>& arr, int noOfElements, int k) 
{
    int left_Index = 0, right_Index = (noOfElements - 1), mid_Index, noOfMissing;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (right_Index - left_Index) / 2;
        noOfMissing = arr[mid_Index] - mid_Index - 1;

        if(noOfMissing < k) left_Index = mid_Index + 1;
        else right_Index = mid_Index - 1;
    }    

    return left_Index + k;
}