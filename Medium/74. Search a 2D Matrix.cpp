class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size(), n = matrix[0].size(), left_Index = 0, right_Index = (m * n - 1), mid_Index, temp_row, temp_col;
    
            while(left_Index <= right_Index)
            {
                mid_Index = left_Index + (-left_Index + right_Index) / 2;
    
                temp_row = mid_Index / n;
                temp_col = mid_Index % n;
    
                if(target == matrix[temp_row][temp_col]) return true;
                if(target < matrix[temp_row][temp_col]) right_Index = mid_Index - 1;
                else left_Index = mid_Index + 1;
            }
    
            return false;    
        }
};