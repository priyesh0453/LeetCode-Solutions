#include <iostream>
using namespace std;

bool isPalindrome(int x) {
        
    if(x < 0) return false;
    else if( x >= 0 && x < 10) return true;
    else
    {
        string str = to_string(x);
        int noOfDigits = str.size(), i = 0, halfLength = noOfDigits / 2, counter = 0;

        for(; i < halfLength; i++)
        {
            if(str[i] != str[(noOfDigits - i - 1)])
            {
                counter = 1;
                break;
            } 
        }
        if(counter == 0) return true;
    }
        
    return false;
}

int main()
{
    int num;
    cin >> num;
    
    cout << isPalindrome(num);
    
    return 0;
}
