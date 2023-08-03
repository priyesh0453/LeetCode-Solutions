#include <iostream>
#include <vector>
using namespace std;

void findLetterCombinations(string current, vector <string>& letterComb, string mapping[], int num);
void letterCombinations(string digits, vector <string>& letterComb);

int main()
{
    string digits;
    cin >> digits;
    
    vector <string> letterComb;
    
    letterCombinations(digits, letterComb);
    
    int noOfCombinations = letterComb.size(), i = 0;
    
    for(; i < noOfCombinations; i++)
    {
        cout << letterComb[i] << " ";
    }
    
    return 0;
}

void letterCombinations(string digits, vector <string>& letterComb) 
{
    if(digits.length()) 
    {
        int num = stoi(digits);
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
        findLetterCombinations("", letterComb, mapping, num); 
    }
}

void findLetterCombinations(string current, vector <string>& letterComb, string mapping[], int num)
{
    if(!num)
    {
        letterComb.push_back(current);
        return;
    }

    string mapNum = mapping[(num % 10)];
    int tempLength = mapNum.length(), i = 0;

    for(; i < tempLength; i++)
    {
        findLetterCombinations(mapNum[i] + current, letterComb, mapping, (num / 10));
    }
}