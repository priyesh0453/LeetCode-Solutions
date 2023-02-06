#include <iostream>
#include <vector>
using namespace std;

void shuffle(int nums[], int n);

int main()
{
    int n, i = 0;
    cin >> n;
    
    int counter = (2 * n), nums[counter];
    
    for(; i < counter; i++)
    {
        cin >> nums[i];
    }
    
    shuffle(nums, n);

    return 0;
}

void shuffle(int nums[], int n) 
{
    if(n == 1) cout << nums[0] << "," << nums[1];

    vector <int> shuffledArray((2 * n));
    int i = 0, counter = (2 * n), x_index = 0, y_index = n;

    for(; i < counter; i += 2)
    {
        shuffledArray[i] = nums[x_index++];
        shuffledArray[(i + 1)] = nums[y_index++];
    }

    for(i = 0; i < counter; i++)
    {
        cout << shuffledArray[i] << " ";
    }
}