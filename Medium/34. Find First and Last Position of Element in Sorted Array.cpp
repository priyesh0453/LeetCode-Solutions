class Solution {
private:
    int firstIndexSearch(vector <int> nums, int target, int size)
    {
        int left_Index = 0, right_Index = (size - 1), mid_Index, index = -1;
        
        while(left_Index <= right_Index)
        {
            mid_Index = left_Index + (-left_Index + right_Index) / 2;
            
            if(target <= nums[mid_Index]) right_Index = mid_Index - 1;
            else left_Index = mid_Index + 1;

            if(target == nums[mid_Index]) index = mid_Index;
        }

        return index;
    }
private:
    int lastIndexSearch(vector <int> nums, int target, int size)
    {
        int left_Index = 0, right_Index = (size - 1), mid_Index, index = -1;
        
        while(left_Index <= right_Index)
        {
            mid_Index = left_Index + (-left_Index + right_Index) / 2;
            
            if(target >= nums[mid_Index]) left_Index = mid_Index + 1;
            else right_Index = mid_Index - 1;

            if(target == nums[mid_Index]) index = mid_Index;
        }

        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int size = nums.size(), firstIndex = firstIndexSearch(nums, target, size), lastIndex;

        if(firstIndex == -1) lastIndex = -1;
        else lastIndex = lastIndexSearch(nums, target, size);
        
        return {firstIndex, lastIndex};
    }
};