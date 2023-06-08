class Solution 
{
    private:
    int checkNegIndex(vector <int>& gridRow, int n)
    {
        int left_Index = 0, right_Index = n - 1, index = -1, mid_Index;

        while(left_Index <= right_Index)
        {
            mid_Index = left_Index + (right_Index - left_Index) / 2;

            if(gridRow[mid_Index] < 0)
            {
                index = mid_Index;
                right_Index = mid_Index - 1;
            }
            else left_Index = mid_Index + 1;
        } 

        return index;
    }

    public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size(), countNeg = 0, i = 0, temp;

        for(; i < m; i++)
        {
            temp = checkNegIndex(grid[i], n);

            if(temp != -1) countNeg += (n - temp);
        }

        return countNeg;
    }
};