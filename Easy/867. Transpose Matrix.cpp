class Solution 
{
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) 
        {
            int m = matrix.size(), n = matrix[0].size(), i = 0, j;
            vector <vector <int>> transposeMatrix(n, vector <int> (m));
    
            for(; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    transposeMatrix[j][i] = matrix[i][j];
                }
            }
    
            return transposeMatrix;
        }
};