#include <iostream>
using namespace std;

int smallestEvenMultiple(int n);

int main()
{
    int n;
    cin >> n;
    
    cout << smallestEvenMultiple(n);

    return 0;
}

int smallestEvenMultiple(int n) 
{
    if(n % 2 == 0) return n;
    return (n * 2);    
}