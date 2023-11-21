class TimeMap {
    map<string,map<int,string>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";
        auto it = store[key].upper_bound(timestamp);
        if(it == store[key].begin()) return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */