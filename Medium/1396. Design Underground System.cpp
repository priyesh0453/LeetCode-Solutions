class UndergroundSystem 
{
    public:

    unordered_map <int, pair <string, int>> checkInMap;
    unordered_map <string, pair <int, int>> timeTaken;

    UndergroundSystem() 
    {}
    
    void checkIn(int id, string stationName, int t) 
    {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string path = checkInMap[id].first + "->" + stationName;
        timeTaken[path].first += t - checkInMap[id].second;
        timeTaken[path].second += 1; 

        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string path = startStation + "->" + endStation;
        
        return (double) timeTaken[path].first / timeTaken[path].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */