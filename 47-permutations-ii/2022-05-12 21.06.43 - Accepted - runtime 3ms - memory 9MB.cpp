class Solution {
    vector<vector<int>> res;
    map<int,int> ctr;
    void backtrack(vector<int>& comb, int N){
        if(comb.size() == N){
            res.push_back(comb);
            return;
        }
        for(auto [num,count]: ctr){
            if(count == 0) continue;
            comb.push_back(num);
            ctr[num]--;
            backtrack(comb,N);
            comb.pop_back();
            ctr[num]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        for(auto num: nums){
            ctr[num]++;
        }
        vector<int> comb;
        backtrack(comb,nums.size());
        return res;
    }
};