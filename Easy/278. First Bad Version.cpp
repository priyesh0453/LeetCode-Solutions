// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int left_Index = 0, right_Index = n, mid_Index;

        while(left_Index < right_Index)
        {   
            mid_Index = left_Index + (-left_Index + right_Index) / 2;
            
            if(isBadVersion(mid_Index) == 0) left_Index = mid_Index + 1;
            else right_Index = mid_Index;
        }

        return left_Index;
    }
};