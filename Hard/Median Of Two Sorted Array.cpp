#include <iostream>
#include <climits>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2, int m, int n) {

    if(m < 0 || m > 1000 || n < 0 || n > 1000)
    {
        return NULL;
    }
    else
    {
       if(m > n)
       {
           return findMedianSortedArrays(nums2, nums1, n, m);
       }
       else
       {
           int mid_Index = (m + n) / 2, left_Index = 0, right_Index = m, left_nums1, left_nums2, right_nums1, right_nums2, max_Selected_nums1, max_Selected_nums2;

            while(left_Index <= right_Index)
           {
               max_Selected_nums1 = (left_Index + right_Index) / 2;
               max_Selected_nums2 = (m + n + 1) / 2 - max_Selected_nums1;

               left_nums1 = (max_Selected_nums1 == 0) ? INT_MIN : nums1[(max_Selected_nums1 - 1)];
               left_nums2 = (max_Selected_nums2 == 0) ? INT_MIN : nums2[(max_Selected_nums2 - 1)];
               right_nums1 = (max_Selected_nums1 == m) ? INT_MAX : nums1[(max_Selected_nums1)];
               right_nums2 = (max_Selected_nums2 == n) ? INT_MAX : nums2[(max_Selected_nums2)];

               if((left_nums1 <= right_nums2) && (left_nums2 <= right_nums1))
               {
                   if((m + n) % 2 == 0)
                   {
                       return ((max(left_nums1, left_nums2) + min(right_nums1, right_nums2)) / 2.0);
                   }
                   else
                   {
                       return (max(left_nums1, left_nums2) * 1.0);
                   }
               }
               else if(left_nums1 > right_nums2)
               {
                   right_Index = max_Selected_nums1 - 1;
               }
               else
               {
                   left_Index = max_Selected_nums1 + 1;
               }
           }
       }
    }
    
    return 0.0;
}

int main()
{
    vector <int> nums1, nums2;
    int i = 0, var, m, n;
    
    cin >> m;
    cin >> n;
    
    for(; i < m; i++)
    {
        cin >> var;
        nums1.push_back(var);
    }
    for(i = 0; i < n; i++)
    {
        cin >> var;
        nums2.push_back(var);
    }
    
    cout << findMedianSortedArrays(nums1, nums2, m, n);

    return 0;
}