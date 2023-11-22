class Solution 
{
  public:
    vector<int> findDiagonalOrder(vector <vector <int>>& nums) 
    {
        vector <int> diagonalOrder;
        int noOfRows = nums.size(), i = noOfRows - 1, j, maxSum = 0;
        unordered_map <int, vector <int>> sumMap;

        for(; i >= 0; i--)
        {
            for(j = 0; j < nums[i].size(); j++)
            {
                maxSum = max(maxSum, (i + j));
                sumMap[(i + j)].push_back(nums[i][j]);
            }
        }

        for(i = 0; i <= maxSum; i++)
        {
            for(auto iterator: sumMap[i])
            {
                diagonalOrder.push_back(iterator);
            }
        }

        return diagonalOrder;
    }
};