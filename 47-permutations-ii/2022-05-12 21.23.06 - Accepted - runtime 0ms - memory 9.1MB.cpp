class Solution {
    vector<vector<int>> res;
    map<int,int> ctr;
    int sz;
    void backtrack(vector<int>& comb){
        if(comb.size() == sz){
            res.push_back(comb);
            return;
        }
        for(auto [num,cnt]: ctr){
            if(cnt == 0) continue;
            ctr[num]--;
            comb.push_back(num);
            backtrack(comb);
            comb.pop_back();
            ctr[num]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sz = nums.size();
        vector<int> comb;
        for(auto num:nums) ctr[num]++;
        backtrack(comb);
        return res;
    }
};