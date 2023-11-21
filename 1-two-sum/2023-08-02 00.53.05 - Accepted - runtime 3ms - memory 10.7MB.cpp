class Solution {
    unordered_map<int,int> cache;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            auto seen = cache.find(nums[i]);
            if(seen != cache.end()) return {seen->second,i};
            cache[target-nums[i]] = i;
        }
        return {};
    }
};