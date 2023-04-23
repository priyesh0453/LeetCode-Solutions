class Solution 
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            int length = nums.size(), a = 0, b, c, d;
            long long tempSum;
            vector <vector <int>> fourSum;

            sort(nums.begin(), nums.end());

            for(; a < length; a++)
            {
                if(a != 0 && (nums[a] == nums[(a - 1)])) continue;

                for(b = (a + 1); b < length; b++)
                {
                    if(b != (a + 1) && (nums[b] == nums[(b - 1)])) continue;

                    c = (b + 1), d = (length - 1);

                    while(c < d)
                    {
                        tempSum = nums[a];
                        tempSum += nums[b];
                        tempSum += nums[c];
                        tempSum += nums[d];

                        if(tempSum < target) c++;
                        else if(tempSum > target) d--;
                        else
                        {
                            fourSum.push_back({nums[a], nums[b], nums[c], nums[d]});
                            c++, d--;

                            while(c < d && (nums[c] == nums[(c - 1)])) c++;
                            while(c < d && (nums[d] == nums[(d + 1)])) d--;
                        }
                    }
                }
            }

            return fourSum;    
        }
};