class Solution {
    vector<int> prefixSums;
    int sum = 0;
public:
    Solution(vector<int>& w) {
        for(int i = 0;i < w.size(); i++){
            sum+=w[i];
            prefixSums.push_back(sum);
        }
    }
    
    int pickIndex() {
        float randNum = (float) rand()/RAND_MAX;
        int target = sum * randNum;
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