class UndergroundSystem {
    map<int,pair<string,int>> log;
    map<pair<string,string>,vector<int>> times;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        log[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = log[id];
        log.erase(id);
        times[{p.first,stationName}].push_back(t-p.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto temp = times[{startStation,endStation}];
        double avg = double(accumulate(temp.begin(),temp.end(),0));
        return avg/temp.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */