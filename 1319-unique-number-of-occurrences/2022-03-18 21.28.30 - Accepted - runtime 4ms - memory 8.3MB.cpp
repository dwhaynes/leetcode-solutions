class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> hist;
        set<int> seen;
        for(auto num: arr) hist[num]++;
        for(auto [k,v]: hist){
            if(seen.count(v)) return false;
            seen.insert(v);
        }
        return true;
    }
};