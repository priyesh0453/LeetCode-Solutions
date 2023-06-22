#include <iostream>
using namespace std;

int minPartitions(string n);

int main()
{
    string n;
    cin >> n;
    
    cout << minPartitions(n);

    return 0;
}

int minPartitions(string n) 
{
    int i = 0, length = n.length(), minDecBin = 0;

    for(; i < length; i++)
    {
        minDecBin = max(minDecBin, (int)(n[i] - '0'));
    }     

    return minDecBin;
}