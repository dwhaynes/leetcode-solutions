class Solution {
    vector<vector<int>> ans;
    vector<int> combs;
    void backtrack(int n, int k, int pos, int curr){
        if(pos == k){
            ans.push_back(combs);
            return;
        }
        for(int i = curr; i <= n-k+pos+1; i++){
            combs[pos] = i;
            backtrack(n,k,pos+1,i+1);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        combs = vector<int>(k);
        backtrack(n, k, 0, 1);
        return ans;
    }
};