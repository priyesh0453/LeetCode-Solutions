#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mostWordsFound(vector<string>& sentences, int noOfSentences);

int main()
{
    int noOfSentences, i = 0;
    cin >> noOfSentences;
    cin.ignore();
    
    vector <string> sentences(noOfSentences);
    
    for(; i < noOfSentences; i++)
    {
        getline(cin, sentences[i]);
    }
    
    cout << mostWordsFound(sentences, noOfSentences);

    return 0;
}

int mostWordsFound(vector<string>& sentences, int noOfSentences) 
{ 
    int i = 0, noOfWords = 0, maxWords = 0;

    for(; i < noOfSentences; i++)
    {
        noOfWords = count(sentences[i].begin(), sentences[i].end(), ' ') + 1;
        maxWords = max(maxWords, noOfWords);
    }   

    return maxWords;
}