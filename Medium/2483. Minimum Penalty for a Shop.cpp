#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int bestClosingTime(string customers);

int main()
{
    string customers;
    cin >> customers;
    
    cout << bestClosingTime(customers);

    return 0;
}

int bestClosingTime(string customers) 
{
    int noOfHours = customers.length(), incomings = 0, prefixCount = 0, j = 0, requiredJ = 0, minPenalty = INT_MAX;
    unordered_map <int, int> tempPenalty;

    for(; j < noOfHours; j++)
    {
        if(customers[j] == 'Y') incomings++;
    }

    tempPenalty[0] = incomings;

    if(minPenalty > incomings)
    {
        minPenalty = incomings;
        requiredJ = 0;
    }

    for(j = 0; j < noOfHours; j++)
    {
        if(customers[j] == 'Y') prefixCount++;
        else prefixCount--;

        tempPenalty[(j + 1)] = incomings - prefixCount;

        if(minPenalty > tempPenalty[(j + 1)])
        {
            minPenalty = tempPenalty[j + 1];
            requiredJ = (j + 1);
        }
    }

    return requiredJ;
}