#include <iostream>
#include <vector>
using namespace std;

void splitWordsBySeparator(vector<string>& words, int noOfWords, char separator, vector <string>&splitWords);

int main()
{
    int noOfWords, i = 0, tempLength;
    cin >> noOfWords;
    
    char separator;
    cin >> separator;
    
    vector <string> words(noOfWords), splitWords;
    
    for(; i < noOfWords; i++)
    {
        cin >> words[i];
    }
    
    splitWordsBySeparator(words, noOfWords, separator, splitWords);
    
    tempLength = splitWords.size();
    
    for(i = 0; i < tempLength; i++)
    {
        cout << splitWords[i] << " ";
    }

    return 0;
}

void splitWordsBySeparator(vector<string>& words, int noOfWords, char separator, vector <string>&splitWords) 
{
    int i = 0, j, length;
    string tempWord;
    
    while(i < noOfWords)
    {
        length = words[i].length();
        
        for(j = 0; j < length; j++)
        {
            if(words[i][j] == separator) 
            {
                if(!tempWord.empty()) splitWords.push_back(tempWord);
                tempWord = "";
            }
            else tempWord += words[i][j];
        }
        
        if(!tempWord.empty()) splitWords.push_back(tempWord);
        tempWord = "";
        i++;
    }
}