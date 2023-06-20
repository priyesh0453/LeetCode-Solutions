#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int n);

int main()
{
    int n;
    cin >> n;
    
    cout << isPowerOfTwo(n);
    
    return 0;
}

bool isPowerOfTwo(int n) 
{
    if(n == 1) return true;
    if(n <= 0 || (n % 2 != 0)) return false;

    if((float)log2(n) == (int)log2(n)) return true;
    else return false;    
}