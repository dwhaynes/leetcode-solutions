class TwoSum {
    map<long,int> map;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        map[number]++;
    }
    
    bool find(int value) {
        for(auto kv: map){
            long complement = value - kv.first;
            if(complement != kv.first){
                if(map.find(complement) != map.end()) return true;
            }else{
                if(kv.second > 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */