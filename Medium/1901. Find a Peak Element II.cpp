class Solution 
{
    private:
    int maxColIndex(vector <int> arr, int noOfCol)
    {
        int i = 0, index = 0;

        for(; i < noOfCol; i++)
        {
            if(arr[i] > arr[index]) index = i;
        }

        return index;
    }
    
    public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int noOfRows = mat.size() - 1, start_Index = 0, end_Index = noOfRows, mid_Index, noOfCol = mat[0].size(), row_Max_Index;

        while(start_Index <= end_Index)
        {
            mid_Index = start_Index + (end_Index - start_Index) / 2;
            row_Max_Index = maxColIndex(mat[mid_Index], noOfCol);

            if(mid_Index == 0)
            {
                if(mat[mid_Index][row_Max_Index] > mat[(mid_Index + 1)][row_Max_Index]) return {mid_Index, row_Max_Index};
            }
            else if(mid_Index == noOfRows)
            {
                if(mat[mid_Index][row_Max_Index] > mat[(mid_Index - 1)][row_Max_Index]) return {mid_Index, row_Max_Index};
            }

            if(mat[mid_Index][row_Max_Index] > mat[mid_Index + 1][row_Max_Index] && mat[mid_Index][row_Max_Index] > mat[mid_Index - 1][row_Max_Index]) return {mid_Index, row_Max_Index};

            if(mat[mid_Index][row_Max_Index] < mat[mid_Index + 1][row_Max_Index]) start_Index = mid_Index + 1;
            else end_Index = mid_Index - 1;
        }   

        return {-1, -1};
    }
};