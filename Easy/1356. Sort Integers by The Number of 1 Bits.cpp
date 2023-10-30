#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int countSetBits(int x);
static bool comparator(int x, int y);
void printArr(vector <int>& arr);
void sortByBits(vector <int>& arr);

int main()
{
    int noOfElements, i = 0;
    cin >> noOfElements;
    
    vector <int> arr(noOfElements);

    for(; i < noOfElements; i++)
    {
        cin >> arr[i];
    }
    
    sortByBits(arr);
    
    return 0;
}
    
void sortByBits(vector <int>& arr) 
{ 
    int noOfElements = arr.size();
    vector <int> sortedArr = arr;

    sort(sortedArr.begin(), sortedArr.end(), comparator);

    printArr(sortedArr);
}

static bool comparator(int x, int y)
{
    /*
        __builtin_popcount too can be used for counting no. of set bits.
        Here, Brian Kerninghan's Algo is used for the same.

        'comparator' function should be static for this case as it doesn't need access to specific instance data of the class & static functions only can call static functions (in this case and usually).
    */

    int setCountsX = countSetBits(x), setCountsY = countSetBits(y);

    if(setCountsX == setCountsY) return x < y;
    else return setCountsX < setCountsY;
}

static int countSetBits(int x)
{
    int noOfSetBits = 0;

    while(x > 0)
    {
        x &= (x - 1);
        noOfSetBits++;
    }

    return noOfSetBits;
}

void printArr(vector <int>& arr)
{
    int i = 0, noOfElements = arr.size();
    
    for(; i < noOfElements; i++)
    {
        cout << arr[i] << " ";
    }
}