#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

bool wordBreak(string s, string wordDict[], int noOfWords);

int main()
{
    string s;
    int noOfWords, i = 0;
    
    cin >> s;
    cin >> noOfWords;
    
    string wordDict[noOfWords];
    
    for(; i < noOfWords; i++)
    {
        cin >> wordDict[i];
    }
    
    cout << wordBreak(s, wordDict, noOfWords);

    return 0;
}

bool wordBreak(string s, string wordDict[], int noOfWords) 
{
    vector <string> wordDictionary;
    int i = 0;
    
    for (; i < noOfWords; i++) 
    {
        wordDictionary.push_back(wordDict[i]);
    }

    int length = s.length(), dp[(length + 1)], j;
    i = 1;
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    set <string> words;
    string temp;

    for(auto iterator : wordDictionary)
    {
        words.insert(iterator);
    }

    for(; i <= length; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if((words.find(s.substr(j, (i - j))) != words.end()) && (dp[j] == 1)) 
            {
                dp[i] = 1;
                break;
            }
        }      
    }

    return dp[length];
}