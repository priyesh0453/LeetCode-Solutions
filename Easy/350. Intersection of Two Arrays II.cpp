#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

void intersect(int nums1[], int length1, int nums2[], int length2);
void printArray(int nums[], int length);

int main(void)
{
    int length1, length2, i = 0;
    cin >> length1;
    cin >> length2;
    
    int nums1[length1], nums2[length2];
    
    for(; i < length1; i++)
    {
        cin >> nums1[i];
    }
    
    for(i = 0; i < length2; i++)
    {
        cin >> nums2[i];
    }
    
    intersect(nums1, length1, nums2, length2);

    return 0;
}

void intersect(int nums1[], int length1, int nums2[], int length2) 
{
    int i = 0, k = 0, intersections[(min(length2, length1))];
    unordered_map <int, int> freq;
    
    memset(intersections, 0, sizeof(intersections));
    
    for(; i < length1; i++) freq[nums1[i]]++;
        
    for(i = 0; i < length2; i++)
    {
        if(freq.find(nums2[i]) != freq.end() && --freq[nums2[i]] >= 0) intersections[k++] = nums2[i];
    }

    printArray(intersections, (min(length2, length1)));
}

void printArray(int nums[], int length)
{
    int i = 0;
    
    for(; i < length; i++)
    {
        if(nums[i] != 0) cout << nums[i] << " ";
    }
}