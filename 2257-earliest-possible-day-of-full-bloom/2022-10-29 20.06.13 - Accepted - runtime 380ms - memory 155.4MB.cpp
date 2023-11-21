class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> ind(plantTime.size());
        iota(ind.begin(),ind.end(),0);
        sort(ind.begin(),ind.end(),[&](int i, int j){ return growTime[i] > growTime[j];});
        int curr = 0, last = 0;
        for(auto i: ind){
            curr += plantTime[i];
            last = max(last,curr+growTime[i]);
        }
        return last;
    }
};