#include <iostream>
#include <vector>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates, int noOfPoints);

int main()
{
    int noOfPoints, i = 0, j;
    cin >> noOfPoints;
    
    vector <vector <int>> coordinates(noOfPoints, vector <int> (2));
    
    for(; i < noOfPoints; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> coordinates[i][j];   
        }
    }
    
    cout << checkStraightLine(coordinates, (noOfPoints - 1));

    return 0;
}

bool checkStraightLine(vector<vector<int>>& coordinates, int noOfPoints) 
{
    if(noOfPoints == 1) return true;
     
    int i = 1;
    
    if(coordinates[1][0] != coordinates[0][0])
    {
        float slope = (float) (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

        for(; i < noOfPoints; i++)
        {
            if((float) (coordinates[(i + 1)][1] - coordinates[i][1]) / (coordinates[(i + 1)][0] - coordinates[i][0]) != slope) return false;
        }
    }
    else
    {
        for(i = 2; i <= noOfPoints; i++)
        {
            if(coordinates[i][0] != coordinates[0][0]) return false;
        }
    }
    
    return true;
}