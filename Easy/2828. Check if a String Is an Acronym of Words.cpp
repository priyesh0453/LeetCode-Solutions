#include <iostream>
#include <vector>
using namespace std;

bool isAcronym(vector<string>& words, int noOfWords, string s);

int main()
{
    string s;
    int noOfWords, i = 0;
    
    cin >> s >> noOfWords;
    
    vector <string> words(noOfWords);
    
    for(; i < noOfWords; i++)
    {
        cin >> words[i];
    }
    
    cout << isAcronym(words, noOfWords, s);

    return 0;
}

bool isAcronym(vector<string>& words, int noOfWords, string s) 
{
    int i = 0;
    string acronym;
    
    for(; i < noOfWords; i++)
    {
        acronym += words[i][0];
    }
    
    return (acronym == s);
}