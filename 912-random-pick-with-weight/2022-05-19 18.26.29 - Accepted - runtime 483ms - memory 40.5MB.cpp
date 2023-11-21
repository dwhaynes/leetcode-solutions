class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        std::partial_sum(w.begin(),w.end(),back_inserter(prefixSums),plus<int>());
    }
    
    int pickIndex() {
        float randNum = (float) rand()/RAND_MAX;
        int target = prefixSums.back() * randNum;
        for(int i = 0; i < prefixSums.size(); i++)
            if(target < prefixSums[i]) return i;
        return prefixSums.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */