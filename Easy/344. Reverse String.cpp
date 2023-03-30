#include <iostream>
using namespace std;

void reverseString(char s[], int length);

int main(void)
{
    int length, i = 0;
    cin >> length;
    
    char s[length];
    
    for(; i < length; i++)
    {
        cin >> s[i];
    }
    
    reverseString(s, length);
    cout << s;

    return 0;
}

void reverseString(char s[], int length) 
{
    int i = 0, noOfIterations = (length / 2);

    for(; i < noOfIterations; i++)
    {
        swap(s[i], s[length - i - 1]);
    }       
}