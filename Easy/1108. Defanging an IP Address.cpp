#include <iostream>
using namespace std;

string defangIPaddr(string address);

int main()
{
    string address;
    cin >> address;
    
    cout << defangIPaddr(address);

    return 0;
}

string defangIPaddr(string address) 
{  
    string output;
    int i = 0, length = address.length();

    for(; i < length; i++)
    {
        if(address[i] != '.') output += address[i];
        else output += "[.]";
    }

    return output;
}