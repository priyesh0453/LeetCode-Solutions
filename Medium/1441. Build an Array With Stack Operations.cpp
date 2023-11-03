#include <iostream>
#include <vector>
using namespace std;

void printArr(vector <string>& arr);
void buildArray(vector <int>& target, int n, int noOfElements);

int main()
{
    int n, noOfElements, i = 0;
    cin >> n >> noOfElements;
    
    vector <int> target(noOfElements);

    for(; i < noOfElements; i++)
    {
        cin >> target[i];
    }
    
    buildArray(target, n, noOfElements);
    
    return 0;
}
    
void buildArray(vector <int>& target, int n, int noOfElements) 
{
    vector <string> stackOps;
    int indexCounter = 0, counter = 1;

    while(indexCounter < noOfElements)
    {
        stackOps.push_back("Push");

        if(target[indexCounter] != counter) stackOps.push_back("Pop");
        else indexCounter++;
        
        counter++;
    }

    printArr(stackOps);
}

void printArr(vector <string>& arr)
{
    int i = 0, noOfElements = arr.size();
    
    for(; i < noOfElements; i++)
    {
        cout << arr[i] << " ";
    }
}