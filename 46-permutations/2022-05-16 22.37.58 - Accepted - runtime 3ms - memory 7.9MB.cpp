class Solution {
    vector<vector<int>> res;
    void build(vector<int>& comb, vector<int>& nums, vector<bool>& used){
        if(comb.size() == nums.size()){
            res.push_back(comb);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                comb.push_back(nums[i]);
                used[i] = true;
                build(comb,nums,used);
                used[i] = false;
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> comb;
        vector<bool> used(nums.size(),false);
        build(comb,nums,used);
        return res;
    }
};