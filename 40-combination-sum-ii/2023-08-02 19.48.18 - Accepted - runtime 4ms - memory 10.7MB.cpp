class Solution {
    set<vector<int>> results;
    vector<int> current;
    void search(vector<int>& nums, int target, int sum, int start){
        if(sum == target){
            results.insert(current);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(nums[i]+sum > target) return;
            if(i > start && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            search(nums,target,sum+nums[i],i+1);
            // current.erase(current.end()-1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        search(candidates,target,0,0);
        return vector<vector<int>>(results.begin(),results.end());
    }
};