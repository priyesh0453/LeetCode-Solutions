class Solution 
{
    public:
        void nextPermutation(vector<int>& nums) 
        {
            int length = nums.size(), i = (length - 2), index = -1;
    
            for(; i >= 0; i--)
            {
                if(nums[i] < nums[(i + 1)])
                {
                    index = i;
                    break;
                }
            }
    
            if(index == -1) 
            {   
                reverse(nums.begin(), nums.end());    
                return;
            }
    
            i = (length - 1);
    
            for(; i >= 0; i--)
            {
                if(nums[i] > nums[index])
                {
                    swap(nums[i], nums[index]);
                    break;
                }
            } 
    
            reverse(nums.begin() + index + 1, nums.end());
        }
};