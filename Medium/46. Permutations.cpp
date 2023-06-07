#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums, int size);
vector <vector <int>> output;

int main()
{
    int size, i = 0, j;
    cin >> size;
    
    vector <int> nums(size);
    
    for(; i < size; i++)
    {
        cin >> nums[i];
    }
    
    permute(nums, size);
    
    int temp = output.size();
    
    for(i = 0; i < temp; i++)
    {
        for(j = 0; j < size; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> permute(vector<int>& nums, int size) 
{
    sort(nums.begin(), nums.end());

    output.push_back(nums);

    while(next_permutation(nums.begin(), nums.end()) != 0)
    {
        output.push_back(nums);
    }

    return output;
}