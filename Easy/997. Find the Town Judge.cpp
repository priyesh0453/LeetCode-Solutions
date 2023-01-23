#include <iostream>
#include <cstring>
using namespace std;

int findJudge(int noOfPeople, int noOfTrusts, int trust[][2]);

int main(void)
{
    int noOfPeople, noOfTrusts, i = 0, j;
    cin >> noOfPeople;
    cin >> noOfTrusts;
    
    int trust[noOfTrusts][2];
    
    for(; i < noOfTrusts; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> trust[i][j];
        }
    }
    
    cout << findJudge(noOfPeople, noOfTrusts, trust);

    return 0;
}

int findJudge(int noOfPeople, int noOfTrusts, int trust[][2]) 
{
    int count[(noOfPeople + 1)], i = 0, noOfTrustsReq = (noOfPeople - 1);
    memset(count, 0, sizeof(count));
    
    for(; i < noOfTrusts; i++)
    {
        count[trust[i][0]]--;
        count[trust[i][1]]++;
    }
    for(i = 1; i <= noOfPeople; i++)
    {
        if(count[i] == (noOfTrustsReq)) return i;
    } 

    return -1;
}