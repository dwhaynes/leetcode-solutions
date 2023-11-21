class Solution {
    void backtrack(int remain, int k, vector<int>& comb, int start, vector<vector<int>>& res){
        if(remain == 0 && comb.size() == k){
            res.push_back(comb);
            return;
        }else if (remain < 0 || comb.size() == k) return;
        
        for(int i = start; i < 9; i++){
            comb.push_back(i+1);
            backtrack(remain-i-1,k,comb,i+1,res);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(n,k,comb,0,res);
        return res;
    }
};