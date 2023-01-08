#include <iostream>
#include <climits>
using namespace std;

int reverse(int x);

int main()
{
    int x;
    cin >> x;
    
    cout << reverse(x);

    return 0;
}

int reverse(int x) 
{
    string str;
    int i = 0, noOfDigits, noOfIterations;

    if(x == 0 || x == INT_MIN || x == INT_MAX) return 0;
        
    str = (x > 0) ? to_string(x) : to_string(x * (-1));
    noOfDigits = str.size();
    noOfIterations = noOfDigits / 2;

    for(; i < noOfIterations; i++)
    {
        swap(str[i], str[noOfDigits - i - 1]);
    }
        
    if(stol(str) > INT_MAX) return 0;
    else
    {
        if(x < 0) return (-1 * stoi(str));
        else return stoi((str));
    }
    
    return 0;
}