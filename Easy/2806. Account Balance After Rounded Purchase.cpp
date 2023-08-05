#include <iostream>
using namespace std;

int main()
{
    int purchaseAmount;
    cin >> purchaseAmount;
    
    int roundedAmount = (purchaseAmount % 10 >= 5) ? ((purchaseAmount / 10) + 1) * 10  : (purchaseAmount / 10) * 10;
        
    cout << "Account Balance: " << (100 - roundedAmount);

    return 0;
}
