#include iostream
using namespace std;

int trap(int height[], int length);

int main()
{
    int length, i = 0;
    
    cin  length;
    
    int height[length];
    
    for(; i  length; i++)
    {
        cin  height[i];
    }
    
    cout  trap(height, length);

    return 0;
}

int trap(int height[], int length) 
{
    if(length == 1) return 0;

    int left_index = 0, right_index = (length - 1), left_max = height[left_index], right_max = height[right_index], area = 0;

    while(left_index  right_index)
    {
        if(left_max  right_max)
        {
            left_index++;
            left_max = max(left_max, height[left_index]);
            area += (left_max - height[left_index]);
        }
        else
        {   
            right_index--;
            right_max = max(right_max, height[right_index]);
            area += (right_max - height[right_index]);
        }
    }

    return area;
}