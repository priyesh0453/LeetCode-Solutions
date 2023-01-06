#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    string s;
    cin >> s;
    
    cout << lengthOfLongestSubstring(s);

    return 0;
}

int lengthOfLongestSubstring(string s) 
{
    int maxLength = 0, startIndex = 0, endIndex = 0, stringLength = s.length();
    set <char> uniqueCharacters;

    for(; startIndex < stringLength;)
    {
        if(uniqueCharacters.find(s[startIndex]) != uniqueCharacters.end())
        {
            uniqueCharacters.erase(s[endIndex]);
            endIndex++;
        }
        else
        {
            uniqueCharacters.insert(s[startIndex]);

            if((startIndex - endIndex + 1) > maxLength)
            {
                maxLength = startIndex - endIndex + 1;
            }

            startIndex++;
        }
    }
    
    return maxLength;
}