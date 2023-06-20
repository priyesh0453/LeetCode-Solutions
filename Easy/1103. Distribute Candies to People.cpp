#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people, vector <int>& distribution);
void display(vector <int>& distribution, int num_people);

int main()
{
    int candies, num_people;
    cin >> candies >> num_people;
    
    vector <int> distribution(num_people);
    
    distributeCandies(candies, num_people, distribution);
    display(distribution, num_people);
    
    return 0;
}

vector<int> distributeCandies(int candies, int num_people, vector <int>& distribution) 
{
    int i = 0;

    for(; candies > 0; i++)
    {
        distribution[(i % num_people)] += min(candies, (i + 1));
        candies -= (i + 1);
    }    

    return distribution;
}

void display(vector <int>& distribution, int num_people)
{
    int i = 0;
    
    for(; i < num_people; i++)
    {
        cout << distribution[i] << " ";
    }
}