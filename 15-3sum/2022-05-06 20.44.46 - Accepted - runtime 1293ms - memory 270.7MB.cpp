class Solution {
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& out){
        unordered_set<int> seen;
        for(int j = i+1; j < nums.size(); j++){
            int complement = -nums[i] - nums[j];
            if(seen.count(complement)){
                out.push_back({nums[i],complement,nums[j]});
                while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
            seen.insert(nums[j]);
        }

    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i] != nums[i-1]) twoSum(nums,i,out);
        }
        return out;
    }
};