#include <iostream>
using namespace std;

int uniquePaths(int m, int n);

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    
    cout << uniquePaths(m, n);

    return 0;
}

int uniquePaths(int m, int n) 
{
    int noOfDirectionsReq = (m + n - 2), noOfSelectionsReq = (n - 1), i = 1;
    double noOfUniquePaths = 1;

    for(; i <= noOfSelectionsReq; i++)
    {
        noOfUniquePaths = (noOfUniquePaths * (noOfDirectionsReq - noOfSelectionsReq + i) ) / i;
    }    

    return (int) noOfUniquePaths;
}