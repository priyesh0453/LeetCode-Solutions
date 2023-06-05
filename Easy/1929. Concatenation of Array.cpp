#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums, int n);

int main()
{
    int n, i = 0;
    cin >> n;
    
    vector <int> nums(n);
    
    for(; i < n; i++)
    {
        cin >> nums[i];
    }
    
    vector <int> ans = getConcatenation(nums, n);
    
    int temp = (2 * n);
    
    for(i = 0; i < temp; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

vector<int> getConcatenation(vector<int>& nums, int n) 
{
    int i = 0;
    vector <int> ans (2 * n);
    
    for(; i < n; i++)
    {
        ans[i] = nums[i];
        ans[(i + n)] = nums[i];
    }

    return ans;
}