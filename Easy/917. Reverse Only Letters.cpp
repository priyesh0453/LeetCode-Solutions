#include <iostream>
using namespace std;

string reverseOnlyLetters(string s);

int main(void)
{
    string s;
    cin >> s;
    
    cout << reverseOnlyLetters(s);

    return 0;
}

string reverseOnlyLetters(string s)
{
    int length = s.length(), i = 0, start = 0, end = (length - 1);

    for(; i < length; i++)
    {
        if(start < end)
        {
            if(isalpha(s[start]) && isalpha(s[end])) 
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            else if(!isalpha(s[start]) && !isalpha(s[end]))
            {
                start++;
                end--;
            }
            else if(isalpha(s[start]) == 0) start++;
            else end--;
        }
        else break;
    }

    return s;    
}