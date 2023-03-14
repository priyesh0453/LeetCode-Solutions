#include <iostream>
#include <unordered_map>
using namespace std;

char repeatedCharacter(string s);

int main(void)
{
    string s;
    cin >> s;
    
    cout << repeatedCharacter(s);

    return 0;
}

char repeatedCharacter(string s) 
{
    unordered_map <char,int> freq;
    int length = s.length(), i = 0;

    for(auto iterator : s)
    {
        if(freq.find(iterator) != freq.end()) return iterator;

        freq[iterator]++;
    }

    return '\0';
}