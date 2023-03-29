class Solution {
public:
    vector <vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        vector <vector <int>> outputMatrix(r, vector <int> (c));
        int i = 0, j = 0, k = 0, l = 0, noOfRows = mat.size(), noOfColumns = mat[i].size();

        if((noOfRows * noOfColumns) != (r * c)) return mat;
        
        for(; i < noOfRows; i++)
        {
            for(j = 0; j < noOfColumns; j++)
            {
                k = (i * noOfColumns) + j;
                outputMatrix[k / c][k % c] = mat[i][j];
            }
        }   

        return outputMatrix; 
    }
};