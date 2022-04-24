class UndergroundSystem {
public:
    unordered_map<string, pair<int,int>> costs;
    unordered_map<int,pair<string,int>> checkin;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        costs[checkin[id].first+"_"+stationName].first += t - checkin[id].second;
        costs[checkin[id].first+"_"+stationName].second++;
        checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)costs[startStation+"_"+endStation].first/(double)costs[startStation+"_"+endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */