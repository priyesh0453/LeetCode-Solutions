#include <iostream>
using namespace std;

string convertToTitle(int columnNumber);

int main()
{
    int columnNumber;
    cin >> columnNumber;
    
    cout << convertToTitle(columnNumber);

    return 0;
}

string convertToTitle(int columnNumber) 
    {
        string title;
        int temp, rem;

        while(columnNumber)
        {
            temp = (columnNumber - 1);
            rem = (temp % 26);

            title = char('A' + rem) + title;

            columnNumber = (temp / 26);
        }

        return title;
    }