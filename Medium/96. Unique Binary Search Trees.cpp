#include <iostream>
#include <cstring>
using namespace std;

int numTrees(int n);

int main()
{
    int n;
    
    cin >> n;
    
    cout << numTrees(n);

    return 0;
}

int numTrees(int n) 
{
    if(n == 1) return 1;

    int noOfUniqueBST[(n + 1)], i = 2, j;
    memset(noOfUniqueBST, 0, sizeof(noOfUniqueBST));

    noOfUniqueBST[0] = noOfUniqueBST[1] = 1; 

    for(; i <= n; i++)
    {
        for(j = 0; j < i; j++)
        {
            noOfUniqueBST[i] += noOfUniqueBST[j] * noOfUniqueBST[(i - 1 - j)];
        }
    }
        
    return noOfUniqueBST[n];
}