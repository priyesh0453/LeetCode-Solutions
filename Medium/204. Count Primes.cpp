#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n);

int main()
{
    int n;
    cin >> n;
    
    cout << countPrimes(n);

    return 0;
}

int countPrimes(int n) 
{
    int totalPrimes = 0, i = 2, j;
    vector <int> primeCheck((n + 1), 1);

    for(; (i * i) <= n; i++)
    {
        if(primeCheck[i] == 1)
        {
            for(j = (i * i); j <= n; j += i)
            {
                primeCheck[j] = 0;
            }
        }
    }

    for(i = 2; i < n; i++)
    {
        if(primeCheck[i] == 1) totalPrimes++;
    }

    return totalPrimes;    
}