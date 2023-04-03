#include <iostream>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k);

int main(void)
{
    int k;
    string s;
    
    cin >> k;
    cin >> s;
    
    cout << reverseStr(s, k);

    return 0;
}

string reverseStr(string s, int k) 
{    
    int length = s.length(), start = 0, end = min(k, length);
        
    while(start < length)
    {    
        reverse(s.begin() + start, s.begin() + end);
        start += (2 * k);
        end = min(k + start, length);
    }

    return s;
}