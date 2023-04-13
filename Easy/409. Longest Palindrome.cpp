#include <iostream>
#include <map>
using namespace std;

int longestPalindrome(string s);

int main(void)
{
    string s;
    cin >> s;
    
    cout << longestPalindrome(s);

    return 0;
}

int longestPalindrome(string s) 
{
    int length = s.length();

    if(length == 1) return 1;

    map <char, int> freqCount;
    int i = 0, longestLength = 0, checkOdd = 0;

    for(; i < length; i++)
    {
        freqCount[s[i]]++;
    }

    for(auto iterator : freqCount)
    {
        if(iterator.second % 2 == 0) longestLength += iterator.second;
        else
        {
            checkOdd = 1;
            longestLength += iterator.second - 1;
        }
    }

    if(checkOdd == 1) longestLength++;

    return longestLength;
}