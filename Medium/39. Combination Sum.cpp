#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector <int> candidates, int target, int index, vector <vector <int>>& combinations, vector <int> temp, int noOfNums);
void combinationSum(vector<int>& candidates, int target, int noOfNums);

int main()
{
    int noOfNums, target, i = 0;
    cin >> noOfNums >> target;
    
    vector <int> candidates(noOfNums);
    
    for(; i < noOfNums; i++)
    {
        cin >> candidates[i];
    }
    
    combinationSum(candidates, target, noOfNums);

    return 0;
}

void combinationSum(vector<int>& candidates, int target, int noOfNums) 
{
    int i = 0, j;
    vector <vector <int>> combinations;
    vector <int> temp;

    findCombinations(candidates, target, 0, combinations, temp, noOfNums);  

    int noOfCombinations = combinations.size(), tempLength;
    
    for(; i < noOfCombinations; i++)
    {
        tempLength = combinations[i].size();
        
        for(j = 0; j < tempLength; j++)
        {
            cout << combinations[i][j] << " ";
        }
        cout << endl;
    }
}

void findCombinations(vector <int> candidates, int target, int index, vector <vector <int>>& combinations, vector <int> temp, int noOfNums)
{
    if(index == noOfNums)
    {
        if(!target) combinations.push_back(temp);
        return;
    }

    if(candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        findCombinations(candidates, (target - candidates[index]), index, combinations, temp, noOfNums);
        temp.pop_back();
    }

    findCombinations(candidates, target, (index + 1), combinations, temp, noOfNums);
}