#include <iostream>
#include <unordered_set>
using namespace std;

int minimumSum(int n, int k);

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    cout << minimumSum(n, k);

    return 0;
}

int minimumSum(int n, int k) 
{
    int i = 1, minSum = 0;
    unordered_set <int> temp;

    for(; n; i++)
    {
        if(!temp.count((k - i)) && !temp.count(i))
        {
            minSum += i;
            temp.insert((k - i));
            temp.insert(i);
            n--;
        }
    }

    return minSum;
}