#include <iostream>
using namespace std;

int countOdds(int low, int high);

int main()
{
    int low, high;
    cin >> low;
    cin >> high;
    
    cout << countOdds(low, high);

    return 0;
}

int countOdds(int low, int high) 
{
    return (low % 2 == 0 && high % 2 == 0) ? ((high - low) / 2) : (((high - low) / 2) + 1);    
}