class Solution 
{
    private:
    long int calcTimeReq(vector <int> piles, int mid, int n)
    {
        long int totalTime = 0, i = 0;

        for(; i < n; i++)
        {
            totalTime += (piles[i] + mid - 1) / mid;   
        }

        return totalTime;
    }    
    
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid, minSpeed, n = piles.size();
        long int timeReq;

        while(low <= high)
        {
            mid = low + (high - low) / 2;
            timeReq = calcTimeReq(piles, mid, n);
            
            if(timeReq <= h)
            {
                minSpeed = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }   

        return minSpeed;
    }
};