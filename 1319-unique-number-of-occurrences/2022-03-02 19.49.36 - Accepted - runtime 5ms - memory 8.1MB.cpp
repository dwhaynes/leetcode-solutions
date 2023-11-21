class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> hist;
        set<int> seen;
        for(auto num: arr) hist[num]++;
        for(auto kv: hist){
            if(seen.find(kv.second) != seen.end()) return false;
            seen.insert(kv.second);
        }
        return true;
    }
};