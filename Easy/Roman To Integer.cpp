#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) 
{
    unordered_map <char, int> conversionMap{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int converted = conversionMap[s.back()], i = 0, noOfIterations = s.length() - 1;
    
    for(; i < noOfIterations; i++)
    {
        if(conversionMap[s[i]] >= conversionMap[s[(i + 1)]])
        {
            converted += conversionMap[s[i]];
        }
        else
        {
            converted -= conversionMap[s[i]];
        }
    }
        
    return converted;
}

int main()
{
    string s;
    cin >> s;
    
    cout << romanToInt(s);
    
    return 0;
}