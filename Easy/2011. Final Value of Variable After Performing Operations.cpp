#include <iostream>
#include <vector>
using namespace std;

int finalValueAfterOperations(vector<string>& operations, int noOfOperations);

int main()
{
    int noOfOperations, i = 0;
    cin >> noOfOperations;
    
    vector <string> operations(noOfOperations);
    
    for(; i < noOfOperations; i++)
    {
        cin >> operations[i];
    }
    
    cout << finalValueAfterOperations(operations, noOfOperations);

    return 0;
}

int finalValueAfterOperations(vector<string>& operations, int noOfOperations) 
{
    int i = 0, ans = 0;

    for(; i < noOfOperations; i++)
    {
        if(operations[i][0] == '+' || operations[i][1] == '+') ans++;
        else ans--;
    }    

    return ans;
}