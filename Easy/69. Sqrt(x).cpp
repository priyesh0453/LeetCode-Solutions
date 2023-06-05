#include <iostream>
using namespace std;

int mySqrt(int x);

int main()
{
    int x, i = 0;
    cin >> x;
    
    cout << mySqrt(x);

    return 0;
}

int mySqrt(int x) 
{
    if(x == 0) return x;

    long int low = 1, high = x, mid, temp;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        temp = (long)(mid * mid);

        if(temp == x) return mid;
        if((temp < x) && ((mid + 1)*(mid + 1) > x)) return mid;

        if(temp < x) low = mid;
        else high = mid;
    }

    return low;
}