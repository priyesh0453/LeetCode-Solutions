#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool canCross(vector <int>& stones, int noOfStones);

int main()
{
    int noOfStones, i = 0;
    cin >> noOfStones;
    
    vector <int> stones(noOfStones);
    
    for(; i < noOfStones; i++)
    {
        cin >> stones[i];
    }
    
    cout << canCross(stones, noOfStones);

    return 0;
}

bool canCross(vector <int>& stones, int noOfStones) 
    {
        if(stones[1] != 1) return false;

        int i = 1;
        unordered_map <int, unordered_set <int>> temp;

        temp[1] = {1};

        for(; i < noOfStones; i++)
        {
            for(int k : temp[stones[i]])
            {
                temp[stones[i] + k].insert(k);
                temp[stones[i] + k - 1].insert(k - 1);
                temp[stones[i] + k + 1].insert(k + 1);
            }
        }   

        return temp[stones[noOfStones - 1]].size();
    }