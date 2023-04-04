class Solution 
{
    public:
        vector<vector<int>> generateMatrix(int n) 
        {
            int i, top = 0, left = 0, bottom = (n - 1), right = (n - 1), k = 1;
            vector <vector <int>> output (n, vector <int> (n));
        
            while(top <= bottom && left <= right)
            {
                for(i = left; i <= right; i++) output[top][i] = k++;
                top++;
        
                for(i = top; i <= bottom; i++) output[i][right] = k++;
                right--;
        
                if(top <= bottom)
                {
                    for(i = right; i >= left; i--) output[bottom][i] = k++;
                    bottom--;
                }
        
                if(left <= right)
                {
                    for(i = bottom; i >= top; i--) output[i][left] = k++;
                    left++;
                }
            }
        
            return output;    
        }
};