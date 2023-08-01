#include <iostream>
#include <vector>
using namespace std;

void findKSizeCombinations(int start, int n, int k, vector <vector <int>>& kSizedCombinations, vector <int>& tempCombination);
void combine(int n, int k, vector <vector <int>>& kSizedCombinations);

int main()
{
    int n, k, i = 0, j, tempLength;
    cin >> n >> k;
    
    vector <vector <int>> kSizedCombinations;
    
    combine(n, k, kSizedCombinations);
    
    tempLength = kSizedCombinations.size();
    
    for(; i < tempLength; i++)
    {
        for(j = 0; j < k; j++)
        {
            cout << kSizedCombinations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void combine(int n, int k, vector <vector <int>>& kSizedCombinations) 
{
    vector <int> tempCombination;

    findKSizeCombinations(1, n, k, kSizedCombinations, tempCombination);
}

void findKSizeCombinations(int start, int n, int k, vector <vector <int>>& kSizedCombinations, vector <int>& tempCombination)
{
    if(tempCombination.size() == k)
    {
        kSizedCombinations.push_back(tempCombination);
        return;
    }

    int i = start;

    for(; i <= n; i++)
    {
        tempCombination.push_back(i);
        findKSizeCombinations((i + 1), n, k, kSizedCombinations, tempCombination);
        tempCombination.pop_back();
    }
}