#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, int size, char target);

int main()
{
    int size, i = 0;
    char target;
    
    cin >> size >> target;
    
    vector <char> letters(size);
    
    for(; i < size; i++)
    {
        cin >> letters[i];
    }
    
    cout << nextGreatestLetter(letters, size, target);

    return 0;
}

char nextGreatestLetter(vector<char>& letters, int size, char target) 
{
    int left_Index = 0, right_Index = size, mid_Index;

    while(left_Index < right_Index)
    {
        mid_Index = left_Index + (right_Index - left_Index) / 2;

        if(letters[mid_Index] <= target) left_Index = mid_Index + 1;
        else right_Index = mid_Index;
    }

    return letters[left_Index % size];
}