#include <iostream>
using namespace std;

string convert(string s, int numRows);

int main()
{
    int numRows;
    string s;
    
    cin >> numRows;
    cin >> s;
     
    cout << convert(s, numRows);

    return 0;
}

string convert(string s, int numRows) 
{
    int length = s.length();

    if(length == 1 || numRows == 1) return s;

    char pattern[numRows][length];
    string output = "";
    int j = 0, i, k = 0, counter = (numRows - 1), noOfColumns = 0;

    for(; j < length; j++)
    {
        if(k >= length)
        {
            noOfColumns = j;
            break;
        }
            
        if(counter == 0) counter = (numRows - 1);

        if(counter == (numRows - 1))
        {
            for(i = 0; i < numRows; i++)
            {
                if(k < length)
                {
                    pattern[i][j] = s[k];
                    k++;
                }
                else pattern[i][j] = '*';
            }
        }
        else
        {
            for(i = 0; i < numRows; i++)
            {
                if(counter == i && k < length)
                {
                    pattern[i][j] = s[k];
                    k++;
                }
                else pattern[i][j] = '*';
            }
        } 
        counter--;
    }    

    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j < noOfColumns; j++)
        {
            if(pattern[i][j] != '*') output += pattern[i][j];
        }
    }

    return output;
}