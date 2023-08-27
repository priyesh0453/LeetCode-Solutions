#include <iostream>
#include <unordered_set>
using namespace std;

long long minimumPossibleSum(int n, int target);

int main()
{
    int n, target;
    cin >> n >> target;
    
    cout << minimumPossibleSum(n, target);

    return 0;
}

long long minimumPossibleSum(int n, int target) 
{
    long long minSum = 0;
    int num = 1;
    unordered_set <int> temp;
    
    while(n)
    {
        if(!temp.count(num) && !temp.count((target - num)))
        {
            minSum += num;
            temp.insert(num);
            temp.insert((target - num));
            
            n--;
        }
        
        num++;
    }
    
    return minSum;
}