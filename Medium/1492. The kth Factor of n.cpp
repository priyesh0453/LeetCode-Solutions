#include <iostream>
#include <cmath>
using namespace std;

int kthFactor(int n, int k);

int main()
{
    int n, k;
    cin >> n >> k;

    cout << kthFactor(n, k);

    return 0;
}

int kthFactor(int n, int k) 
{
    int i = 1, counter = sqrt(n);

    for(; i <= counter; i++) if((n % i) == 0 && --k == 0) return i;

    i = i - 1;

    for(; i >= 1; i--)
    {
        if((i * i) == n) continue;
        if((n % i) == 0 && --k == 0) return (n / i);
    }

    return -1;
}