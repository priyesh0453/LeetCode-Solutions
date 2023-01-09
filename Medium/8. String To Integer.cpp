#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string s);

int main()
{
    string s;
    cin >> s;
    
    cout << myAtoi(s);

    return 0;
}

int myAtoi(string s) 
{
    int i = 0, j = 0, length = s.size();
    double number = 0;

    if(s.empty()) return 0;

    while(s.at(j) == ' ') 
    {
        j++;
        
        if(j == length) return 0;
    }
       
    s = s.substr(j);

    char ch = s.at(i);
    length = s.size();

    if(ch == '+' || ch == '-' || (ch >= '0' && ch <= '9'))
    {
        if(ch == '+' || ch == '-') i++;    

        for(; i < length; i++)
        {
            ch = s.at(i);

            if(ch >= '0' && ch <= '9')
            {
                number = (number * 10) + (ch - '0');
            }
            else break;
        }

        if(s.at(0) == '-')
        {
            number *= -1;

            if(number < INT_MIN) return INT_MIN;
            return (int) number;
        }
        else
        {
            if(number > INT_MAX) return INT_MAX;
            return (int) number;
        }
    }

    return 0;
}