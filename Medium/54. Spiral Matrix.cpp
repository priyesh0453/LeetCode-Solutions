class Solution 
{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) 
        {
            int m = matrix.size(), n = matrix[0].size(), i, top = 0, left = 0, bottom = (m - 1), right = (n - 1);
            vector <int> output;
    
            while(top <= bottom && left <= right)
            {
                for(i = left; i <= right; i++) output.push_back(matrix[top][i]);
                top++;
    
                for(i = top; i <= bottom; i++) output.push_back(matrix[i][right]);
                right--;
    
                if(top <= bottom)
                {
                    for(i = right; i >= left; i--) output.push_back(matrix[bottom][i]);
                    bottom--;
                }
    
                if(left <= right)
                {
                    for(i = bottom; i >= top; i--) output.push_back(matrix[i][left]);
                    left++;
                }
            }
    
            return output;    
        }
};