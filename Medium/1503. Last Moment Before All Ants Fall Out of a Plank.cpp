#include <iostream>
#include <vector>
using namespace std;

int getLastMoment(int n, vector <int>& left, vector <int>& right, int noOfLeftMoving, int noOfRightMoving);

int main()
{
    int n, noOfLeftMoving, noOfRightMoving, i;
    cin >> n >> noOfLeftMoving >> noOfRightMoving;
    
    vector <int> left(noOfLeftMoving), right(noOfRightMoving);
    
    for(i = 0; i < noOfLeftMoving; i++)
    {
        cin >> left[i];
    }
    
    for(i = 0; i < noOfRightMoving; i++)
    {
        cin >> right[i];
    }
    
    cout << getLastMoment(n, left, right, noOfLeftMoving, noOfRightMoving);

    return 0;
}

int getLastMoment(int n, vector <int>& left, vector <int>& right, int noOfLeftMoving, int noOfRightMoving)
{
    //Treat each ant unlabeled. Only distance moved matters!
    
    int lastMoment = 0, i = 0;

    for(; i < noOfLeftMoving; i++) lastMoment = max(lastMoment, left[i]);
    for(i = 0; i < noOfRightMoving; i++) lastMoment = max(lastMoment, n - right[i]);

    return lastMoment;
}