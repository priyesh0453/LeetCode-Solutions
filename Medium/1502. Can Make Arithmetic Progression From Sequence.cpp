#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr, int noOfElements);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> arr(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> arr[i];
    }
    
    cout << canMakeArithmeticProgression(arr, noOfElements);

    return 0;
}

bool canMakeArithmeticProgression(vector<int>& arr, int noOfElements)
{
    sort(arr.begin(), arr.end());
    
    int d = arr[1] - arr[0], i = 2;

    for(; i < noOfElements; i++)
    {
        if((arr[i] - arr[(i - 1)]) != d) return false;
    }   

    return true; 
}