#include <iostream>
#include <set>
using namespace std;

string longestCommonPrefix(string strs[], int noOfWords);

int main(void)
{
    int noOfWords, i = 0;
    cin >> noOfWords;
    
    string strs[noOfWords];
    
    for(; i < noOfWords; i++)
    {
        cin >> strs[i];
    }
    
    cout << longestCommonPrefix(strs, noOfWords);

    return 0;
}

string longestCommonPrefix(string strs[], int noOfWords) 
{
    int i = 0; 

    if(noOfWords == 0) return "";
    else if(noOfWords == 1) return strs[0];
    else
    {
        int shortestLength = strs[i].size(), j;
        string longestPrefix;

        for(; i < shortestLength; i++)
        {
            longestPrefix = strs[0].substr(0, (i+1));
            for(j = 0; j < noOfWords; j++)
            {
                if(longestPrefix != strs[j].substr(0, (i+1)))
                {
                    if(longestPrefix.size() == 1) return "";
                    else return longestPrefix.substr(0, i);
                }
            }
                
        }
        return longestPrefix;
    }   
    return "";
}