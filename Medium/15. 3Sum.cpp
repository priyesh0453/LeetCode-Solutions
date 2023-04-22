class Solution 
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            int length = nums.size(), i = 0, j, k, temp_Sum = 0;
            vector <vector <int>> ThreeSum;
            vector <int> temp;

            sort(nums.begin(), nums.end());

            for(; i < length; i++)
            {
                if((i != 0) && (nums[i] == nums[(i - 1)])) continue;

                j = (i + 1), k = (length - 1);

                while(j < k)
                {
                    temp_Sum = nums[i] + nums[j] + nums[k];

                    if(temp_Sum < 0) j++;
                    else if(temp_Sum > 0) k--;
                    else
                    {
                        ThreeSum.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;

                        while(j < k && (nums[j] == nums[(j - 1)])) j++;
                        while(j < k && (nums[k] == nums[(k + 1)])) k--;
                    }
                }
            }

            return ThreeSum;
        }
};