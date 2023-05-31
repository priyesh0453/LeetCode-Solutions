#include <iostream>
using namespace std;

bool checkPossibleMaking(int bloomDay[], int m, int k, int n, int mid);
int minDays(int bloomDay[], int m, int k, int n);

int main()
{
    int n, m, k, i = 0;
    cin >> n >> m >> k;
    
    int bloomDay[n];
    
    for(; i < n; i++)
    {
        cin >> bloomDay[i];
    }
    
    cout << minDays(bloomDay, m, k, n);

    return 0;
}

int minDays(int bloomDay[], int m, int k, int n) 
{
    if((long long)m * k > n) return -1;

    int low = 1, high = 1e9, mid;

    while(low < high)
    {
        mid = low + (high - low) / 2;

        if(checkPossibleMaking(bloomDay, m, k, n, mid)) high = mid;
        else low = mid + 1;
    }

    return low;
}

bool checkPossibleMaking(int bloomDay[], int m, int k, int n, int mid)
{
    int i = 0, noOfAdjFlowers = 0;

    for(; i < n; i++)
    {
        if(bloomDay[i] <= mid)
        {
            noOfAdjFlowers++;

            if(noOfAdjFlowers == k)
            {
                m--;
                noOfAdjFlowers = 0;
            }
        }
        else noOfAdjFlowers = 0;

        if(m <= 0) return true;
    }

    return false;
}