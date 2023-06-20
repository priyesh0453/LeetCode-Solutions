#include <iostream>
using namespace std;

int main()
{
    int start, goal;
    cin >> start >> goal;
    
    cout << __builtin_popcount((start ^ goal));
    
    return 0;
}