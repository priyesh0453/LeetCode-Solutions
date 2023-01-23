#include <iostream>
using namespace std;

bool divisorGame(int n);

int main()
{
    int n;
    cin >> n;
    
    cout << divisorGame(n);

    return 0;
}

bool divisorGame(int n) 
{
    return ((n % 2) == 0);
}