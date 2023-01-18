#include <iostream>
using namespace std;

bool isSubsequence(string s, string t);

int main(void)
{
    string s, t;
    cin >> s;
    cin >> t;
    
    cout << isSubsequence(s, t);

    return 0;
}

bool isSubsequence(string s, string t) 
{
    if(s.compare("") == 0) return true; 
         
    int s_Length = s.size(), t_Length = t.size(), t_Index = 0, s_Index = 0;

    for(; t_Index < t_Length; t_Index++)
    {
        if(t.at(t_Index) == s.at(s_Index))
        {
            s_Index++;
        }
        if(s_Index == s_Length) return true;
    }  

    return false;
}