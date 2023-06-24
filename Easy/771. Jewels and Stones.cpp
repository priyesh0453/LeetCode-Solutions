#include <iostream>
using namespace std;

int numJewelsInStones(string jewels, string stones);

int main()
{
    string jewels, stones;
    cin >> jewels >> stones;
    
    cout << numJewelsInStones(jewels, stones);

    return 0;
}

int numJewelsInStones(string jewels, string stones) 
{
    int ans = 0, i = 0, noOfStones = stones.length(), noOfJewels = jewels.length();

    for(; i < noOfStones; i++)
    {
        if(jewels.find(stones[i]) < noOfJewels) ans++;
    }    

    return ans;
}