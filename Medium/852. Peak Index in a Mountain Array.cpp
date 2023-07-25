#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector <int>& arr, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> arr(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> arr[i];
    }
    
    cout << peakIndexInMountainArray(arr, noOfElements);

    return 0;
}

int peakIndexInMountainArray(vector <int>& arr, int noOfElements) 
{
    int left_Index = 0, right_Index = noOfElements - 1, mid_Index;

    while(left_Index <= right_Index)
    {
        mid_Index = left_Index + (right_Index - left_Index) / 2;

        if(arr[mid_Index] < arr[mid_Index + 1]) left_Index = mid_Index + 1;
        else right_Index = mid_Index - 1;
    }    

    return left_Index;
}