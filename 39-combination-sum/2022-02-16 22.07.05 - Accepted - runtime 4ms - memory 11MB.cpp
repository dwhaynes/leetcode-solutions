class Solution {
    vector<vector<int>> results;
    void search(vector<int>& candidates, int target, int start, vector<int>& path){
        if(target < 0) return;
        if(target == 0){
            results.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            int c = candidates[i];
            path.push_back(c);
            search(candidates, target-c, i, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        search(candidates, target, 0, path);
        return results;
    }
};