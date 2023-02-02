#include <iostream>
#include <unordered_map>
using namespace std;

bool isAlienSorted(string words[], int noOfWords, string order);

int main()
{
    int noOfWords, i = 0;
    string order;
    
    cin >> noOfWords;
    
    string words[noOfWords];
    
    for(; i < noOfWords; i++)
    {
        cin >> words[i];
    }
    
    cin >> order;
    
    cout << isAlienSorted(words, noOfWords, order);

    return 0;
}

bool isAlienSorted(string words[], int noOfWords, string order) 
{
    if(noOfWords == 1) return true;

    unordered_map <char, int> AlienOrder;
    int i = 0, noOfCompares = noOfWords - 1, minNoOfChecks, j;
    string str1, str2;

    for(; i < 26; i++)
    {
        AlienOrder[order[i]] = i;
    }

    i = 0;

    for(; i < noOfCompares; i++)
    {
        str1 = words[i];
        str2 = words[(i + 1)];

        minNoOfChecks = min(str1.length(), str2.length());

        for(j = 0; j < minNoOfChecks; j++)
        {
            if(AlienOrder[str1[j]] < AlienOrder[str2[j]]) break;
            else if(AlienOrder[str1[j]] > AlienOrder[str2[j]]) return false;
        }

        if((str1.length() > str2.length()) && (str1.find(str2) != string::npos)) return false; 
    }

    return true;
}