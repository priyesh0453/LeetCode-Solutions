#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkShippingPoss(vector <int>& weights, int noOfPackage, int mid, int days);
int shipWithinDays(vector<int>& weights, int noOfPackage, int days);

int main()
{
    int noOfPackage, days, i = 0;
    cin >> noOfPackage >> days;
    
    vector <int> weights(noOfPackage);
    
    for(; i < noOfPackage; i++)
    {
        cin >> weights[i];
    }
    
    cout << shipWithinDays(weights, noOfPackage, days);

    return 0;
}

int shipWithinDays(vector<int>& weights, int noOfPackage, int days) 
{
    int low = *max_element(weights.begin(), weights.end()), high = 0, mid, i = 0;

    for(; i < noOfPackage; i++)
    {
        high += weights[i];
    }

    while(low < high)
    {
        mid = low + (high - low) / 2;

        if(checkShippingPoss(weights, noOfPackage, mid, days)) high = mid;
        else low = (mid + 1);
    } 

    return low;       
} 

bool checkShippingPoss(vector <int>& weights, int noOfPackage, int mid, int days)
{
    int i = 0, temp = 0;

    for(; i < noOfPackage; i++)
    {
        if(weights[i] > mid) return false;

        if((temp + weights[i]) > mid)
        {
            days--;
            temp = 0;
        }

        temp += weights[i];
    }

    return (days >= 1);
}