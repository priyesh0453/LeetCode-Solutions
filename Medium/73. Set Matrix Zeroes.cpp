class Solution 
{
    public:
        void setZeroes(vector<vector<int>>& matrix) 
        {
            int m = matrix.size(), n = matrix[0].size(), i = 0, j, col_0 = 1;
    
            for(; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        
                        if(j != 0) matrix[0][j] = 0;
                        else col_0 = 0;
                    }
                }
            }
    
            for(i = 1; i < m; i++)
            {
                for(j = 1; j < n; j++)
                {
                    if(matrix[i][j] != 0)
                    {
                        if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
                    }
                }
            }
    
            if(matrix[0][0] == 0)
            {
                for(j = 0; j < n; j++) matrix[0][j] = 0;
            }
    
            if(col_0 == 0)
            {
                for(i = 0; i < m; i++) matrix[i][0] = 0;
            }
        }
};