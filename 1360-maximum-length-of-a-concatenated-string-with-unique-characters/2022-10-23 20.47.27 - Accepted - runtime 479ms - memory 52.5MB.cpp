class Solution {
    int dfs(vector<string>& arr, int pos, string res){
        unordered_set<char> resSet(res.begin(),res.end());
        if(res.size() != resSet.size()) return 0;
        int best = res.size();
        for(int i = pos; i < arr.size(); i++)
            best = max(best, dfs(arr,i+1, res + arr[i]));
        return best;
    }
public:
    int maxLength(vector<string>& arr) {
        return dfs(arr,0,"");
    }
};