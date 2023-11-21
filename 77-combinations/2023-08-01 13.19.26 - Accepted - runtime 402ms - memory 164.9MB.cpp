class Solution {
    vector<vector<int>> ans;
    void permute(int start, int end, vector<int> combs, int k){
        if(k == 0){
            ans.push_back(combs);
            return;
        }
        for(int i = start; i <= end; i++){
            combs.push_back(i);
            permute(i+1,end, combs,k-1);
            combs.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= n; i++){
            permute(i+1,n,{i},k-1);
        }
        return ans;
    }
};