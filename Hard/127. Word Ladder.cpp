/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList);

int main()
{
    int noOfListItems, i = 0;
    string beginWord, endWord;
    cin >> beginWord >> endWord >> noOfListItems;
    
    vector <string> wordList(noOfListItems);
    
    for(; i < noOfListItems; i++)
    {
        cin >> wordList[i];
    }
    
    cout << ladderLength(beginWord, endWord, wordList);

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set <string> list(wordList.begin(), wordList.end());
    list.erase(beginWord);

    queue <pair <string, int>> temp;
    temp.push({beginWord, 1});  

    int noOfWords, i, wordLength = endWord.length();
    string tempWord; 
    char ch, c; 

    while(!temp.empty())
    {
        tempWord = temp.front().first;
        noOfWords = temp.front().second;

        if(tempWord == endWord) return noOfWords;

        temp.pop();

        for(i = 0; i < wordLength; i++)
        {
            ch = tempWord[i];

            for(c = 'a'; c <= 'z'; c++)
            {
                tempWord[i] = c;

                if(list.find(tempWord) != list.end())
                {
                    list.erase(tempWord);
                    temp.push({tempWord, (noOfWords + 1)});
                }
            }

            tempWord[i] = ch;
        }
    }

    return 0;
}