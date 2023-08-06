#include <iostream>
#include <algorithm>
using namespace std;

string finalString(string s);

int main()
{
    string s;
    cin >> s;
    
    cout << finalString(s);

    return 0;
}

string finalString(string s) 
{
    int length = s.length(), i = 0;
    string output;
    
    for(; i < length; i++)
    {
        if(s[i] == 'i')
        {
            reverse(output.begin(), output.end());
        }
        else output += s[i];
    }
    
    return output;
}