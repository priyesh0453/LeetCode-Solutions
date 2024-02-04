#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumAfterPartitioning(vector <int>& arr, int noOfElements, int k);

int main() 
{
    int noOfElements, k, i = 0;
    cin >> noOfElements >> k;

    vector <int> arr(noOfElements);
    
    for(; i < noOfElements; i++)
    {
        cin >> arr[i];
    }

    cout << maxSumAfterPartitioning(arr, noOfElements, k);

    return 0;
}

int maxSumAfterPartitioning(vector <int>& arr, int noOfElements, int k) 
{
    int i = noOfElements - 1, j, tempMax, counter;
    vector <int> dp(k + 1, 0);

    for(; i >= 0; i--) 
    {
        counter = 0;
        tempMax = 0;

        for(j = i; j < min(noOfElements, i + k); j++) 
        {
            counter = max(counter, arr[j]);
            tempMax = max(tempMax, ((j - i + 1) * counter) + dp[(j + 1) % k]);
        }

        dp[i % k] = tempMax;
    }

    return dp[0];
}