#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jobScheduling(vector <int>& startTime, vector <int>& endTime, vector <int>& profit, int noOfJobs);

int main() 
{
    int noOfJobs;
    cin >> noOfJobs;

    vector <int> startTime(noOfJobs), endTime(noOfJobs), profit(noOfJobs);

    for (int& time : startTime) 
    {
        cin >> time;
    }
    
    for (int& time : endTime) 
    {
        cin >> time;
    }

    for (int& p : profit) 
    {
        cin >> p;
    }

    cout << jobScheduling(startTime, endTime, profit, noOfJobs) << endl;

    return 0;
}

int jobScheduling(vector <int>& startTime, vector <int>& endTime, vector <int>& profit, int noOfJobs) 
{
    int i = 0, left, right, mid;
    vector <vector <int>> jobs;
    vector<int> dp(noOfJobs);

    for(; i < noOfJobs; i++) 
    {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());

    dp[0] = jobs[0][2];

    for(i = 1; i < noOfJobs; i++) 
    {
        int take = jobs[i][2];
        left = 0, right = i - 1;
        
        while (left <= right) 
        {
            mid = left + (right - left) / 2;
            
            if(jobs[mid][0] <= jobs[i][1]) 
            {
                take = max(take, jobs[i][2] + dp[mid]);
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], take);
    }

    return dp[noOfJobs - 1];
}