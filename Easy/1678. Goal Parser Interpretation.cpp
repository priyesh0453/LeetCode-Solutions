#include <iostream>
using namespace std;

string interpret(string command);

int main()
{
    string command;
    cin >> command;
    
    cout << interpret(command);

    return 0;
}

string interpret(string command) 
{
    int length = command.length(), i = 0;
    string interpretation;

    for(; i < length; i++)
    {
        if(command[i] == 'G') interpretation += 'G';
        else if(command[i] == '(')
        {
            if(command[(i+1)] == ')') interpretation += 'o';
            else interpretation += "al";
        }
    }    

    return interpretation;
}