class Solution {
    vector<vector<int>> res;
    vector<int> comb;
    void backtrack(int target, int k, int start){
        if(target == 0 && k == 0) res.push_back(comb);
        else if(target < 0 || k == 0 || start > 9) return;
        for(int i = start; i <= 9; i++){
            comb.push_back(i);
            backtrack(target-i,k-1,i+1);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n,k,1);
        return res;
    }
};