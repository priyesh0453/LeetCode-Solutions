#include <iostream>
#include <cmath>
using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest);

int main()
{
    int buckets, minutesToTest, minutesToDie;
    cin >> buckets >> minutesToTest >> minutesToDie;
    
    cout << poorPigs(buckets, minutesToDie, minutesToTest);

    return 0;
}

int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
{
    /*
        For 1 pig and t intervals -> (t + 1) buckets can be determined for required output.
        Therefore, for n pigs with t intervals -> (t + 1) ^ n buckets max can be determined.
        
        Also, log2 to be used because of binary used.
    */
    
    int noOfIntervals = (minutesToTest / minutesToDie), minNoOfPigs = ceil(log2(buckets) / log2(noOfIntervals + 1));

    return minNoOfPigs;
}