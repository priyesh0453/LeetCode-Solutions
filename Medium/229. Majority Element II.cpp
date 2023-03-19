#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

void majorityElement(int nums[], int n);

int main(void)
{
    int n, i = 0;
    cin >> n;
    
    int nums[n];
    
    for(; i < n; i++)
    {
        cin >> nums[i];
    }
    
    majorityElement(nums, n);

    return 0;
}

void majorityElement(int nums[], int n) 
{
    //Boyer Moore's Voting Algoithm : max of 2 majority elements
        
    int i = 0, major_1 = INT_MIN, major_2 = INT_MIN + 1, count_1 = 0, count_2 = 0;

    for(; i < n; i++)
    {
        if(major_1 == nums[i]) count_1++;
        else if(major_2 == nums[i]) count_2++;
        else if(count_1 == 0)
        {
            major_1 = nums[i];
            count_1++;
        }
        else if(count_2 == 0)
        {
            major_2 = nums[i];
            count_2++;
        }
        else 
        {
            count_1--;
            count_2--;
        }
    }

    /*
    vector <int> majorityElements;
    i = 0;
    count_1 = count_2 = 0;

    for(; i < n; i++)
    {
        if(nums[i] == major_1) count_1++;
        else if(nums[i] == major_2) count_2++;
    }

    if(count_1 > (n / 3)) majorityElements.push_back(major_1);
    if(count_2 > (n / 3)) majorityElements.push_back(major_2);

    return majorityElements;
    */
    int majorityElements_Array[2];
    memset(majorityElements_Array, INT_MIN, sizeof(majorityElements_Array));
    
    i = 0;
    count_1 = count_2 = 0;
    
    for(; i < n; i++)
    {
        if(nums[i] == major_1) count_1++;
        else if(nums[i] == major_2) count_2++;
    }
    
    if(count_1 > (n / 3)) majorityElements_Array[0] = major_1;
    
    if(count_2 > (n / 3))
    {
        majorityElements_Array[1] = major_2;
        cout << majorityElements_Array[0] << endl;
        cout << majorityElements_Array[1];
    }
    else cout << majorityElements_Array[0];
}