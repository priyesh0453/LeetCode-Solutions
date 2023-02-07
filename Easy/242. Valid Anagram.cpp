#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t);

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    
    cout << isAnagram(s, t);

    return 0;
}

bool isAnagram(string s, string t) 
{
    int t_length = t.length(), s_length = s.length();

    if(t_length != s_length) return false;

    vector <int> t_map(26, 0), s_map(26, 0);
    int i = 0;

    for(; i < t_length; i++)
    {
        t_map[t[i] - 'a']++;
        s_map[s[i] - 'a']++;
    }

    if(t_map == s_map) return true;

    return false;
}