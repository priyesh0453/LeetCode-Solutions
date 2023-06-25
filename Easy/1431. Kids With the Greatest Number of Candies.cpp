#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int n, int extraCandies, vector <bool>& output) ;
void display(vector <bool> output, int n);

int main()
{
    int n, extraCandies, i = 0;
    cin >> n >> extraCandies;
    
    
    vector <int> candies(n);
    vector <bool> output(n);
    
    for(; i < n; i++)
    {
        cin >> candies[i];
    }
    
    
    kidsWithCandies(candies, n, extraCandies, output);
    display(output, n);
    
    return 0;
}

vector<bool> kidsWithCandies(vector<int>& candies, int n, int extraCandies, vector <bool>& output) 
{
    int i = 1, maxCandies = candies[0];

    for(; i < n; i++)
    {
        maxCandies = max(maxCandies, candies[i]);
    }    

    for(i = 0; i < n; i++)
    {
        if((candies[i] + extraCandies) >= maxCandies) output[i] = true;
        else output[i] = false; 
    }

    return output;
}

void display(vector <bool> output, int n)
{
    int i = 0;
    
    for(; i < n; i++)
    {
        cout << output[i] << " ";
    }
}